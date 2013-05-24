/*
CuteTorrent BitTorrent Client with dht support, userfriendly interface
and some additional features which make it more convenient.
Copyright (C) 2012 Ruslan Fedoseyenko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "SettingsDialog.h"

#include <QFileDialog>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include "TorrentManager.h"
#include <QDebug>
#include <QTranslator>
#include <QIntValidator>
#include "application.h"
#include "Scheduller.h"

#ifdef Q_WS_WIN //file association for windows
#include <windows.h>
#include <tchar.h>

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
		GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

	if(NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}

#endif
SettingsDialog::SettingsDialog(QWidget* parrent,int flags)
{
	setupUi(this);
	previousFocuse=NULL;
	settings = QApplicationSettings::getInstance();
	FillDTTab();
	FillFilteringGroups();
	FillTorrentTab();
	FillHDDTab();
	SetupSchedullerTab();
	////////////OS_SPECIFICK//////////////////////////
#ifdef Q_WS_WIN
	QSettings assocSettings ("HKEY_CLASSES_ROOT", QSettings::NativeFormat);                                                                                   
	QString torrentAssociation=assocSettings.value (".torrent/.").toString();  
	magnetAssociationCheckBox->setChecked(assocSettings.value ("Magnet/shell/open/command/.").toString().toLower().contains("cutetorrent"));
	asociationCheckBox->setChecked( torrentAssociation == "CuteTorrent.file");
	QSettings bootUpSettings(QString("HKEY_LOCAL_MACHINE\\SOFTWARE\\")+(IsWow64() ? "Wow6432Node\\" : "")+"Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	QString val=bootUpSettings.value("CuteTorrent").toString();
	int current=0;
	runOnbootCheckBox->setChecked(val.length()>0);	
	startMinimizedCheckBox->setChecked(val.contains("-m"));
#endif
	////////////OS_SPECIFICK//////////////////////////
	QString curLoc=Application::currentLocale().split('_')[1];
	foreach (QString avail, Application::availableLanguages())
	{
		QString loc=avail.split('_')[1];

		localeComboBox->addItem(loc);

		if (loc==curLoc)
			localeComboBox->setCurrentIndex(current);
		current++;

	}
	
	
	tabWidget->removeTab(5);
}


void SettingsDialog::FillHDDTab()
{
	lockFilesCheckBox->setCheckState(settings->valueBool("Torrent","lock_files") ?  Qt::Checked :Qt::Unchecked );
	casheSizeLineEdit->setValue(settings->valueInt("Torrent","cache_size")*16);
	diskIOCasheModeComboBox->setCurrentIndex(settings->valueInt("Torrent","disk_io_write_mode"));
	useDiskReadAheadCheckBox->setCheckState(settings->valueBool("Torrent","use_disk_read_ahead") ?  Qt::Checked :Qt::Unchecked );
	alowReorderedOpsCheckBox->setCheckState(settings->valueBool("Torrent","allow_reordered_disk_operations") ?  Qt::Checked :Qt::Unchecked );
	lowPrioDiskCheckBox->setCheckState(settings->valueBool("Torrent","low_prio_disk") ?  Qt::Checked :Qt::Unchecked );
	useReadCasheCheckBox->setCheckState(settings->valueBool("Torrent","use_read_cache") ?  Qt::Checked :Qt::Unchecked );
}

void SettingsDialog::FillTorrentTab()
{
	portEdit->setText(settings->valueString("Torrent","listen_port"));
	portEdit->setValidator(new QIntValidator());
	uploadLimitEdit->setValue(settings->valueInt("Torrent","upload_rate_limit")/1024.0);
	downloadLimitEdit->setValue(settings->valueInt("Torrent","download_rate_limit")/1024.0);
	activeLimitEdit->setText(settings->valueString("Torrent","active_limit"));
	activeLimitEdit->setValidator(new QIntValidator());
	activeSeedLimitEdit->setText(settings->valueString("Torrent","active_seeds"));
	activeSeedLimitEdit->setValidator(new QIntValidator());
	activeDownloadLimitEdit->setText(settings->valueString("Torrent","active_downloads"));
	activeDownloadLimitEdit->setValidator(new QIntValidator());
	bool useProxy=settings->valueBool("Torrent","useProxy");
	proxyGroupBox->setChecked(useProxy);
	if (useProxy)
	{
		proxyHostEdit->setText(QString("%1:%2").arg(settings->valueString("Torrent",
			"proxy_hostname").arg(settings->valueString("Torrent","proxy_port"))));
		proxyUsernameEdit->setText(settings->valueString("Torrent","proxy_username"));
		proxyPwdEdit->setText(settings->valueString("Torrent","proxy_password"));
	}
}

void SettingsDialog::FillFilteringGroups()
{
	filterGroups = settings->GetFileFilterGroups();
	for (int i=0;i<filterGroups.count();i++)
	{
		GroupsListWidget->addItem(filterGroups.at(i).Name());
	}
	GroupsListWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
}

void SettingsDialog::FillDTTab()
{
	DTPathEdit->setText(settings->valueString("DT","Executable"));
	int driveNumber=settings->valueInt("DT","Drive");
	driveNumberComboBox->setCurrentIndex(driveNumber < driveNumberComboBox->count() ? driveNumber : 0);
	settings->setValue("DT","DefaultCommand","-mount dt,%1,\"%2\"");
	bool useCustomCommand=settings->valueBool("DT","UseCustomCommand");
	customMoutGroupBox->setChecked(useCustomCommand);
	customCommandEdit->setText( (useCustomCommand ? settings->valueString("DT","CustomtCommand") : settings->valueString("DT","DefaultCommand")));
}

void SettingsDialog::FillWebUITab()
{
	webUIGroupBox->setChecked(settings->valueBool("WebControl","webui_enabled",false));
	loginLineEdit->setText(settings->valueString("WebControl","webui_login"));
	passwordLineEdit->setText(settings->valueString("WebControl","webui_password"));
	webPortLineEdit->setText(settings->valueString("WebControl","web_port","8080"));
	rconPortLineEdit->setText(settings->valueString("WebControl","rcon_port","18745"));
	upnpCheckBox->setChecked(settings->valueBool("WebControl","enable_upnp",false));
	webUILogginGroupBox->setChecked(settings->valueBool("WebControl","enable_loggin",false));
	logLineEdit->setText(settings->valueString("WebControl","log_name"));
	IPFilterGroupBox->setChecked(settings->valueBool("WebControl","enable_ipfilter",false));
	ipFilterTextEdit->setText(settings->valueString("WebControl","ipfilter"));
}

void SettingsDialog::showSelectedGroup(int row)
{
	if (row > filterGroups.count())
	{	
		return;
	}
	if (row <0)
		return;
	newGroupNameEdit->setText(filterGroups.at(row).Name());
	extensionsEdit->setText(filterGroups.at(row).Extensions());
	groupSavePathEdit->setText(filterGroups.at(row).SavePath());
	
}
SettingsDialog::~SettingsDialog() 
{
	
	QApplicationSettings::FreeInstance();
}
void SettingsDialog::ApplySettings()
{
	settings->setValue("Torrent","listen_port",					qVariantFromValue(portEdit->text().toInt()));
	settings->setValue("Torrent","active_limit",				qVariantFromValue(activeLimitEdit->text().toInt()));
	settings->setValue("Torrent","active_downloads",			qVariantFromValue(activeDownloadLimitEdit->text().toInt()));
	settings->setValue("Torrent","active_seeds",				qVariantFromValue(activeSeedLimitEdit->text().toInt()));


	settings->setValue("Torrent","upload_rate_limit",			qVariantFromValue(uploadLimitEdit->value()*1024));
	settings->setValue("Torrent","download_rate_limit",			qVariantFromValue(downloadLimitEdit->value()*1024));
	settings->setValue("Torrent","useProxy",					qVariantFromValue(proxyGroupBox->isChecked()));
	if (proxyGroupBox->isChecked())
	{
		QStringList iport= proxyHostEdit->text().split(':');
		if (iport.count()==2)
		{
			settings->setValue("Torrent","proxy_hostname",		qVariantFromValue(iport.at(0)));
			settings->setValue("Torrent","proxy_password",		qVariantFromValue(proxyPwdEdit->text()));
			settings->setValue("Torrent","proxy_port",			qVariantFromValue(iport[1]));
			settings->setValue("Torrent","proxy_type",			qVariantFromValue(proxyTypeComboBox->currentIndex()));
			settings->setValue("Torrent","proxy_username",		qVariantFromValue(proxyUsernameEdit->text()));
		}
		
	}
	
	settings->setValue("Torrent","lock_files",					lockFilesCheckBox->isChecked());
	settings->setValue("Torrent","cache_size",					casheSizeLineEdit->value() /16 );
	settings->setValue("Torrent","disk_io_read_mode",			diskIOCasheModeComboBox->currentIndex());
	settings->setValue("Torrent","disk_io_write_mode",			diskIOCasheModeComboBox->currentIndex());
	settings->setValue("Torrent","low_prio_disk",				lowPrioDiskCheckBox->isChecked() );
	settings->setValue("Torrent","allow_reordered_disk_operations",alowReorderedOpsCheckBox->isChecked() );
	settings->setValue("Torrent","use_read_cache",				useReadCasheCheckBox->isChecked() );

	ApplySettingsToSession();

	settings->setValue("DT","Executable",						DTPathEdit->text());
	settings->setValue("DT","Drive",							driveNumberComboBox->currentIndex());
	settings->setValue("DT","DefaultCommand",					"-mount dt,%1,\"%2\"");
	settings->setValue("DT","UseCustomCommand",					(customMoutGroupBox->isChecked()));
	settings->setValue("DT","CustomtCommand",					customCommandEdit->text());

	settings->setValue("WebControl","webui_enabled",			webUIGroupBox->isChecked());
	settings->setValue("WebControl","webui_login",				loginLineEdit->text());
	settings->setValue("WebControl","webui_password",			passwordLineEdit->text());
	settings->setValue("WebControl","web_port",					webPortLineEdit->text());
	settings->setValue("WebControl","rcon_port",				rconPortLineEdit->text());
	settings->setValue("WebControl","enable_upnp",				upnpCheckBox->isChecked());
	settings->setValue("WebControl","enable_loggin",			webUILogginGroupBox->isChecked());
	settings->setValue("WebControl","log_name",					logLineEdit->text());
	settings->setValue("WebControl","enable_ipfilter",			IPFilterGroupBox->isChecked());
	settings->setValue("WebControl","ipfilter",					ipFilterTextEdit->toPlainText());

	settings->SaveFilterGropups(filterGroups);
#ifdef Q_WS_WIN //file association for windows
	QSettings asocSettings ("HKEY_CLASSES_ROOT", QSettings::NativeFormat);   
	QString base_dir=QDir::toNativeSeparators(settings->valueString("System","BaseDir"))+QDir::separator()+"CuteTorrent.exe";
	if (base_dir.isEmpty())
	{
		base_dir=QDir::toNativeSeparators(QApplication::applicationFilePath());
	}
	if (asociationCheckBox->checkState()==Qt::Checked)
	{
		

		asocSettings.setValue (".torrent/.", "CuteTorrent.file");                                                      
		asocSettings.setValue ("CuteTorrent.file/.", tr("Torrent file"));
		
		asocSettings.setValue ("CuteTorrent.file/shell/open/command/.",
			"\"" + QDir::toNativeSeparators (base_dir) + "\"" + " \"%1\"");

		
	}
	else
	{
			asocSettings.remove(".torrent/.");
			asocSettings.remove("CuteTorrent.file/.");
			asocSettings.remove("CuteTorrent.file/shell/open/command/.");
	}
	if (magnetAssociationCheckBox->isChecked())
	{
		asocSettings.setValue ("Magnet/.", "Magnet URI");                                                      
		asocSettings.setValue ("Magnet/Content Type", "application/x-magnet");
		asocSettings.setValue ("Magnet/URL Protocol", "");
		asocSettings.setValue ("Magnet/shell/open/command/.",
			"\"" + QDir::toNativeSeparators (base_dir) + "\"" + " \"%1\"");
	} 
	else
	{
		asocSettings.remove ("Magnet/.");                                                      
		asocSettings.remove ("Magnet/Content Type");
		asocSettings.remove ("Magnet/URL Protocol");
		asocSettings.remove ("Magnet/shell/open/command/.");
	}
	QSettings bootUpSettings(QString("HKEY_LOCAL_MACHINE\\SOFTWARE\\")+(IsWow64() ? "Wow6432Node\\" : "")+"Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	
	if (runOnbootCheckBox->checkState()==Qt::Checked)
	{
		bootUpSettings.setValue("CuteTorrent","\""+base_dir+"\""+ (startMinimizedCheckBox->isChecked() ? " -m" : ""));
	}
	else
		bootUpSettings.remove("CuteTorrent");
#endif
	int curLocaleIndex=localeComboBox->currentIndex();
	Application::setLanguage("cutetorrent_"+localeComboBox->currentText().toUpper());
	settings->setValue("System","Lang",localeComboBox->currentText().toUpper());
	retranslateUi(this);
	calendarWidget->setLocale(localeComboBox->currentIndex()==0 ? QLocale(QLocale::English) : QLocale(QLocale::Russian));
}
void SettingsDialog::ApplySettingsToSession()
{
	
	TorrentManager* manager = TorrentManager::getInstance();
	
	libtorrent::session_settings current= manager->readSettings();
	current.active_limit		= activeLimitEdit->text().toInt();
	current.active_downloads	= activeDownloadLimitEdit->text().toInt();
	current.active_seeds		= activeSeedLimitEdit->text().toInt();
	
	current.cache_size			= casheSizeLineEdit->value() /16 ;
	current.use_read_cache		= useReadCasheCheckBox->isChecked();
	current.lock_files			= lockFilesCheckBox->isChecked();
	current.disk_io_write_mode  = diskIOCasheModeComboBox->currentIndex();
	current.disk_io_read_mode   = diskIOCasheModeComboBox->currentIndex();
	current.low_prio_disk		= lowPrioDiskCheckBox->isChecked();

	current.allow_reordered_disk_operations = alowReorderedOpsCheckBox->isChecked();

	current.upload_rate_limit	= uploadLimitEdit->value()*1024;
	
	current.download_rate_limit = downloadLimitEdit->value()*1024;
	
	manager->updateSettings(current);
	
	manager->freeInstance();

}
void SettingsDialog::addGroup()
{
	
	int foundRow=-1;
	QString name=newGroupNameEdit->text();
	if (name.isEmpty())
	{
		QMessageBox::warning(this,tr("STR_SETTINGS"),
			tr("ERROR_GROUP_NAME_NOT_SET"));
		return;
	}
	QString extensions=extensionsEdit->toPlainText();
	if (extensions.isEmpty())
	{
		QMessageBox::warning(this,tr("STR_SETTINGS"),
			tr("ERROR_NO_EXTENSIONS"));
		return;
	}
	QString dir=groupSavePathEdit->text();
	if (dir.isEmpty())
	{
		QMessageBox::warning(this,tr("STR_SETTINGS"),
			tr("ERROR_NO_PATH"));
		return;
	}
	if (!QDir(dir).exists())
	{
		QMessageBox::warning(this,tr("STR_SETTINGS"),
			tr("ERROR_PATH_NOT_EXISTS"));
		return;
	}
	
	for (int i=0;i<filterGroups.count();i++)
	{
		
		if (filterGroups.at(i).Name()==name)
		{
			foundRow=i;
			break;
		}
	}
	if (foundRow >= 0)
	{
		if (QMessageBox::No==QMessageBox::warning(this,tr("STR_SETTINGS"),
			tr("SHURE_IN_CHANGING_GROUP %1").arg(name),
			QMessageBox::No | QMessageBox::Yes))
		return;
	}
	else
	{
		GroupsListWidget->addItem(name);
	}
	GroupForFileFiltering newfilterGroup = GroupForFileFiltering(name,extensions,dir);
	foundRow > 0 ? filterGroups.replace(foundRow,newfilterGroup) : filterGroups.append(newfilterGroup);

}
void SettingsDialog::removeGroup()
{
	QListWidgetItem* index=GroupsListWidget->selectedItems().first();
	QString name=index->text();
	int foundRow=-1;
	for (int i=0;i<filterGroups.count();i++)
	{
		
		if (filterGroups.at(i).Name()==name)
		{
			foundRow=i;
			break;
		}
	}
	if (foundRow >= 0)
	{
		newGroupNameEdit->setText("");
		extensionsEdit->setText("");
		groupSavePathEdit->setText("");
		filterGroups.removeAt(foundRow);
		delete index;
	}
	else
	{
		QMessageBox::warning(this,"Error",QString(tr("Unable to find %1")).arg(name));
	}
	
}
void SettingsDialog::browseSavepathGroup()
{
	QString lastDir=settings->valueString("System","LastSaveTorrentDir");
	
	QString savaPathForCurrentGroup = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		lastDir,
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	savaPathForCurrentGroup.append("\\");
	groupSavePathEdit->setText(QDir::toNativeSeparators(savaPathForCurrentGroup));
}
void SettingsDialog::browseDTPath()
{
	QString lastDir=settings->valueString("System","LastSaveTorrentDir");
	QString DTPath = QFileDialog::getOpenFileName(this,
		tr("WHERE_DT"), lastDir , tr("DaemonTools Lite (DTLite.exe);;DaemonTools PRO (DTAgent.exe);;Any File (*.*)"));
	
	DTPathEdit->setText(QDir::toNativeSeparators(DTPath));
}

void SettingsDialog::ApplyAndClose()
{
	ApplySettings();
	close();
}

void SettingsDialog::SetDate(QDate date)
{
//	QPair<QDateTime,QDateTime> interval=calendarWidget->getSelectedInterval();
	
	beginDateTimeEdit->setDate(date);
	
}

void SettingsDialog::DeleteTask()
{
	int index=tasksComboBox->currentIndex();
	SchedulerTask currentTask=tasksComboBox->itemData(index).value<SchedulerTask>();
	tasksComboBox->removeItem(index);
	tasks.removeAt (index);
	settings->SaveSchedullerQueue(tasks);
}

void SettingsDialog::AddTask()
{
	
	SchedulerTask::TaskType type=SchedulerTask::UNKNOWN;
	int limit=-1;
	QString name=taskNameLineEdit->text();
	QVariant limitVal;
	if (pauseAllRadioButton->isChecked())
	{
		type=SchedulerTask::PAUSE_ALL;
	}
	else if(startAllRadioButton->isChecked())
	{
		type=SchedulerTask::START_ALL;
	}
	else if(limitDlRadioButton->isChecked())
	{
		type=SchedulerTask::LIMIT_DOWNLOAD;
		limit=dlLimitEdit->text().toInt();
	}
	else if(limitUlRadioButton->isChecked())
	{
		type=SchedulerTask::LIMIT_UPLOAD;
		limit=ulLimitEdit->text().toInt();
	}
	if (limit >0)
	{
		limitVal=qVariantFromValue(limit);
	}
	if (SchedulerTask::UNKNOWN==type)
	{
		QMessageBox::warning(this,tr("ERROR_SRT"),tr("SCHEDULLER_UNKNOWN_TYPE"));
		return;
	}
	if (name.length()==0)
	{
		QMessageBox::warning(this,tr("ERROR_SRT"),tr("SCHEDULLER_NO_NAME"));
		return;
	}
	SchedulerTask newTask(name,type,limitVal,beginDateTimeEdit->dateTime());
	tasks.push_back(newTask);
	settings->SaveSchedullerQueue(tasks);
	tasksComboBox->addItem(newTask.name(),qVariantFromValue(newTask));
	emit tasksChanged();
	
}

void SettingsDialog::SetupSchedullerTab()
{
	calendarWidget->setLocale(localeComboBox->currentIndex()==0 ? QLocale(QLocale::English) : QLocale(QLocale::Russian));
	QObject::connect(calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(SetDate(QDate)));
	beginDateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(120));
	QObject::connect(tasksComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateSchedullerTab(int)));    
	tasks = settings->GetSchedullerQueue();
	for (int i=0;i<tasks.count();i++)
	{
		tasksComboBox->addItem(tasks.at(i).name(),qVariantFromValue(tasks.at(i)));
	}
	Scheduller* scheduller=Scheduller::getInstance();
	QObject::connect(this,SIGNAL(tasksChanged()),scheduller,SLOT(UpdateTasks()));
	Scheduller::freeInstance();
}

void SettingsDialog::UpdateSchedullerTab( int index )
{
	SchedulerTask currentTask=tasksComboBox->itemData(index).value<SchedulerTask>();
	taskNameLineEdit->setText(currentTask.name());
	beginDateTimeEdit->setDateTime(currentTask.startTime());
	switch(currentTask.type())
	{
	case SchedulerTask::START_ALL :
		startAllRadioButton->setChecked(true);
		break;
	case SchedulerTask::PAUSE_ALL:
		pauseAllRadioButton->setChecked(true);
		break;
	case SchedulerTask::LIMIT_UPLOAD:
		limitUlRadioButton->setChecked(true);
		ulLimitEdit->setText(QString::number(currentTask.limit()));
		break;
	case SchedulerTask::LIMIT_DOWNLOAD:
		limitDlRadioButton->setChecked(true);
		dlLimitEdit->setText(QString::number(currentTask.limit()));
		break;
	}
}






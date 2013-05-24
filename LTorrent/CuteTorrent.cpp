/*
CuteTorrent BitTorrenttClient with dht support, userfriendly interface
and some additional features which make it more convenient.
Copyright (C) <year>  <name of author>

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
#include "application.h"
#include "CuteTorrent.h"
#include "Scheduller.h"
#include <QMessageBox>
#include <QComboBox>
#include <QDateTime>
#include <QAbstractItemView>
#include "QTorrentListView.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QIcon>
#include "QBaloon.h"
#include <QProcess>
#include <QTextCodec>
#include <QtNetwork/QHostAddress>
#include <QSortFilterProxyModel>
#include <QClipboard>
#include <QCleanlooksStyle>
CuteTorrent::CuteTorrent(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent,flags)
{
    setupUi(this);
    model = new QTorrentDisplayModel(listView,this);
	
	mng = TorrentManager::getInstance();
	notyfire = new UpdateNotifier();
	mayShowNotifies = false;
	fileinfosLocker = new QMutex(QMutex::NonRecursive);
    setAcceptDrops(true);
	setupStatusBar();
	setupTray();
	setupToolBar();
	setupListView();
	setupTabelWidgets();
	setupFileTabel();
	setupConnections();

	QApplicationSettings* settings=QApplicationSettings::getInstance();
	
	Application::setLanguage("cutetorrent_"+settings->valueString("System","Lang","RUSSIAN"));

	
	QTextCodec *wantUnicode = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForCStrings(wantUnicode);
	
	mng->initSession();

	QTimer::singleShot(10000,this,SLOT(checkForUpdates()));
	QTimer::singleShot(3000,this,SLOT(enableNitifyShow()));
	Scheduller* sch=Scheduller::getInstance();
	
	
	
}
void CuteTorrent::checkForUpdates()
{
		notyfire->fetch();

}
void CuteTorrent::ShowAbout()
{
	QMessageBox::about(this,tr("ABAUT_TITLE"),tr("ABAUT_TEXT").arg(CT_VERSION));
}
void CuteTorrent::ShowUpdateNitify(const QString& newVersion)
{
	QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information;
	QBalloonTip::showBalloon("CuteTorrent", tr("CT_NEW_VERSION %1").arg(newVersion),QBalloonTip::UpdateNotyfy,qVariantFromValue(0), icon,
		5* 1000);
}

void CuteTorrent::setupStatusBar()
{
	
	upLabel = new QLabel(this);
	upLabelText = new QLabel(this);
	upLabelText->setMinimumWidth(140);
	upLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/upload.ico")));
	
	downLabel = new QLabel(this);
	downLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/download.ico")));
	downLabelText = new QLabel(this);
	downLabel->setToolTip(tr("STATUS_DWONLOAD"));
	downLabelText->setToolTip(tr("STATUS_DWONLOAD"));
	upLabel->setToolTip(tr("STATUS_UPLOAD"));
	upLabelText->setToolTip(tr("STATUS_UPLOAD"));
	downLabelText->setMinimumWidth(140);
	statusBar()->addPermanentWidget(upLabel);
	statusBar()->addPermanentWidget(upLabelText);
	statusBar()->addPermanentWidget(downLabel);
	statusBar()->addPermanentWidget(downLabelText);
	
}
void CuteTorrent::setupListView()
{
	
	listView->setModel(model);
	listView->setSelectionMode(QAbstractItemView::ExtendedSelection );
	listView->setContextMenuPolicy(Qt::CustomContextMenu);
}
void CuteTorrent::setupTabelWidgets()
{
	trackerTableWidget->verticalHeader()->hide();
	trackerTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	trackerTableWidget->setColumnWidth(2,120);
	trackerTableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
	addTracker = new QAction(tr("ADD_TRACKER"),trackerTableWidget);
	QObject::connect(addTracker,SIGNAL(triggered()),this,SLOT(AddTracker()));
	trackerTableWidget->addAction(addTracker);

	

    fileTableWidget->setSortingEnabled(true);
	peerTableWidget->verticalHeader()->hide();
	peerTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	peerTableWidget->setSortingEnabled(true);
	peerTableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
	addPeer = new QAction(tr("ADD_PEER"),peerTableWidget);
	QObject::connect(addPeer,SIGNAL(triggered()),this,SLOT(AddPeer()));
	peerTableWidget->addAction(addPeer);


}
void CuteTorrent::setupToolBar()
{
	
	QTorrentItemDelegat::max_width=width()-110;
	listView->setItemDelegate(new QTorrentItemDelegat(this));
	searchEdit=new QLineEdit(this);
	QObject::connect(searchEdit,SIGNAL(returnPressed()),this,SLOT(peformSearch()));
	ul = new QSpinBox(this);
	ul->setSpecialValueText(tr("None"));
	ul->setSuffix(" Kb\\s");
	ul->setMaximum(12000.0f);
	ul->setSingleStep(10.0);
	ul->setButtonSymbols(QAbstractSpinBox::PlusMinus);
	QObject::connect(ul,SIGNAL(valueChanged(int)),this,SLOT(UpdateUL(int)));
	dl = new QSpinBox(this);
	dl->setSpecialValueText(tr("None"));
	dl->setMaximum(12000.0f);
	dl->setSuffix(" Kb\\s");
	dl->setSingleStep(10.0);
	dl->setButtonSymbols(QAbstractSpinBox::PlusMinus);
	QObject::connect(dl,SIGNAL(valueChanged(int)),this,SLOT(UpdateDL(int)));
	uploadLimit = new QLabel(tr("LIMIT_UL"),this);
	uploadLimit->setBuddy(ul);
	downloadLimit = new QLabel(tr("LIMIT_DL"),this);
	downloadLimit->setBuddy(dl);
	searchEdit->setMinimumWidth(100);
	toolBar->addSeparator();
	toolBar->addWidget(uploadLimit);
	toolBar->addWidget(ul);
	toolBar->addWidget(downloadLimit);
	toolBar->addWidget(dl);
	toolBar->addSeparator();
	toolBar->addWidget(searchEdit);
	updateTabWidget(-2);
}
void CuteTorrent::setupConnections()
{
	
	QObject::connect(listView->selectionModel(), SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
															model,SLOT(UpdateSelectedIndex(const QItemSelection &)));
	QObject::connect(listView,SIGNAL(customContextMenuRequested(const QPoint &)),model,SLOT(contextualMenu(const QPoint &)));
	QObject::connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
	QObject::connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
	QObject::connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(updateTabWidget(int)));
	QObject::connect(model,SIGNAL(updateTabSender(int)),this,SLOT(updateTabWidget(int)));
	QObject::connect(mng,SIGNAL(TorrentError(const QString&,const QString&)),this,SLOT(ShowTorrentError(const QString&,const QString&)));
	QObject::connect(mng,SIGNAL(TorrentCompleted(const QString&,const QString&)),
									this,SLOT(showTorrentCompletedNotyfy(const QString,const QString)));
	QObject::connect(mng,SIGNAL(TorrentInfo(const QString&,const QString&)),
		this,SLOT(showTorrentInfoNotyfy(const QString,const QString)));
	QObject::connect(mng,SIGNAL(AddTorrentGui(Torrent*)),model,SLOT(AddTorrent(Torrent*)));
	QObject::connect(notyfire,SIGNAL(showUpdateNitify(const QString &)),this,SLOT(ShowUpdateNitify(const QString &)));
	QObject::connect(notyfire,SIGNAL(showNoUpdateNitify(const QString &)),this,SLOT(ShowNoUpdateNitify(const QString &)));
	QObject::connect(fileTableWidget,SIGNAL(customContextMenuRequested ( const QPoint &)),this,SLOT(fileTabContextMenu(const QPoint &)));
	QObject::connect(listView->verticalScrollBar(),SIGNAL(rangeChanged (int,int)),this,SLOT(updateItemWidth(int,int)));
}
void CuteTorrent::fileTabContextMenu(const QPoint & point)
{
	QModelIndex qmi=fileTableWidget->indexAt(point);
	if (qmi.isValid())
	{
		fileinfosLocker->lock();
		int currentPriority=file_infos.at(qmi.row()).prioiry;
		fileinfosLocker->unlock();
		switch(currentPriority)
		{
			case 1:
			case 2:
				lowPriority->setChecked(true);
				mediumPriority->setChecked(false);
				highPriority->setChecked(false);
				dontDownload->setChecked(false);
				break;
			case 3:
			case 4:
			case 5:
				lowPriority->setChecked(false);
				mediumPriority->setChecked(true);
				highPriority->setChecked(false);
				dontDownload->setChecked(false);
				break;
			case 6:
			case 7:
				lowPriority->setChecked(false);
				mediumPriority->setChecked(false);
				highPriority->setChecked(true);
				dontDownload->setChecked(false);
				break;
			case 0:
				highPriority->setChecked(false);
				mediumPriority->setChecked(false);
				highPriority->setChecked(false);
				dontDownload->setChecked(true);
				break;
			default:
				highPriority->setChecked(false);
				mediumPriority->setChecked(false);
				highPriority->setChecked(false);
				dontDownload->setChecked(false);
				break;
		}
		fileTabMenu->exec(fileTableWidget->mapToGlobal(point));
	}
	else
	{

		fileTableWidget->selectionModel()->reset();

	}
}
void CuteTorrent::ShowNoUpdateNitify(const QString & ver)
{
	
	
	
}
void CuteTorrent::ShowTorrentError(const QString& name,const QString& error)
{
	QBalloonTip::showBalloon("CuteTorrent", tr("CT_ERROR %1\n%2").arg(name).arg(error), QBalloonTip::Error,qVariantFromValue(0),
		QSystemTrayIcon::Critical,15000,false);
	
}
void CuteTorrent::showTorrentCompletedNotyfy(const QString name,QString path)
{
	if (!mayShowNotifies)
			return;	
	QBalloonTip::showBalloon("CuteTorrent", tr("CT_DOWNLOAD_COMPLETE %1").arg(name),QBalloonTip::TorrentCompleted,qVariantFromValue(path+name),
		QSystemTrayIcon::Information,15000,false);
	
}
void CuteTorrent::updateItemWidth(int min,int max)
{
	//qDebug() << "updateItemWidth " << QTorrentItemDelegat::max_width << listView->verticalScrollBar()->isVisible() << min << max;
	QTorrentItemDelegat::max_width=width()-QApplication::style( )->pixelMetric( QStyle::PM_MessageBoxIconSize )-35-(max!=0 ? listView->autoScrollMargin() : 0);
	//qDebug() << "updateItemWidth " << QTorrentItemDelegat::max_width << listView->verticalScrollBar()->isVisible()<< min << max;
}
void CuteTorrent::updateTabWidget(int tab)
{
	//qDebug() << "updateTabWidget(" << tab << ");";

	
	trayIcon->setToolTip("CuteTorrent "CT_VERSION"\nUpload: "+mng->GetSessionUploadSpeed()+"\nDownload:"+mng->GetSessionDownloadSpeed());
	if (this->isMinimized())
		return;
	bool udapteLimits = false;
	if (tab < 0)
	{
		if (tab==-2)
			udapteLimits = true;	
		tab=tabWidget->currentIndex();
	}
	//qDebug() << "udapteLimits =" << udapteLimits << ";";
	

	try
	{
		switch(tab)
		{
		case 0:
			
			UpdateInfoTab();
			break;
		case 1:
			
			UpdatePeerTab();
			break;
		case 2:
			
			UpadteTrackerTab();
			break;
		case 3:
			
			UpdateFileTab();
			break;
		}
		if (udapteLimits)
		{
			Torrent* tor = model->GetSelectedTorrent();
			if (tor!=NULL)
			{
				if (ul->value()!=tor->GetUploadLimit()/1024)
					ul->setValue(tor->GetUploadLimit()/1024);
				if (dl->value()!=tor->GetDownloadLimit()/1024)
					dl->setValue(tor->GetDownloadLimit()/1024);
			}
			else
			{
				if (ul->value()!=mng->GetUploadLimit()/1024)
					ul->setValue(mng->GetUploadLimit()/1024);
				if (dl->value()!=mng->GetDownloadLimit()/1024)
					dl->setValue(mng->GetDownloadLimit()/1024);
			}
			
			
		}
		upLabelText->setText(QString("%1(%2)").arg(mng->GetSessionUploaded()).arg(mng->GetSessionUploadSpeed()));
		downLabelText->setText(QString("%1(%2)").arg(mng->GetSessionDownloaded()).arg(mng->GetSessionDownloadSpeed()));
		
	}
	catch (std::exception e)
	{
		QMessageBox::warning(this,"Error",QString("CuteTorrent::updateTabWidget()\n")+e.what());
	}
	
}

class MyTableWidgetItem : public QTableWidgetItem {
public:
	MyTableWidgetItem(QString text) : QTableWidgetItem(text)
	{

	}
	bool operator <(const QTableWidgetItem &other) const
	{
		QHostAddress thisadr(text());
		if (!thisadr.isNull())
		{
			//qDebug() << "Ip Addresses" << text() << other.text();
			QHostAddress otheradr(other.text());
			return thisadr.toIPv4Address() < otheradr.toIPv4Address();
		}
		else
		if (text().contains(" tb",Qt::CaseInsensitive) || text().contains(" gb",Qt::CaseInsensitive) ||text().contains(" kb",Qt::CaseInsensitive) || text().contains(" mb",Qt::CaseInsensitive) || text().contains(" b",Qt::CaseInsensitive))
		{
			QStringList parts1 = text().split(' ');
			bool ok;
			double speed1=parts1[0].toDouble(&ok);
			if (ok)
			{
				QStringList parts2=other.text().split(' ');
				double speed2=parts2[0].toDouble();
				
				switch(parts1[1][0].toLower().toAscii())
				{
				case 'k':
					speed1*=1024.0;
					break;
				case 'm':
					speed1*=1024*1024.0;
					break;
				case 'g':
					speed1*=1024*1024*1024.0;
					break;
				case 't':
					speed1*=1024*1024*1024*1024.0;
					break;
				case 'b':
					break;

				}
				//qDebug() << parts1 << speed1;
				switch(parts2[1][0].toLower().toAscii())
				{
				case 'k':
					speed2*=1024;
					break;
				case 'm':
					speed2*=1024*1024;
					break;
				case 'g':
					speed2*=1024*1024*1024;
					break;
				case 't':
					speed2*=1024*1024*1024*1024;
					break;
				case 'b':
					break;

				}
				//qDebug() << "Speed or size" << text() << other.text() << speed1 << speed2;
				return speed1 < speed2;
			}

		}else
		if (text().endsWith('%'))
		{
			//qDebug() << "Percentage" << text() << other.text() ;
			QString perc1=text().remove('%'),perc2=other.text().remove('%');
			return perc1.toDouble() < perc2.toDouble();
		}
		return QTableWidgetItem::operator <(other);
	}
};
void CuteTorrent::UpdateFileTab()
{
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		
		fileinfosLocker->lock();
		file_infos=tor->GetFileDownloadInfo();
		fileTableWidget->setRowCount(file_infos.count());
		
		
		for (int i=0;i<file_infos.count();i++)
		{
			
			file_info current=file_infos.at(i);
			
			fileTableWidget->setItem(i,0,new MyTableWidgetItem(current.name));
			
			fileTableWidget->setItem(i,1,new MyTableWidgetItem(StaticHelpers::toKbMbGb(current.size)));
			
			fileTableWidget->setItem(i,2,new MyTableWidgetItem(QString::number(current.progrss,'f',0)+" %"));
			
			fileTableWidget->setItem(i,3,new MyTableWidgetItem(StaticHelpers::filePriorityToString(current.prioiry)));
		}
        //fileTableWidget->resizeColumnsToContents();
		fileinfosLocker->unlock();
	}
	else
	{
		fileTableWidget->setRowCount(0);
	}
}
void CuteTorrent::setupTray()
{
	 createActions();
     createTrayIcon();
	 trayIcon->setToolTip("CuteTorrent "CT_VERSION);
	 trayIcon->show();
}

void CuteTorrent::changeEvent(QEvent *event)
{

	 if(event->type() == QEvent::ActivationChange) 
	 {     
		if(!isVisible() && isMinimized()) 
		{
			setUpdatesEnabled(false);
		}
		else
		{
			setUpdatesEnabled(true);
		}

	}
	if (event->type()==QEvent::LanguageChange)
	{
		retranslateUi(this);

		openFile->setText(tr("FILETAB_OPEN_FILE"));
		openDir->setText(tr("FILETAB_OPEN_FOLDER"));
		priority->setTitle(tr("FILETAB_PRIORITY"));
		lowPriority->setText(tr("FILETAB_PRIORITY_LOW"));
		mediumPriority->setText(tr("FILETAB_PRIORITY_MEDIUM"));
		highPriority->setText(tr("FILETAB_PRIORITY_HIGH"));
		dontDownload->setText(tr("FILETAB_PRIORITY_ZERO"));

		minimizeAction->setText(tr("ACTION_HIDE"));
		maximizeAction->setText(tr("ACTION_MAXIMIZE_FULLSCREEN"));
		restoreAction->setText(tr("ACTION_MAXIMIZE"));
		quitAction->setText(tr("ACTION_EXIT"));
		copyContext->setText(tr("ACTION_COPY"));
		
		downLabel->setToolTip(tr("STATUS_DWONLOAD"));
		downLabelText->setToolTip(tr("STATUS_DWONLOAD"));
		upLabel->setToolTip(tr("STATUS_UPLOAD"));
		upLabelText->setToolTip(tr("STATUS_UPLOAD"));

		uploadLimit->setText(tr("LIMIT_UL"));
		downloadLimit->setText(tr("LIMIT_DL"));

		addTracker->setText(tr("ADD_TRACKER"));
		addPeer->setText(tr("ADD_PEER"));

		model->retranslate();
	 }
  QMainWindow::changeEvent(event);


}
void CuteTorrent::iconActivated(QSystemTrayIcon::ActivationReason reason)
 {
     switch (reason) 
	 {
		 case QSystemTrayIcon::DoubleClick:
			 if (isVisible())
				 hide();
			 else
			 {
				showNormal();
				raise();
				activateWindow();
			}
			 break;
		 default:
			 break;
     }
 }

void CuteTorrent::createTrayIcon()
 {
     trayIconMenu = new QMenu(this);
     trayIconMenu->addAction(minimizeAction);
     trayIconMenu->addAction(maximizeAction);
     trayIconMenu->addAction(restoreAction);
     trayIconMenu->addSeparator();
     trayIconMenu->addAction(quitAction);

     trayIcon = new QSystemTrayIcon(this);
	 trayIcon->setIcon(QIcon(QString::fromUtf8(":/icons/app.ico")));
     trayIcon->setContextMenu(trayIconMenu);
 }
 void CuteTorrent::createActions()
 {
	 minimizeAction = new QAction(tr("ACTION_HIDE"), this);
	 connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

	 maximizeAction = new QAction(tr("ACTION_MAXIMIZE_FULLSCREEN"), this);
	 connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

	 restoreAction = new QAction(tr("ACTION_MAXIMIZE"), this);
	 connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

	 quitAction = new QAction(tr("ACTION_EXIT"), this);
	 connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	 copyContext = new QAction(tr("ACTION_COPY"),describtionLabel);
	 connect(copyContext, SIGNAL(triggered()), this, SLOT(copyDiscribtion()));
	 describtionLabel->addAction(copyContext);

 }
void CuteTorrent::ConnectMessageReceved(QtSingleApplication* a)
{
	QObject::connect(a,SIGNAL(messageReceived ( const QString & )), this, SLOT(HandleNewTorrent(const QString &)));
}
void CuteTorrent::HandleNewTorrent(const QString & path)
{
	showNormal();
	activateWindow();
	OpenTorrentDialog dlg(this);
	dlg.SetData(path);
	dlg.execConditional();

}
void CuteTorrent::ShowCreateTorrentDialog(void)
{
	CreateTorrentDialog dlg(this);
	
	dlg.exec();
}
void CuteTorrent::ShowOpenTorrentDialog()
{
	QApplicationSettings* settings=QApplicationSettings::getInstance();
	QString lastDir=settings->valueString("System","LastOpenTorrentDir","");
	QString filename =  QFileDialog::getOpenFileName(this,tr("OPEN_TOORENT_DIALOG"),
		lastDir , tr("Торрент файлы (*.torrent);;Any File (*.*)"));
	if (!filename.isEmpty())
	{
		OpenTorrentDialog* dlg=new OpenTorrentDialog(this);
		settings->setValue("System","LastOpenTorrentDir",filename);
		dlg->SetData(filename);
		dlg->execConditional();
		delete dlg;
	}
	QApplicationSettings::FreeInstance();
}
void CuteTorrent::enableNitifyShow()
{
	mayShowNotifies = true;
}

void CuteTorrent::UpdateInfoTab()
{
	
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		fillPieceDisplay();	
		downloadedBytesLabel->setText(tor->GetTotalDownloaded());
		uploadedBytesLabel->setText(tor->GetTotalUploaded());
		downloadSpeedLabel->setText(tor->GetDwonloadSpeed());
		activetimeLabel->setText(tor->GetActiveTime());
		uploadSpeedLabel->setText(tor->GetUploadSpeed());
		pathLabel->setText(tor->GetSavePath());
		totalSizeLabel->setText(tor->GetTotalSize());
		seedCoutLabel->setText(tor->GetSeedString());
		peerCoutLabel->setText(tor->GetPeerString());
		describtionLabel->setText(tor->GetDiscribtion());
		timeleftLabel->setText(tor->GetRemainingTime());
	}
	else
	{
		clearPieceDisplay();
		downloadedBytesLabel->setText("");
		downloadSpeedLabel->setText("");
		uploadedBytesLabel->setText("");
		activetimeLabel->setText("");
		timeleftLabel->setText("");
		uploadSpeedLabel->setText("");
		pathLabel->setText("");
		totalSizeLabel->setText("");
		seedCoutLabel->setText("");
		peerCoutLabel->setText("");
		describtionLabel->setText("");
	}
	
}
void CuteTorrent::UpdatePeerTab()
{
	
	Torrent* tor=model->GetSelectedTorrent();
	
	if (tor!=NULL)
	{
		
		
		QVector<peer_info> peerInfos=QVector<peer_info>::fromStdVector(tor->GetPeerInfo());
		peerTableWidget->setRowCount(peerInfos.size());
		for(int i=0;i<peerInfos.size();i++)
		{
			peerTableWidget->setItem(i,0,new MyTableWidgetItem(QString::fromStdString(peerInfos[i].ip.address().to_string())));
			peerTableWidget->setItem(i,1,new MyTableWidgetItem(QString::fromUtf8(peerInfos[i].client.c_str())));
			peerTableWidget->setItem(i,2,new MyTableWidgetItem(QString::number(peerInfos[i].progress_ppm/10000.f,'f',1) + "%"));
			peerTableWidget->setItem(i,3,new MyTableWidgetItem(StaticHelpers::toKbMbGb(peerInfos[i].down_speed)+"/s"));
			peerTableWidget->setItem(i,4,new MyTableWidgetItem(StaticHelpers::toKbMbGb(peerInfos[i].up_speed)+"/s"));
			peerTableWidget->setItem(i,5,new MyTableWidgetItem(StaticHelpers::toKbMbGb(peerInfos[i].total_download)));
			peerTableWidget->setItem(i,6,new MyTableWidgetItem(StaticHelpers::toKbMbGb(peerInfos[i].total_upload)));
		}
        //peerTableWidget->resizeColumnsToContents();
	
	}
	else
	{
		peerTableWidget->setRowCount(0);
	}
}
void CuteTorrent::UpadteTrackerTab()
{
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		std::vector<announce_entry> trackers=tor->GetTrackerInfo();
		
		trackerTableWidget->setRowCount(trackers.size());
		
        for (size_type i=0;i<trackers.size();i++)
		{
			trackerTableWidget->setItem(i,0,new QTableWidgetItem(trackers[i].url.c_str()));
			trackerTableWidget->setItem(i,1,new QTableWidgetItem(trackers[i].message.length() >0 ? QString::fromUtf8(trackers[i].message.c_str()) : "Ok" ));
			trackerTableWidget->setItem(i,2,new QTableWidgetItem(StaticHelpers::toTimeString(trackers[i].next_announce_in())));
		
		}
        //trackerTableWidget->resizeColumnsToContents();
		
	
	}
	else
	{
		trackerTableWidget->setRowCount(0);
	}
}
void CuteTorrent::PauseSelected()
{
	model->ActionOnSelectedItem(QTorrentDisplayModel::pause);
	
}
void CuteTorrent::ResumeSelected()
{
	model->ActionOnSelectedItem(QTorrentDisplayModel::resume);
	
}
void CuteTorrent::DeleteSelected()
{
	model->ActionOnSelectedItem(QTorrentDisplayModel::remove);
	
}
void CuteTorrent::retranslate()
{
	retranslateUi(this);
}
void CuteTorrent::OpenSettingsDialog()
{
	SettingsDialog* dlg = new SettingsDialog(this);
	QObject::connect(dlg,SIGNAL(needRetranslate()),this,SLOT(retranslate()));
	dlg->exec();
	delete dlg;
	updateTabWidget(-2);
}
void CuteTorrent::closeEvent(QCloseEvent* ce)
{
	ce->ignore();
	hide();
	QBalloonTip::showBalloon("CuteTorrent", tr("CT_HIDE_MSG"),QBalloonTip::Info,qVariantFromValue(0),
		QSystemTrayIcon::Information,5000,false);
	setUpdatesEnabled(false);
	return;
	

}

void CuteTorrent::dragEnterEvent(QDragEnterEvent *event)
{
    foreach (const QString &mime, event->mimeData()->formats())
    {
       qDebug("mimeData: %s", mime.toLocal8Bit().data());
    }
    if (event->mimeData()->hasFormat(QString("text/plain")) || event->mimeData()->hasFormat(QString("text/uri-list")))
    {
        event->acceptProposedAction();
    }
}

void CuteTorrent::dropEvent(QDropEvent *event)
{
    QStringList files;
    if (event->mimeData()->hasUrls())
    {
        const QList<QUrl> urls = event->mimeData()->urls();
        foreach (const QUrl &url, urls)
        {
            if (!url.isEmpty())
            {
                if (url.scheme().compare("file", Qt::CaseInsensitive) == 0)
                    files << url.toLocalFile();
                else
                    files << url.toString();
            }
        }
     }
    else
    {
        files = event->mimeData()->text().split(QString::fromUtf8("\n"));
    }
    foreach(QString file,files)
    {
        if (file.startsWith("magnet:", Qt::CaseInsensitive) || file.endsWith(".torrent",Qt::CaseInsensitive))
        {
            OpenTorrentDialog* dlg2 = new OpenTorrentDialog();
            dlg2->SetData(file);
            dlg2->exec();
            delete dlg2;
            event->acceptProposedAction();
        }
        else
        {
            //qDebug() << file;
        }
    }


}
CuteTorrent::~CuteTorrent()
{
	trayIcon->hide();
	mng->freeInstance();
	model->~QTorrentDisplayModel();
	Scheduller::freeInstance();
	QApplicationSettings::FreeInstance();
	delete notyfire;
	delete trayIcon;
}

void CuteTorrent::setupFileTabel()
{
	fileTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	fileTableWidget->setColumnWidth(0,300);
	fileTableWidget->setColumnWidth(1,60);
	fileTableWidget->setColumnWidth(2,60);
	fileTableWidget->setColumnWidth(3,60);
	
	setupFileTabelContextMenu();
}
void CuteTorrent::setupFileTabelContextMenu()
{
	fileTabMenu = new QMenu(this);
	openFile = new QAction(tr("FILETAB_OPEN_FILE"), fileTabMenu);
	QObject::connect(openFile, SIGNAL(triggered()), this, SLOT(OpenFileSelected()));
	fileTabMenu->addAction(openFile);
	openDir = new QAction(tr("FILETAB_OPEN_FOLDER"), this);
	QObject::connect(openDir, SIGNAL(triggered()), this, SLOT(OpenDirSelected()));
	fileTabMenu->addAction(openDir);
	fileTabMenu->addSeparator();
	priority = new QMenu(fileTabMenu);
	priority->setTitle(tr("FILETAB_PRIORITY"));
	lowPriority = new QAction(tr("FILETAB_PRIORITY_LOW"), fileTabMenu);
	lowPriority->setCheckable(true);
	QObject::connect(lowPriority, SIGNAL(triggered()), this, SLOT(setLowForCurrentFile()));
	priority->addAction(lowPriority);
	mediumPriority = new QAction(tr("FILETAB_PRIORITY_MEDIUM"), fileTabMenu);
	mediumPriority->setCheckable(true);
	QObject::connect(mediumPriority, SIGNAL(triggered()), this, SLOT(setMediumForCurrentFile()));
	priority->addAction(mediumPriority);
	highPriority = new QAction(tr("FILETAB_PRIORITY_HIGH"), fileTabMenu);
	highPriority->setCheckable(true);
	QObject::connect(highPriority, SIGNAL(triggered()), this, SLOT(setHighForCurrentFile()));
	priority->addAction(highPriority);
	fileTabMenu->addMenu(priority);
	fileTabMenu->addSeparator();
	dontDownload = new QAction(tr("FILETAB_PRIORITY_ZERO"), fileTabMenu);
	dontDownload->setCheckable(true);
	QObject::connect(dontDownload, SIGNAL(triggered()), this, SLOT(setNotDownloadForCurrentFile()));
	fileTabMenu->addAction(dontDownload);

}

void CuteTorrent::OpenFileSelected()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		int file_num=fileTableWidget->currentRow();
		QDesktopServices desctopService;
		fileinfosLocker->lock();
		QString path=combine_path(tor->GetSavePath().toAscii().data(),file_infos.at(file_num).name.toAscii().data()).c_str();
		fileinfosLocker->unlock();
		desctopService.openUrl(QUrl("file:///"+path));
	}
}

void CuteTorrent::OpenDirSelected()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		int file_num=fileTableWidget->currentRow();
		fileinfosLocker->lock();
		QString path = QFileInfo(QDir::toNativeSeparators(tor->GetSavePath()+file_infos.at(file_num).name)).absoluteFilePath();
		fileinfosLocker->unlock();
#ifdef Q_WS_MAC
		QStringList args;
		args << "-e";
		args << "tell application \"Finder\"";
		args << "-e";
		args << "activate";
		args << "-e";
		args << "select POSIX file \""+path+"\"";
		args << "-e";
		args << "end tell";
		QProcess::startDetached("osascript", args);
#endif

#ifdef Q_WS_WIN
		QStringList args;
		args << "/select," << QDir::toNativeSeparators(path);
		QProcess::startDetached("explorer", args);
#endif

	}
}

void CuteTorrent::setLowForCurrentFile()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		
		mediumPriority->setChecked(false);
		highPriority->setChecked(false);
		dontDownload->setChecked(false);
		int file_num=fileTableWidget->currentRow();
		fileinfosLocker->lock();
		file_info current=file_infos.at(file_num);
		fileinfosLocker->unlock();
		tor->SetFilePriority(current.index,2);
	}
}

void CuteTorrent::setMediumForCurrentFile()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		lowPriority->setChecked(false);
		highPriority->setChecked(false);
		dontDownload->setChecked(false);
		int file_num=fileTableWidget->currentRow();
		fileinfosLocker->lock();
		file_info current=file_infos.at(file_num);
		fileinfosLocker->unlock();
		tor->SetFilePriority(current.index,5);
	}
}

void CuteTorrent::setHighForCurrentFile()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		lowPriority->setChecked(false);
		mediumPriority->setChecked(false);
		dontDownload->setChecked(false);
		int file_num=fileTableWidget->currentRow();
		fileinfosLocker->lock();
		file_info current=file_infos.at(file_num);
		fileinfosLocker->unlock();
		tor->SetFilePriority(current.index,7);
	}
}

void CuteTorrent::setNotDownloadForCurrentFile()
{
	Torrent* tor= model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		lowPriority->setChecked(false);
		mediumPriority->setChecked(false);
		highPriority->setChecked(false);
		int file_num=fileTableWidget->currentRow();
		fileinfosLocker->lock();
		file_info current=file_infos.at(file_num);
		fileinfosLocker->unlock();
		tor->SetFilePriority(current.index,0);
	}
}

void CuteTorrent::ProcessMagnet()
{
	bool ok;
	QString magnetLink=QInputDialog::getText(this,tr("MAGNET_LINK_DLG"),tr("MAGNET_LINK:"),QLineEdit::Normal,"",&ok);
	if (ok && !magnetLink.isEmpty())
	{
		OpenTorrentDialog* dlg2 = new OpenTorrentDialog();
		dlg2->SetData(magnetLink);
		dlg2->exec();
		delete dlg2;
	}
	
}

void CuteTorrent::peformSearch()
{
	QString searchText=searchEdit->text();
	QDesktopServices desctopService;
	desctopService.openUrl(QUrl("http://btdigg.org/search?q="+QUrl::toPercentEncoding(searchText)));
}

void CuteTorrent::resizeEvent( QResizeEvent * event )
{
    Q_UNUSED(event);
	QTorrentItemDelegat::max_width=width()-QApplication::style( )->pixelMetric( QStyle::PM_MessageBoxIconSize )-35-(listView->verticalScrollBar()->isVisible() ? listView->autoScrollMargin() : 0);
	fillPieceDisplay();
}

void CuteTorrent::showTorrentInfoNotyfy( const QString name,const QString info)
{
	QBalloonTip::showBalloon("CuteTorrent", QString("%1\n%2").arg(name).arg(info),QBalloonTip::Info,qVariantFromValue(0),
		QSystemTrayIcon::Information,15000,false);
}

void CuteTorrent::keyPressEvent( QKeyEvent * event )
{
	if (focusWidget()!=listView)
	{
		QMainWindow::keyPressEvent(event);
		return;
	}
	switch(event->key())
	{
		case Qt::Key_Delete:
			{
				if(event->modifiers()==Qt::ShiftModifier)
				{
					

					model->ActionOnSelectedItem(QTorrentDisplayModel::removeAll);
				}
				else
				{
					model->ActionOnSelectedItem(QTorrentDisplayModel::remove);
				}
				event->accept();
				break;
			}
		case  Qt::Key_Enter:
		case  Qt::Key_Return:
			{
				model->OpenDirSelected();
				event->accept();
				break;
			}
		default:
			QMainWindow::keyPressEvent(event);
			break;
	}
}

void CuteTorrent::fillPieceDisplay()
{
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		int piece_count=tor->GetPieceCount();
		QVector<int> avaliablePieces = tor->GetDownloadedPieces();
		QVector<int> dwonloadingPieces = tor->GetDownloadingPieces();
		QGraphicsScene *scene = new QGraphicsScene(this);
		qreal pieceItemWidth  = (piceDwonloadedView->width())*1.0/piece_count;
		qreal pieceItemHeight = piceDwonloadedView->height()*0.8;
		for (int i=0;i<avaliablePieces.count();i++)
		{
			scene->addRect(avaliablePieces[i]*pieceItemWidth,0,pieceItemWidth,pieceItemHeight,QPen(Qt::darkBlue),QBrush(Qt::darkBlue));
		}
		for (int i=0;i<dwonloadingPieces.count();i++)
		{
			scene->addRect(dwonloadingPieces[i]*pieceItemWidth,0,pieceItemWidth,pieceItemHeight,QPen(Qt::green),QBrush(Qt::green));
		}
		piceDwonloadedView->scene()->deleteLater();
		piceDwonloadedView->setScene(scene);
		piceDwonloadedView->show();
	}
	
}

void CuteTorrent::copyDiscribtion()
{
	QClipboard *clipboard = QApplication::clipboard();
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		clipboard->setText(tor->GetDiscribtion());
	}
	
}

void CuteTorrent::clearPieceDisplay()
{
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->clear();
	piceDwonloadedView->scene()->deleteLater();
	piceDwonloadedView->setScene(scene);
	piceDwonloadedView->show();
}

void CuteTorrent::UpdateUL(int kbps)
{
	//qDebug()<< "UpdateUL" << kbps*1024;
	Torrent* tor=model->GetSelectedTorrent();
	if (tor!=NULL)
	{
		tor->SetUlLimit(kbps*1024);
	}
	else
	{
		QApplicationSettings* settings = QApplicationSettings::getInstance();
		settings->setValue("Torrent","upload_rate_limit",kbps*1024);
		QApplicationSettings::FreeInstance();
		mng->SetUlLimit(kbps*1024);
	}
}

void CuteTorrent::UpdateDL(int kbps)
{
	//qDebug()<< "UpdateDL" << kbps*1024;
	Torrent* tor=model->GetSelectedTorrent();
	
	if (tor!=NULL)
	{
		tor->SetDlLimit(kbps*1024);
	}
	else
	{
		QApplicationSettings* settings = QApplicationSettings::getInstance();
		settings->setValue("Torrent","download_rate_limit",kbps*1024);
		QApplicationSettings::FreeInstance();
		mng->SetDlLimit(kbps*1024);
	}
}

void CuteTorrent::AddPeer()
{
	Torrent* torrent=model->GetSelectedTorrent();
	if (torrent!=NULL)
	{
		bool ok;
		QString peerStr = QInputDialog::getText(this,tr("ADD_PEER_DLG"),tr("PEER:"),QLineEdit::Normal,"",&ok);
		if (ok && !peerStr.isEmpty())
		{
			QStringList parts = peerStr.split(':');
			if (parts.count()==2)
			{
				QHostAddress adr(parts[0]);
				if(!adr.isNull())
				{
					torrent->AddPeer(adr,parts[1].toUInt());
					return;
				}
				
			}
			QMessageBox::critical(this,tr("PEER_ERR"),tr("INVALID_IP_STRING"));
		}
	}
}

void CuteTorrent::AddTracker()
{
	Torrent* torrent=model->GetSelectedTorrent();
	if (torrent!=NULL)
	{
		bool ok;
		QString trackerUrl = QInputDialog::getText(this,tr("ADD_TRACKER_DLG"),tr("TRACKER:"),QLineEdit::Normal,"",&ok);
		if (ok && !trackerUrl.isEmpty())
		{
			torrent->AddTracker(trackerUrl);
		}
	}
}

void CuteTorrent::StopSelected()
{
	model->ActionOnSelectedItem(QTorrentDisplayModel::stop);
}




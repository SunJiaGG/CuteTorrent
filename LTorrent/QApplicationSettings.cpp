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
#include "QApplicationSettings.h"
#include <QMessageBox>
#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include "StaticHelpers.h"
QApplicationSettings* QApplicationSettings::_instance=NULL;
int QApplicationSettings::_instanceCount = 0;

QApplicationSettings::QApplicationSettings()
{
	try
	{
		settings = new QSettings( QApplication::applicationDirPath()+"/CuteTorrent.ini", QSettings::IniFormat);

		locker= new QMutex();
		ReedSettings();
	}
	catch(std::exception ex)
	{
		QMessageBox::warning(0,"Error",QString("QApplicationSettings::QApplicationSettings()")+ex.what());
	}
	
}
QApplicationSettings::~QApplicationSettings()
{
	//qDebug() << "QApplicationSettings: object destruction";
	WriteSettings();

}
QApplicationSettings* QApplicationSettings::getInstance()
{
	
	if (_instance==NULL)
		_instance = new QApplicationSettings();
	//qDebug() << "QApplicationSettings giving " <<_instanceCount<< " instance " ;
	_instanceCount++;
	return _instance;
}
void QApplicationSettings::FreeInstance()
{
	
	_instanceCount--;
	//qDebug() << "QApplicationSettings freeing " <<_instanceCount<< " instance " ;
	if (!_instanceCount)
	{
		_instance->~QApplicationSettings();
		_instance=NULL;
	}
	
}
QStringList QApplicationSettings::GetGroupNames()
{
	locker->lock();
	QStringList res=settings->childGroups();
	locker->unlock();
	return res;
}

void QApplicationSettings::setValue(const QString group,const QString key,const QVariant &value)
{
	locker->lock();
	settingsStorrage[group][key]=value;
	//qDebug() << "QApplicationSettings::setValue " << group << " " << key << " " << value;
	locker->unlock();
	WriteSettings();
}

QVariant QApplicationSettings::value(const QString group,const QString key)
{
	locker->lock();
	QVariant res = QVariant(QVariant::Double);
	if (settingsStorrage.contains(group))
		if (settingsStorrage[group].contains(key))
			res=settingsStorrage[group][key];
	locker->unlock();
	return res;
}
int QApplicationSettings::valueInt(const QString group,const QString key,int defalt)
{
	QVariant val=value(group,key);
	//qDebug() << group << key << val << val.isNull() ;
	if (val.isNull() )
	{
		settingsStorrage[group][key]=defalt;
		return defalt;
	}
	else
		return val.toInt();
}
QString	QApplicationSettings::valueString(const QString group,const QString key,QString defalt)
{
	QVariant val=value(group,key);
	//qDebug() << group << key << val << val.isNull() ;
	if (val.isNull() )
	{
		settingsStorrage[group][key]=defalt;
		return defalt;
	}
	else
		return val.toString();
}

bool QApplicationSettings::valueBool(const QString group,const QString key,bool defalt)
{
	QVariant val=value(group,key);
	//qDebug() << group << key << val << val.isNull() ;
	if (val.isNull() )
	{
		settingsStorrage[group][key]=defalt;
		return defalt;
	}
	else
		return val.toBool();
}
void  QApplicationSettings::ReedSettings()
{
	
	QStringList rootGroups=settings->childGroups();
	//qDebug() << "================================================";
	for(int i=0;i<rootGroups.size();i++)
	{
		
		settings->beginGroup(rootGroups.at(i));
		QStringList keys= settings->childKeys();
		for (int j=0;j<keys.size();j++)
		{
			//qDebug() << rootGroups.at(i) << keys.at(j) << settings->value(keys.at(j));
			settingsStorrage[rootGroups.at(i)][keys.at(j)]=settings->value(keys.at(j));
		}
		settings->endGroup();
	}
	//qDebug() << "================================================";
	
}
void QApplicationSettings::SaveFilterGropups(QList<GroupForFileFiltering> filters)
{
	locker->lock();
	settings->beginGroup("FileFiltering");
	settings->remove("");
	for (int i=0;i<filters.count();i++)
	{
		GroupForFileFiltering group = filters.at(i);
		settings->setValue(group.Name(),QString("savepath;;%1;;extensions;;%2").arg(group.SavePath()).arg(group.Extensions()));
	}
	settings->endGroup();
	locker->unlock();
}
QList<GroupForFileFiltering> QApplicationSettings::GetFileFilterGroups()
{
	QList<GroupForFileFiltering> res;
	locker->lock();
	settings->beginGroup("FileFiltering");
	QStringList groupNames=settings->childKeys();
	for (int i=0;i<groupNames.count();i++)
	{
		QStringList tmpVal= settings->value(groupNames.at(i)).toString().split(";;");
		if (tmpVal.at(0)!="savepath" && tmpVal.count()<4)
			continue;
		else
		{
			QString savepath=tmpVal.at(1);
			QString extensions = tmpVal.at(3);
			res.append(GroupForFileFiltering(groupNames.at(i),extensions,savepath));
		}
	}
	settings->endGroup();
	locker->unlock();
	return res;
}
void  QApplicationSettings::WriteSettings()
{
	
	QMap<QString, QMap<QString,QVariant> >::const_iterator i = settingsStorrage.constBegin();
	while (i != settingsStorrage.constEnd())
	{
		if (i.key()=="FileFiltering")
		{
			i++;
			continue;
		}
		settings->beginGroup(i.key());
		QMap<QString,QVariant>::const_iterator j=i.value().constBegin();
		while (j != i.value().constEnd())
		{
			//qDebug() << QString("[%1] %2 %3" ).arg(i.key()).arg(j.key()).arg(j.value().toString());
			settings->setValue(j.key(),j.value());
			++j;
		}
		settings->endGroup();
		++i;
	}
	
}

QList<SchedulerTask> QApplicationSettings::GetSchedullerQueue()
{
	QList<SchedulerTask> res;
	res.clear();
	QFile file("CT_DATA/schedulertasks.xml");
	if (!file.open(QFile::ReadOnly))
	{
		return res;
	}
	QXmlStreamReader xml(&file);
	while (!xml.atEnd())
	{
		QXmlStreamReader::TokenType tType=xml.readNext();
		if(xml.name()=="tasks")
			continue;
		if(xml.name()!="task")
			continue;
		if (tType!=QXmlStreamReader::StartElement)
			continue;
		QXmlStreamAttributes atribbutes=xml.attributes();
		SchedulerTask::TaskType type=SchedulerTask::UNKNOWN;
		int limit;
		QDateTime begin,end;
		QString name;
		if (atribbutes.hasAttribute("TYPE"))
		{
			QString val=atribbutes.value("TYPE").toString();
			if (val=="PAUSE_ALL")
			{
				type=SchedulerTask::PAUSE_ALL;
			}
			else if (val=="START_ALL")
			{
				type=SchedulerTask::START_ALL;
			}
			else if (val=="LIMIT_DL")
			{
				type=SchedulerTask::LIMIT_DOWNLOAD;
			}
			else if (val=="LIMIT_UL")
			{
				type=SchedulerTask::LIMIT_UPLOAD;
			}
			else 
			{
				//qDebug() << "Unknown type " << val;
			}
		}
		if (atribbutes.hasAttribute("NAME"))
		{
			name=atribbutes.value("NAME").toString();
			
		}
		if (atribbutes.hasAttribute("LIMIT"))
		{
			QString val=atribbutes.value("LIMIT").toString();
			limit=val.toInt();
			
		}
		if (atribbutes.hasAttribute("TBEGIN"))
		{
			QString val=atribbutes.value("TBEGIN").toString();
			begin = QDateTime::fromString(val,"dd:MM:yyyy hh:mm:ss");
			
		}
		if (atribbutes.hasAttribute("TEND"))
		{
			QString val=atribbutes.value("TEND").toString();
			end = QDateTime::fromString(val,"dd:MM:yyyy hh:mm:ss");
		
		}

		SchedulerTask task(name,type,qVariantFromValue(limit),begin);
		res.push_back(task);
	}
	if (xml.hasError()) 
	{
		//qDebug() << xml.errorString();	
	}
	file.close();
	return res;
}

void QApplicationSettings::SaveSchedullerQueue( QList<SchedulerTask> &tasks)
{
	QFile file("CT_DATA/schedulertasks.xml");
	if (!file.open(QFile::WriteOnly))
	{
		QMessageBox::warning(NULL,"","Error open fro writing CT_DATA/schedulertasks.xml");
		return;
	}
	QXmlStreamWriter xml(&file);
	xml.setAutoFormatting(true);
	xml.writeStartDocument();
	//qDebug() << tasks.count();
	qSort(tasks);
	xml.writeStartElement("tasks");
	for (QQueue<SchedulerTask>::iterator i = tasks.begin();i!=tasks.end();i++)
	{
		xml.writeStartElement("task");
		//qDebug() << i->startTime().toString("dd:MM:yyyy hh:mm:ss");
		xml.writeAttribute("TYPE", StaticHelpers::SchedulerTypeToString(i->type()));
		xml.writeAttribute("NAME", i->name());
		xml.writeAttribute("LIMIT", QString::number(i->limit()));
		xml.writeAttribute("TBEGIN", i->startTime().toString("dd:MM:yyyy hh:mm:ss"));
		xml.writeEndElement(); // bookmark
	}
	xml.writeEndElement(); 
	xml.writeEndDocument();
	file.close();
}

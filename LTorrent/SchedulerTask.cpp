#include "SchedulerTask.h"
#include "TorrentManager.h"
#include <QDebug>
SchedulerTask::SchedulerTask(QString name, TaskType type,QVariant limit,QDateTime begin,QObject* parent /*= 0*/) : QThread(parent)
{
	_name=name;
	iType=type;
	bool ok;
	if (type == LIMIT_DOWNLOAD || type == LIMIT_UPLOAD)
	{	_limit=limit.toInt(&ok);
		if (!ok)
		{
			//qDebug() << "Unable to get limit value";
		}
	}
	_begin=begin;
	
}

SchedulerTask::SchedulerTask( const SchedulerTask &other )
{
	iType=other.iType;
	_name  = other._name;
	_limit = other._limit;
	_begin = other._begin;
	
}
SchedulerTask::SchedulerTask()
{
	iType = UNKNOWN;
}

void SchedulerTask::run()
{

	
}

SchedulerTask::TaskType SchedulerTask::type() const
{
	return iType;
}

void SchedulerTask::pefromTask()
{
	//qDebug() << "Starting task" << _name;
	TorrentManager* tManager = TorrentManager::getInstance();
	//qDebug() << "TorrentManager::getInstance()";
	libtorrent::session_settings current=tManager->readSettings();
	//qDebug() << "tManager->readSettings()";
	switch(iType)
	{
	case START_ALL		:
		//qDebug() <<"[Task]"<< _name << QDateTime::currentDateTime()<< _begin << "Starting all torrents";
		tManager->StartAllTorrents();
		break;
	case PAUSE_ALL		:
		//qDebug() <<"[Task]"<< _name << QDateTime::currentDateTime()<< _begin << "Pausing all torrents";
		tManager->PauseAllTorrents();
		break;
	case LIMIT_UPLOAD	:
		{
			//qDebug() <<"[Task]"<< _name << QDateTime::currentDateTime()<< _begin << "Updating upload limit to " << _limit;
			current.upload_rate_limit=_limit;
			tManager->updateSettings(current);
		}
		break;
	case LIMIT_DOWNLOAD	:
		{
			//qDebug() <<"[Task]"<< _name << QDateTime::currentDateTime()<< _begin << "Updating download limit to " << _limit;
			current.download_rate_limit=_limit;
			tManager->updateSettings(current);
		}
		break;
	default:
		//qDebug() << "Unknown type of task";
		break;
	}
	TorrentManager::freeInstance();
}

bool SchedulerTask::operator<( const SchedulerTask &other ) const
{
	return _begin < other.startTime();
}

QDateTime SchedulerTask::startTime() const
{
	return _begin;
}


int SchedulerTask::limit()
{
	return _limit;
}

SchedulerTask& SchedulerTask::operator=( const SchedulerTask& other )
{
	if (this==&other)
	{
		return *this;
	}
	iType=other.iType;
	_name  = other._name;
	_limit = other._limit;
	_begin = other._begin;
	return *this;
	
}

QString SchedulerTask::name() const
{
	return _name;
}

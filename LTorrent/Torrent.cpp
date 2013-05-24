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
#include "Torrent.h"
#include <QStringList>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QMap>
#include <QFileInfo>
#include <vector>
#include <QDebug>
bool Torrent::hasError() const
{
	try
	{
		QString errorString="";
		bool hasErr=false;
		if (cur_torrent.status(torrent_handle::query_accurate_download_counters).error.length()>0)
		{
			hasErr=true;
		}
		const std::vector<announce_entry> trackers=cur_torrent.trackers();
		for (int i=0;i<trackers.size();i++)
		{
			if (trackers[i].message.length()>0)
			{	
				hasErr=true;
			}
		}
		return hasErr;
	}
	catch (...)
	{
		
	}
	return false;
}
std::vector<peer_info> Torrent::GetPeerInfo()
{
	std::vector<peer_info> pInfo;
	try
	{
		if (cur_torrent.is_valid())
				cur_torrent.get_peer_info(pInfo);
	}
	catch (...)
	{

	}	
	return pInfo;
}
std::vector<announce_entry> Torrent::GetTrackerInfo()
{
	std::vector<announce_entry> trackers;
	try
	{
		trackers=cur_torrent.trackers();
	}
	catch (...)
	{

	}
	return trackers;
}
QString Torrent::GetErrorMessage() const
{

	try
	{
		QString errorString="";
		if (cur_torrent.status().error.length()>0)
		{
			errorString.append(QString::fromLocal8Bit(cur_torrent.status().error.c_str())); 
			errorString.append("\n"); 
		}
		const std::vector<announce_entry> trackers=cur_torrent.trackers();
		for (int i=0;i<trackers.size();i++)
		{
			if (trackers[i].message.length()>0)
			{
				errorString.append(QString::fromLocal8Bit(trackers[i].message.c_str())); 
				errorString.append("\n"); 
			}
		}		
		return errorString;
	}
	catch (...)
	{

	}
	return "";
}
bool Torrent::hasMetadata() const
{
	try
	{
		return cur_torrent.has_metadata();
	}
	catch (...)
	{

	}
	return false;
}
bool Torrent::isDownloading() const
{
	try
	{
		return cur_torrent.status().state>=2 && cur_torrent.status().state<=3;
	}
	catch (...)
	{

	}
	return false;
}
bool Torrent::isPaused() const
{
	try
	{
		if (!m_stoped)
			return cur_torrent.is_paused();
	}
	catch (...)
	{

	}
	return false;
}
bool Torrent::isSeeding() const
{
	try
{
	if (cur_torrent.status().state==4) return true;
		return cur_torrent.is_seed();
	}	catch (...)
	{

	}
	return false;
}
int Torrent::GetProgress() const
{


	try
	{
		return cur_torrent.status().progress_ppm / 10000.f;
	}
	catch (...)
	{

	}
	return 0;

}
QString Torrent::GetSuffix()
{
	return base_suffix;
}
QStringList& Torrent::GetImageFiles()
{
	imageFiles.clear();
	file_storage storrgae=cur_torrent.get_torrent_info().files();
	libtorrent::file_storage::iterator bg=storrgae.begin(),
		end=storrgae.end();
	
	for (libtorrent::file_storage::iterator i=bg;i!=end;i++)
	{
		QFileInfo curfile(QString::fromUtf8(storrgae.file_path(*i).c_str()));
		if (cur_torrent.file_priority(storrgae.file_index(*i)) > 0 && StaticHelpers::suffixes[StaticHelpers::DISK].contains(curfile.suffix().toLower()) )
		{
			imageFiles << QString::fromUtf8(cur_torrent.save_path().c_str())+QString::fromUtf8(storrgae.file_path(*i).c_str());
		}
	}
	return imageFiles;
}
Torrent::Torrent(libtorrent::torrent_handle torrentStatus) 
	: mountable(false) , m_hasMedia(false) , cur_torrent(torrentStatus) , size(0) , m_stoped(false)
{
	file_storage storrgae=cur_torrent.get_torrent_info().files();
	libtorrent::file_storage::iterator bg=storrgae.begin(),
		end=storrgae.end();
	StaticHelpers::guessMimeIcon("");
	for (libtorrent::file_storage::iterator i=bg;i!=end;i++)
	{
		QFileInfo curfile(QString::fromUtf8(storrgae.file_path(*i).c_str()));
		if (cur_torrent.file_priority(storrgae.file_index(*i)) > 0 && StaticHelpers::suffixes[StaticHelpers::DISK].contains(curfile.suffix().toLower()))
		{
			imageFiles << QString::fromUtf8(cur_torrent.save_path().c_str())+QString::fromUtf8(storrgae.file_path(*i).c_str());
		}
		if (cur_torrent.file_priority(storrgae.file_index(*i)) > 0)
		{
			if (StaticHelpers::suffixes[StaticHelpers::VIDEO].contains(curfile.suffix().toLower()) || StaticHelpers::suffixes[StaticHelpers::AUDIO].contains(curfile.suffix().toLower()))
				m_hasMedia=true;
			size+=storrgae.file_size(*i);
		}
	}
	
	base_suffix=StaticHelpers::GetBaseSuffix(storrgae);
	//qDebug() << base_suffix << GetName();
	if (!base_suffix.isEmpty())
	{
				
		icon=StaticHelpers::guessMimeIcon(base_suffix);
	}
	else
	{
		icon = QIcon(":/icons/my-folder.ico");
	}
}
bool Torrent::isDaemonToolsMountable()
{
	return imageFiles.length() > 0;
}
QString Torrent::GetProgresString() const
{
	try
	{
		return QString::number(cur_torrent.status().progress_ppm / 10000.f ,'f',2)+"%";
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetStatusString() const
{
	QStringList state_str;
	
	state_str << (QT_TR_NOOP("STATE_FILE_CHEACKING (q)")) 
			  << (QT_TR_NOOP("STATE_FILE_CHEACKING")) 
			  << (QT_TR_NOOP("STATE_DOWNLOADING")) 
			  << (QT_TR_NOOP("STATE_DOWNLOADING")) 
			  << (QT_TR_NOOP("STATE_SEEDING")) 
			  << (QT_TR_NOOP("STATE_SEEDING"))
			  << (QT_TR_NOOP("STATE_PREPARING")) 
			  << (QT_TR_NOOP("STATE_FILE_CHEACKING (r)"));

	try
	{
		return tr(state_str.at(cur_torrent.status().state).toAscii().data()) + (cur_torrent.is_sequential_download() ? (" [S]"):"");
	}
	catch (...)
	{

	}
	return "";

}
QString Torrent::GetHashString() const
{

	
	try
	{
		return to_hex(cur_torrent.info_hash().to_string()).c_str();
	}
	catch (...)
	{

	}
	return "";
}

QString Torrent::GetName() const
{
	try
	{
		if (cur_torrent.is_valid())
				return QString::fromUtf8(cur_torrent.name().c_str());
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetDwonloadSpeed()
{
	try
	{
		return (cur_torrent.status().download_rate > 2*1024 ) ? StaticHelpers::toKbMbGb(cur_torrent.status().download_rate)+"\\s" : "";
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetDwonloadSpeed() const
{
	try
	{
		return (cur_torrent.status().download_rate > 2*1024 ) ? StaticHelpers::toKbMbGb(cur_torrent.status().download_rate)+"\\s" : "";
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetUploadSpeed()
{
	try
	{
		return (cur_torrent.status().upload_rate > 2*1024) ? StaticHelpers::toKbMbGb(cur_torrent.status().upload_rate)+"\\s" : "";
	}
	catch (...)
	{

	}
	return "";
}

QString Torrent::GetUploadSpeed() const
{
	try
	{
		return (cur_torrent.status().upload_rate > 2*1024) ? StaticHelpers::toKbMbGb(cur_torrent.status().upload_rate)+"\\s" : "";
	}
	catch (...)
	{

	}
	return "";
}
int Torrent::GetPeerCount()
{
	try
	{
		return cur_torrent.status().num_peers;
	}
	catch (...)
	{

	}
	return 0;
}
int Torrent::GetActivePeerCount()
{
	try
	{
		return cur_torrent.status().num_seeds;
	}
	catch (...)
	{

	}
	return 0;
}
QIcon Torrent::GetMimeTypeIcon() const
{

	return icon;
}
QIcon Torrent::GetMimeTypeIcon()
{

	return icon;
}

void Torrent::announceRehash()
{
	try
	{
		cur_torrent.force_recheck();
	}
	catch (...)
	{

	}
}
bool Torrent::isSquential() const
{
	try
	{
		return cur_torrent.is_sequential_download();
	}
	catch (...)
	{

	}
	return false;
}
void Torrent::seqensialDownload()
{
	try
	{
		cur_torrent.set_sequential_download(!cur_torrent.is_sequential_download());
	}
	catch (...)
	{

	}

}

void Torrent::RemoveTorrent(TorrentManager *mgr,bool delfiles)
{
	//qDebug() << "Torrent::RemoveTorrent " << cur_torrent.name().c_str();
	mgr->RemoveTorrent(cur_torrent,delfiles);
}
void Torrent::pause()
{
	try
	{
		if (!m_stoped)
		{
			cur_torrent.auto_managed(false);
			cur_torrent.pause();
		}
		
	}
	catch (...)
	{

	}
}
void Torrent::resume()
{
	
	try
	{
		cur_torrent.resume();
		m_stoped=false;
	}
	catch (...)
	{

	}
}
QString Torrent::GetSavePath()
{
	try
	{
		return QString::fromUtf8(cur_torrent.save_path().c_str())/*+GetName()*/;
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetTotalUploaded() const
{
	try
	{
		return StaticHelpers::toKbMbGb(cur_torrent.status().all_time_upload);
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetTotalDownloaded() const
{
	try
	{
		return StaticHelpers::toKbMbGb(cur_torrent.status(torrent_handle::query_accurate_download_counters).all_time_download);
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetActiveTime()
{
	try
	{
		return StaticHelpers::toTimeString(cur_torrent.status(torrent_handle::query_accurate_download_counters).active_time);
	}
	catch (...)
	{

	}
	return "";
}

QString Torrent::GetTotalSize() const
{
	try
	{
		return StaticHelpers::toKbMbGb(size);
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetSeedString()
{
	try
	{
		return QObject::tr("CT_CONNECTED %1 CT_FROM %2").arg(cur_torrent.status(torrent_handle::query_accurate_download_counters).num_seeds).arg(cur_torrent.status(torrent_handle::query_accurate_download_counters).list_seeds);
	}
	catch (...)
	{

	}
	return "";
}
QString Torrent::GetPeerString()
{
	try
	{
		return QObject::tr("CT_CONNECTED %1 CT_FROM %2").arg(cur_torrent.status(torrent_handle::query_accurate_download_counters).num_peers).arg(cur_torrent.status(torrent_handle::query_accurate_download_counters).list_peers);
	}
	catch (...)
	{

	}
	return "";
}

QString Torrent::GetRemainingTime()
{
	QString res;
	try
	{
		if (isSeeding() || isPaused())
			{
				res.append(QChar(8734));
				return res;
			}
			if (cur_torrent.status(torrent_handle::query_accurate_download_counters).download_rate < 1024*10)
				res.append(QChar(8734));
			else
			{
				int time=(cur_torrent.get_torrent_info().total_size()-cur_torrent.status(torrent_handle::query_accurate_download_counters).all_time_download) / cur_torrent.status(torrent_handle::query_accurate_download_counters).download_rate;
				res = StaticHelpers::toTimeString(time);
			}
	}	
	catch (...)
	{

	}
	return res;
}

QList<file_info> Torrent::GetFileDownloadInfo()
{
	QList<file_info> res;
	try
	{
		torrent_info ti=cur_torrent.get_torrent_info();
		file_storage storage=ti.files();
		std::vector<float> progresses;
		cur_torrent.file_progress(progresses);
		int counter=0;
		for (file_storage::iterator i=storage.begin();i!=storage.end();i++)
		{
			file_info current;
			current.name=storage.file_path(*i).c_str();
			current.index=storage.file_index(*i);
			current.prioiry = cur_torrent.file_priority(current.index);
			current.progrss =progresses[counter]*100.f;
			current.size = storage.file_size(*i);
			res.append(current);
			counter++;
		}
		progresses.~vector();
	}
	catch (...)
	{

	}
	return res;
}
void Torrent::SetFilePriority(int index,int prioryty)
{
	try
	{
		
		cur_torrent.file_priority(index,prioryty);
	}
	catch (...)
	{
		
	}
	
	
}

void Torrent::updateTrackers()
{
	try
	{
		cur_torrent.force_reannounce();
	}
	catch (...)
	{
		
	}
	
}

void Torrent::MoveStorrage( QString path )
{
	try
	{
		cur_torrent.move_storage(path.toStdString());
	}
	catch (...)
	{
		
	}
	
}

int Torrent::GetPieceCount()
{
	try
	{
		return cur_torrent.get_torrent_info().num_pieces();
	}
	catch (...)
	{
	}
	return 0;
}

QVector<int> Torrent::GetDownloadedPieces()
{
	QVector<int> res;
	try
	{
		int max_num=cur_torrent.get_torrent_info().num_pieces();
		for (int i=0;i<max_num;i++)
		{
			if (cur_torrent.have_piece(i))
				res.append(i);
		}
		
		
	}
	catch (...)
	{

	}
	return res;
	
}

QVector<int> Torrent::GetDownloadingPieces()
{
	QVector<int> res;
	try
	{
		
		std::vector<partial_piece_info> pieces;
		cur_torrent.get_download_queue(pieces);
		for (std::vector<partial_piece_info>::iterator i=pieces.begin();i!=pieces.end();i++)
		{
			if (i->finished+i->writing > 0)
			{
				res.append(i->piece_index);
			}
		}

	}
	catch (...)
	{

	}
	return res;
}

QString Torrent::GetDiscribtion()
{
	try
	{
		return QString::fromStdString(cur_torrent.get_torrent_info().comment());
	}
	catch (...)
	{
		
	}
	return "";
}

void Torrent::SetUlLimit( int val )
{
	//qDebug() << "Torrent::SetUlLimit" << val;
	try
	{

		cur_torrent.set_upload_limit(val);
	}
	catch (...)
	{
		
	}
	
}

void Torrent::SetDlLimit( int val )
{
	//qDebug() << "Torrent::SetDlLimit" << val;
	try
	{
		cur_torrent.set_download_limit(val);
	}
	catch (...)
	{

	}
}

int Torrent::GetDownloadLimit()
{
	try
	{
		return cur_torrent.download_limit();
	}
	catch (...)
	{

	}
	return 0;
}

int Torrent::GetUploadLimit()
{
	try
	{
		return cur_torrent.upload_limit();
	}
	catch (...)
	{

	}
	return 0;
}
bool Torrent::hasMediaFiles()
{
	return m_hasMedia;
}

void Torrent::AddPeer( QHostAddress adr,short port )
{
	tcp::endpoint ep(boost::asio::ip::address_v4(adr.toIPv4Address()),port);
	cur_torrent.connect_peer(ep);
}

void Torrent::AddTracker( QString url )
{
	
	cur_torrent.add_tracker(url.toStdString());
}

void Torrent::stop()
{
	cur_torrent.auto_managed(false);
	cur_torrent.pause(torrent_handle::graceful_pause);
	m_stoped=true;
}

bool Torrent::isStoped() const
{
	return m_stoped;
}

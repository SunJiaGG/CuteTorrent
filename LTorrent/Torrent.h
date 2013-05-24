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
#ifndef _TOR_H
#define _TOR_H
#include "TorrentManager.h"
#include "StaticHelpers.h"
#include <QString>
#include <QStringList>
#include <QIcon>
#include <QList>
#include <QVector>
#include <QFileIconProvider>
#include <QMessageBox>
#include <QHostAddress>
class TorrentManager;
class StaticHelpers;
#include "defs.h"
class Torrent : public QObject
{
	Q_OBJECT
		
private:
	bool m_hasMedia,m_stoped;
	StaticHelpers* helper;
	torrent_handle cur_torrent;
	libtorrent::size_type size;
	QIcon icon;
	QString ErrorString;
	bool mountable;
	QString base_suffix;
	QStringList imageFiles;
	bool prevHaserror,prevIsCompleted;
public :

	Torrent::Torrent(const Torrent &): QObject(0){};
	Torrent(): QObject(0){};
	~Torrent() {};
	void SetFilePriority(int index,int prioryty);
	QString GetRemainingTime();
	QStringList& GetImageFiles();
	QString GetSuffix();
	QString GetErrorMessage() const;
  	Torrent(torrent_handle torrentStatus);
	QString GetDwonloadSpeed();
	QString GetUploadSpeed();
	QString GetSavePath();
	QString GetTotalUploaded() const;
	QString GetTotalDownloaded() const;
	QString GetActiveTime();
	QString GetTotalSize() const;
	QString GetSeedString();
	QString GetPeerString();
	QString GetName() const;
	QString GetDiscribtion();
	QString GetHashString() const;
	int GetProgress() const;
	int GetPeerCount();
	int GetActivePeerCount();
	QIcon GetMimeTypeIcon() const;
	QIcon GetMimeTypeIcon();
	QList<file_info> GetFileDownloadInfo();
	bool isPaused() const;
	bool isSeeding() const;
	bool isStoped() const;
	bool hasMetadata() const;
	bool isDownloading() const;
	bool isDaemonToolsMountable();
	bool isSquential() const;
	bool hasError() const;	
	bool hasMediaFiles();
	int GetPieceCount();
	QVector<int> GetDownloadedPieces();
	QVector<int> GetDownloadingPieces();
	QString GetStatusString() const;
	QString GetProgresString() const;
	QString GetDwonloadSpeed() const;
	QString GetUploadSpeed() const;
	void RemoveTorrent(TorrentManager* mgr,bool delfiles=false);
	std::vector<peer_info> GetPeerInfo();
	std::vector<announce_entry> GetTrackerInfo();
	void announceRehash();
	void updateTrackers();
	void seqensialDownload();
	void pause();
	void stop();
	void resume();
	void MoveStorrage(QString path);
	void AddTracker(QString url);
	void AddPeer(QHostAddress adr,short port);
	void SetUlLimit(int val);
	void SetDlLimit(int val);
	int GetDownloadLimit();
	int GetUploadLimit();

};

//Q_DECLARE_METATYPE(Torrent)
Q_DECLARE_METATYPE(Torrent*)

#endif
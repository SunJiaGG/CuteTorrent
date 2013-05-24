#ifndef _DEFS_H
#define _DEFS_H


#define BOOST_ASIO_SEPARATE_COMPILATION
#include "libtorrent/config.hpp"
#include "libtorrent/file_storage.hpp"
#include "libtorrent/torrent_handle.hpp"
using namespace libtorrent;
struct opentorrent_info
{
	QString name,describtion,base_suffix;
	libtorrent::file_storage files;
	libtorrent::size_type size;
};
struct openmagnet_info
{
	QString name,describtion,base_suffix;
	libtorrent::torrent_handle handle;
	libtorrent::file_storage files;
	libtorrent::size_type size;
};

enum torrent_filter
{
	active=0,stopped=1,compled=2,seeding=3

};



struct torrent_creation_info
{
	std::string path,filter,describtion;
	std::vector<std::string> web_seeds;
	std::vector<std::string> trackers;
	quint64 pice_size;
	bool _private, startSeed, saveFileOrder;


};

struct file_info 
{
	QString name;
	size_type size;
	float progrss;
	int prioiry;
	int index;
};

enum RconMessageType
{
	LOGIN,
	ADD_TORRENT,
	PAUSE_TORRENT,
	REMOVE_TORRENT_ONLY,
	REMOVE_TORRENT_WITH_DATA,
	SET_DOWNLOAD_LIMIT,
	SET_UPLOAD_LIMIT,
	SET_GLOBAL_DOWNLOAD_LIMIT,
	SET_GLOBAL_UPLOAD_LIMIT,
	SET_SETTINGS_VALUE,
	LOGOUT
};

#endif _DEFS_H
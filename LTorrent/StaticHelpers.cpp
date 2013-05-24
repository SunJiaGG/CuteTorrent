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
#include "CuteTorrent.h"
#include "StaticHelpers.h"
#include <QDebug>


QIcon StaticHelpers::fileIcons[TYPE_COUNT];
QSet<QString> StaticHelpers::suffixes[TYPE_COUNT];

QString StaticHelpers::toKbMbGb(libtorrent::size_type size)
{
	float val=size;
	char* Suffix[] = { " B\0", " KB\0", " MB\0", " GB\0", " TB\0" };
    int i=0;
    float dblSByte=val;
	if (size > 1024)
	for (i ; (libtorrent::size_type)(val / 1024) > 0; i++, val /= 1024)
		dblSByte = val / 1024.f;
	QString str=QString::number(dblSByte,'f',i==0? 0 : 2);
	str.append(Suffix[i]);
	return str;
}

QIcon StaticHelpers::guessMimeIcon(QString suffix)
{
	
	static QIcon fallback;
	
	suffix=suffix.toLower();
	
	if( fileIcons[0].isNull( ) )
	{
	
		fallback = QIcon(QString::fromUtf8(":/icons/my-folder.ico"));
		const char * disk_types[] = {
				"mdx", "mds", "mdf", "iso", "b5t", "b6t", "bwt", "ccd", "cdi",
				"nrg", "pdi", "isz" };
		for( int i=0, n=sizeof(disk_types)/sizeof(disk_types[0]); i<n; ++i )
		{
			suffixes[DISK] << QString::fromAscii(disk_types[i]);
		}
		fileIcons[DISK]= QIcon( ":/icons/my-iso.ico");
	
	    const char * doc_types[] = {
	            "abw", "csv", "doc", "dvi", "htm", "html", "ini", "log", "odp",
	            "ods", "odt", "pdf", "ppt", "ps",  "rtf", "tex", "txt", "xml" };
	    for( int i=0, n=sizeof(doc_types)/sizeof(doc_types[0]); i<n; ++i )
		{
			suffixes[DOCUMENT] << QString::fromAscii(doc_types[i] );
		}
		fileIcons[DOCUMENT] = QIcon( ":/icons/my-doc.ico" );
	
	    const char * pic_types[] = {
	            "bmp", "gif", "jpg", "jpeg", "pcx", "png", "psd", "ras", "tga", "tiff" };
	    for( int i=0, n=sizeof(pic_types)/sizeof(pic_types[0]); i<n; ++i )
		{
			suffixes[PICTURE] << QString::fromAscii(pic_types[i]);
		}
	    fileIcons[PICTURE]  = QIcon( ":/icons/my-picture.ico" );
	
	    const char * vid_types[] = {
	            "3gp", "asf", "avi", "mov", "mpeg", "mpg", "mp4", "mkv", "mov",
	            "ogm", "ogv", "qt", "rm", "wmv" , "m2ts" };
	    for( int i=0, n=sizeof(vid_types)/sizeof(vid_types[0]); i<n; ++i )
		{
			suffixes[VIDEO] << QString::fromAscii(vid_types[i]);
		}
        fileIcons[VIDEO] = QIcon( ":/icons/my-movie.ico") ;

	    const char * arc_types[] = {
	            "7z", "ace", "bz2", "cbz", "gz", "gzip", "lzma", "rar", "sft", "tar", "zip" };
	    for( int i=0, n=sizeof(arc_types)/sizeof(arc_types[0]); i<n; ++i )
		{
			suffixes[ARCHIVE] << QString::fromAscii(arc_types[i]);
		}
        fileIcons[ARCHIVE]  = QIcon( ":/icons/my-archive.ico" );

        const char * aud_types[] = {
	            "aac", "ac3", "aiff", "ape", "au", "flac", "m3u", "m4a", "mid", "midi", "mp2",
	            "mp3", "mpc", "nsf", "oga", "ogg", "ra", "ram", "shn", "voc", "wav", "wma" };
	    for( int i=0, n=sizeof(aud_types)/sizeof(aud_types[0]); i<n; ++i )
		{
			suffixes[AUDIO] << QString::fromAscii(aud_types[i]);
		}
	    fileIcons[AUDIO] = QIcon( ":/icons/my-audio.ico" );
	
	    const char * exe_types[] = { "bat", "cmd", "com", "exe" };
	    for( int i=0, n=sizeof(exe_types)/sizeof(exe_types[0]); i<n; ++i )
		{
			suffixes[APP] << QString::fromAscii(exe_types[i]);
		}
	    fileIcons[APP] = QIcon::fromTheme( "application-x-executable", fallback );
	}
	if (!suffix.isEmpty())
	{
		for( int i=0; i<TYPE_COUNT; ++i )
		{
			if( suffixes[i].contains(suffix))
			{
				return fileIcons[i];
			}
		}
	}
	
	
	return fallback;
}

void StaticHelpers::dellDir(QString dirName)
{
	try
	{
		error_code ec;
		remove_all(dirName.toStdString(),ec);
	}
	catch (...)
	{
		//qDebug() << " exception caught int deldir";
	}
	
	
}
QString StaticHelpers::filePriorityToString(int priority)
{
	static char* priority_str[] = {"FILETAB_PRIORITY_ZERO","FILETAB_PRIORITY_LOW","FILETAB_PRIORITY_MEDIUM","FILETAB_PRIORITY_HIGH"};
	if (priority==0)
		return CuteTorrent::tr(priority_str[0]);
	if (priority < 3)
		return CuteTorrent::tr(priority_str[1]);
	if (priority >=3 && priority < 6)
		return CuteTorrent::tr(priority_str[2]);
	if (priority >=6)
		return CuteTorrent::tr(priority_str[3]);
	return "";
}

QString StaticHelpers::toTimeString( int seconds )
{
	if (seconds<0)
		return "";
	int min=0,hour=0,day=0,Week=0;
	Week = seconds/(7*24*60*60);
	seconds -=Week*(7*24*60*60);
	day = seconds / (24*60*60);
	seconds -=day*(24*60*60);
	hour=seconds / (60*60);
	seconds -=hour*60*60;
	min=seconds/60;
	seconds-=min*60;
	QString result,tmp;

	if (Week>0)
	{
		result.append(QObject::tr("%1 WEEK ").arg(Week));
	}
	if (day>0)
	{
		result.append(QObject::tr("%1 DAY ").arg(day));
	}
	if (hour>=0)
	{
		result.append(tmp.sprintf("%02d:",hour));
	}
	if (min>=0)
	{
		result.append(tmp.sprintf("%02d:",min));
	}
	result.append(tmp.sprintf("%02d",seconds));
	return result;
}

QString StaticHelpers::SchedulerTypeToString( SchedulerTask::TaskType type )
{
	switch (type)
	{
	case SchedulerTask::START_ALL :
		return "START_ALL";
	case SchedulerTask::PAUSE_ALL:
		return "PAUSE_ALL";
	case SchedulerTask::LIMIT_UPLOAD:
		return "LIMIT_UL";
	case SchedulerTask::LIMIT_DOWNLOAD:
		return "LIMIT_DL";
	}
	return "";
}

QString StaticHelpers::GetBaseSuffix( libtorrent::file_storage storrage )
{
	QString base_suffix;
	int maxSuffix=0;
	QMap<QString,int> suffixesCount;
	libtorrent::file_storage::iterator iter=storrage.begin();
	for (iter;iter!=storrage.end();iter++)
	{
		QFileInfo curfile(QString::fromUtf8(storrage.file_path(*iter).c_str()));
		if (suffixes[DISK].contains(curfile.suffix()))
		{
			base_suffix=curfile.suffix();
			break;
		}
		if (suffixes[VIDEO].contains(curfile.suffix()))
		{
			base_suffix=curfile.suffix();
			break;
		}
		if (!suffixesCount.contains(curfile.suffix()))
		{
			suffixesCount.insert(curfile.suffix(),1);
			
		}
		else
		{

			suffixesCount[curfile.suffix()]++;
			
		}
		if (suffixesCount[curfile.suffix()] > maxSuffix)
		{
			maxSuffix=suffixesCount[curfile.suffix()];
			base_suffix=curfile.suffix();
		}

	}
	return base_suffix;
}


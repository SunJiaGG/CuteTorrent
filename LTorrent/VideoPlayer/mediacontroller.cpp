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

#include "mediacontroller.h"

#include <phonon/mediasource.h>
#include <phonon/mediaobject.h>

#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QUrl>
#include <QTimer>
MediaController::MediaController(Phonon::VideoWidget *parent) :
QObject(parent)
{
    m_media = new Phonon::MediaObject(this);
	connect(m_media,SIGNAL(stateChanged(Phonon::State, Phonon::State)),SLOT(updateStateStatus(Phonon::State, Phonon::State)));
	connect(m_media,SIGNAL(aboutToFinish()),SLOT(forvard()));
	m_AudioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
	Phonon::createPath( m_media, m_AudioOutput );
	m_LastDir="";
}

Phonon::MediaObject *MediaController::mediaObject() const
{
    return m_media;
}

void MediaController::openFile()
{
    QString file = QFileDialog::getOpenFileName(0, tr("Open a new file to play"),m_LastDir, "Suported Video Files (*.mkv *.avi *.mp4 *.m2ts *.mpg *.mpeg);;"
																					 "Suported Audio Files (*.mp3 *.aac *.ac3 *.aiff *.flac *.m4a *.mpc *.nsf *.oga *.ogg *.wav *.wma);;"
																					 "Matroska (*.mkv);;"
																					 "Audio Video Interleave (*.avi);;"
																					 "MPEG-4 Video (*.mp4);;"
																					 "MPEG-TS Video (*.m2ts);;"
																					 "MPEG-1 Video (*.mpg *.mpeg);;"
																					 "MPEG-1/2/2.5 Layer 3 (*.mp3);;"
																					 "Advanced Audio Coding (*.aac);;"
																					 "Dolby Digital (*.ac3);;"
																					 "Audio Interchange File Format (*.aiff);;"
																					 "Free Lossless Audio Codec (*.flac);;"
																					 "M4A (*.m4a);;"
																					 "MusePack (*.mpc);;"
																					 "NES Sound Format (*.nsf);;"
																					 "Vorbis Audio (*.oga *.ogg);;"
																					 "Windwos Audio (*.wav *.wma);;"
																					 "Any File (*.*)");
	if (!file.isEmpty()) {
		if (!QFile::exists(file))
			file= m_LastDir + QDir::separator() + file;
		QDir dir=QFileInfo(file).absoluteDir();
		if (m_LastDir != dir.absolutePath())
		{
			m_LastDir = dir.absolutePath();
			QStringList namefilters;
			namefilters << "*.mkv";
			namefilters << "*.avi";
			namefilters << "*.mp4";
			namefilters << "*.m2ts";
			namefilters << "*.mpg";
			namefilters << "*.mpeg";
			namefilters << "*.mp3";
			namefilters << "*.aac";
			namefilters << "*.ac3";
			namefilters << "*.aiff";
			namefilters << "*.flac";
			namefilters << "*.m4a";
			namefilters << "*.mpc";
			namefilters << "*.nsf";
			namefilters << "*.oga";
			namefilters << "*.ogg";
			namefilters << "*.wav";
			namefilters << "*.wma";
			m_playList = dir.entryList(namefilters);
			m_playListPosition = m_playList.indexOf(QFileInfo(file).fileName());
			if (m_playListPosition < 0)
			{
				m_playList=dir.entryList();
				m_playListPosition = m_playList.indexOf(file);
			}
			//qDebug() << m_playListPosition << m_playList;
		}

		Phonon::MediaSource s(file);
		playSource(s);
		emit newFile(QFileInfo(file).fileName());
	}
}

void MediaController::openURL()
{
	bool ok;
	QString url = QInputDialog::getText(NULL, tr("Type an url to play"),
		tr("Mediafile URL:"), QLineEdit::Normal,
		"", &ok);
	if (ok && !url.isEmpty())
	{
		Phonon::MediaSource s(QUrl::fromPercentEncoding(url.toUtf8().data()));
		emit newFile(s.fileName());
		playSource(s);
	}
}

void MediaController::playSource(const Phonon::MediaSource &s)
{
    m_media->setCurrentSource(s);
    m_media->play();
	
	
}

void MediaController::play()
{
	m_media->play();
}

void MediaController::pause()
{
	m_media->pause();
}

Phonon::AudioOutput * MediaController::audioOutput() const
{
	return m_AudioOutput;
}

void MediaController::updateStateStatus( Phonon::State newState, Phonon::State oldState)
{
	Q_UNUSED(oldState)
	if (newState==Phonon::PlayingState)
	{
		m_playing=true;
	}
	else
	{
		m_playing=false;
	}
	if (newState == Phonon::ErrorState)
	  if(m_media->errorType()==Phonon::FatalError)
	  {
		  m_media->play();
		  qobject_cast<Phonon::VideoWidget*>(parent())->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
		  QTimer::singleShot(1000,this,SIGNAL(updateMediaObject()));

	  }
}

void MediaController::playFile( QString file )
{
	if (!file.isEmpty()) {
		if (!QFile::exists(file))
			file= m_LastDir + QDir::separator() + file;
		QDir dir=QFileInfo(file).absoluteDir();
		if (m_LastDir != dir.absolutePath())
		{
			m_LastDir = dir.absolutePath();
			QStringList namefilters;
			namefilters << "*.mkv";
			namefilters << "*.avi";
			namefilters << "*.mp4";
			namefilters << "*.m2ts";
			namefilters << "*.mpg";
			namefilters << "*.mpeg";
			namefilters << "*.mp3";
			namefilters << "*.aac";
			namefilters << "*.ac3";
			namefilters << "*.aiff";
			namefilters << "*.flac";
			namefilters << "*.m4a";
			namefilters << "*.mpc";
			namefilters << "*.nsf";
			namefilters << "*.oga";
			namefilters << "*.ogg";
			namefilters << "*.wav";
			namefilters << "*.wma";
			m_playList = dir.entryList(namefilters);
			m_playListPosition = m_playList.indexOf(QFileInfo(file).fileName());
			if (m_playListPosition < 0)
			{
				m_playList=dir.entryList();
				m_playListPosition = m_playList.indexOf(file);
			}
			//qDebug() << m_playListPosition << m_playList;
		}
		
		Phonon::MediaSource s(file);
		playSource(s);
		emit newFile(QFileInfo(file).fileName());
	}
}

void MediaController::forvard()
{
	//qDebug() << "MediaController::forvard" << m_playListPosition;
	if (m_playListPosition+1 < m_playList.length())
	{
		m_playListPosition++;
	}
	else
	{
		m_playListPosition=0;
	}
	playFile(m_playList[m_playListPosition]);
}

void MediaController::reverse()
{
	//qDebug() << "MediaController::reverse" << m_playListPosition;
	if (m_playListPosition-1 >= 0 )
	{
		m_playListPosition--;
	}
	else
	{
		m_playListPosition=m_playList.length()-1;
	}
	playFile(m_playList[m_playListPosition]);
}

bool MediaController::isPlaying()
{
	return m_playing;
}


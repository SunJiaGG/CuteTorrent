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

#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include <QtCore/QObject>
#include <QStringList>
#include <phonon/AudioOutput>
#include <phonon/VideoWidget>
namespace Phonon
{
class MediaObject;
class MediaSource;

}

class MediaController : public QObject
{
    Q_OBJECT
public:
	explicit MediaController(Phonon::VideoWidget *parent = 0);
    void playFile(QString file);
    Phonon::MediaObject *mediaObject() const;
	Phonon::AudioOutput *audioOutput() const;
	bool isPlaying();
public slots:
	void play();
	void pause();
    void openFile();
    void openURL();
	void reverse();
	void forvard();
	void updateStateStatus(Phonon::State, Phonon::State);
signals:
	void updateMediaObject();
	void newFile(QString);
private:
	QStringList m_playList;
	int m_playListPosition;
	QString m_LastDir;
    Phonon::MediaObject *m_media;
	Phonon::AudioOutput *m_AudioOutput;
	bool m_playing;
	void playSource(const Phonon::MediaSource &);

};

#endif // MEDIACONTROLLER_H

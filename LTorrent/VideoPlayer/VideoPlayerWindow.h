/*
    Copyright (C) 2010 Jean-Baptiste Kempf <jb@videolan.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), Nokia Corporation
    (or its successors, if any) and the KDE Free Qt Foundation, which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#ifndef VideoPlayerWindow_H
#define VideoPlayerWindow_H

#include <QMainWindow>
#include "MediaControls.h"
#include <phonon/audiooutput.h>
namespace Phonon { class VideoWidget; }
class MediaController;

class VideoPlayerWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit VideoPlayerWindow(QWidget *parent = 0);
	void openFile(QString path);
signals:

public slots:
	void goFullScreen();

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void timerEvent(QTimerEvent * event);
  	void resizeEvent(QResizeEvent* event);
	bool eventFilter(QObject *src, QEvent *event);
	void keyPressEvent(QKeyEvent *keyEvent);
private:
	bool isFullScr;
	MediaControls* controls;
    MediaController *m_mediaControl;
    Phonon::VideoWidget *m_videoWidget;
	int animationTimerID;

};

#endif // VideoPlayerWindow_H

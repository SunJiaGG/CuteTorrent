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

#include "VideoPlayerWindow.h"
#include "mediacontroller.h"


#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include <phonon/VideoWidget>


#include <QContextMenuEvent>
#include <QFileDialog>
#include <QMenu>

VideoPlayerWindow::VideoPlayerWindow(QWidget *parent) :
QMainWindow(parent),isFullScr(false)
{
	try
	{
	
		m_videoWidget = new Phonon::VideoWidget();
		setCentralWidget(m_videoWidget);
		m_mediaControl = new MediaController(m_videoWidget);
		Phonon::createPath(m_mediaControl->mediaObject(), m_videoWidget);
		
		controls = new MediaControls(m_mediaControl,m_videoWidget);
				
		setWindowIcon(QIcon(":/icons/app.ico"));
			
		QObject::connect(controls,SIGNAL(play()),m_mediaControl,SLOT(play()));
		QObject::connect(controls,SIGNAL(pause()),m_mediaControl,SLOT(pause()));
		QObject::connect(controls,SIGNAL(openFile()),m_mediaControl,SLOT(openFile()));
		QObject::connect(controls,SIGNAL(openURL()),m_mediaControl,SLOT(openURL()));
		QObject::connect(controls,SIGNAL(forvard()),m_mediaControl,SLOT(forvard()));
		QObject::connect(controls,SIGNAL(reverse()),m_mediaControl,SLOT(reverse()));
		QObject::connect(controls,SIGNAL(toggleFullScreen()),this,SLOT(goFullScreen()));
		QObject::connect(m_mediaControl,SIGNAL(newFile(QString)),this,SLOT(setWindowTitle(QString)));
		QObject::connect(m_mediaControl,SIGNAL(updateMediaObject()),controls,SLOT(updateMedaiObject()));

		setAttribute(Qt::WA_DeleteOnClose);
		setMouseTracking(true);
		resize(600, 400);
		m_videoWidget->installEventFilter(this);
		m_videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
		controls->move((m_videoWidget->width()-controls->width())/2,m_videoWidget->height()-controls->height());
	}
	catch (...)
	{
		QMessageBox::warning(this,"Exception","VideoPlayerWindow::VideoPlayerWindow()\n");
	}
}


void VideoPlayerWindow::resizeEvent( QResizeEvent* event )
{
	controls->move(QPoint((event->size().width()-controls->width())/2,event->size().height()-controls->height()));
	
	QWidget::resizeEvent(event);
}

bool VideoPlayerWindow::eventFilter( QObject *src, QEvent *event )
{
	if(src==m_videoWidget && event->type()==QEvent::MouseButtonDblClick )
	{
		goFullScreen();
		return true;
	}
	return false;
}

void VideoPlayerWindow::goFullScreen()
{
	isFullScr=!isFullScr;
	Qt::WindowFlags flags = windowFlags();
	if (isFullScr) {
		if (!isFullScreen()) {
			//we only update that value if it is not already fullscreen
			
		
#ifdef Q_WS_X11
			// This works around a bug with Compiz
			// as the window must be visible before we can set the state
			show();
			raise();
			setWindowState( windowState() | Qt::WindowFullScreen ); // set
#else
			setWindowState( windowState() | Qt::WindowFullScreen ); // set
			show();
#endif
		}
	} else if (isFullScreen()) {
		setWindowState( windowState()  ^ Qt::WindowFullScreen ); // reset
		show();
	}
	controls->move(QPoint((m_videoWidget->width()-controls->width())/2,m_videoWidget->height()-controls->height()));
}

void VideoPlayerWindow::openFile( QString path )
{
	try
	{
		m_mediaControl->playFile(path);
	}
	catch (...)
	{
		QMessageBox::warning(this,"ERROR","VideoPlayerWindow::openFile()");
	}
	
}

void VideoPlayerWindow::mouseMoveEvent( QMouseEvent *event )
{
	controls->show();
	animationTimerID=startTimer(3000);
}

void VideoPlayerWindow::timerEvent( QTimerEvent * event )
{
	if (event->timerId()==animationTimerID)
	{
		killTimer(animationTimerID);
		controls->hide();
	}
}

void VideoPlayerWindow::keyPressEvent( QKeyEvent *keyEvent )
{
	if (keyEvent->key()==Qt::Key_Space)
	{
		if (m_mediaControl->isPlaying())
		{
			m_mediaControl->pause();
		}
		else
		{
			m_mediaControl->play();
		}
	}
}








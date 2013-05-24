/*
CuteTorrent BitTorrent Client with dht support, userfriendly interface
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
#ifndef LTORRENT_H
#define LTORRENT_H

#include <QtGui/QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSpinBox>
#include <QString>
#include <QTimer>
#include "ui_CuteTorrent.h"
#include "SettingsDialog.h"
#include "TorrentManager.h"
#include "FileTabelModel.h"
#include "CreateTorrentDilaog.h"
#include "OpenTorrentDialog.h"
#include "QTorrentDisplayModel.h"
#include "QTorrentItemDelegat.h"
#include <qtsingleapplication.h>
#include <QSystemTrayIcon>
#include <QEvent>
#include <QCloseEvent>
#include "QTorrentListView.h"
#include "UpdateNotyfier.h"
#include <QMutex>
#include <QtNetwork/QHostAddress>
#include <QScrollBar>
Q_DECLARE_METATYPE(QHostAddress)
class CuteTorrent : public QMainWindow , private Ui::CuteTorrentClass
{
	Q_OBJECT

public:
	CuteTorrent(QWidget *parent = 0, Qt::WFlags flags = 0);

	

	void ConnectMessageReceved(QtSingleApplication* a);
	
    ~CuteTorrent();
protected:
	
	void changeEvent(QEvent *event);
	void resizeEvent ( QResizeEvent * event );
	void closeEvent(QCloseEvent* ce);
	void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
	void keyPressEvent ( QKeyEvent * event );
private:
	int  m_nMouseClick_X_Coordinate;
	int  m_nMouseClick_Y_Coordinate;
	QMutex* fileinfosLocker;
	QList<file_info> file_infos;
	UpdateNotifier* notyfire;
	bool mayShowNotifies;
	QSystemTrayIcon *trayIcon;
	QSpinBox* ul,*dl;
	QMenu *trayIconMenu;
	QAction* minimizeAction;
    QAction* maximizeAction;
    QAction* restoreAction;
    QAction* quitAction;
	QAction* copyContext;
	QAction* addPeer,* addTracker;
	QLabel *upLabelText, *upLabel;
	QLabel *uploadLimit, *downloadLimit;
	QLabel* downLabelText, *downLabel;
	FileTabelModel* fModel;
	QTorrentDisplayModel* model;
	TorrentManager* mng;
	QTimer *timer;
	QMenu* fileTabMenu;
	QAction* openFile;
	QAction* openDir;
	QMenu* priority;
	QAction* lowPriority;
	QAction* mediumPriority;
	QAction* highPriority;
	QAction* dontDownload;
	QLineEdit* searchEdit;
	void createTrayIcon();
	void createActions();
	void setupTray();
	void setupToolBar();
	void setupConnections();
	void setupListView();
	void setupTabelWidgets();
	void setupStatusBar();
	void setupFileTabel();
	void setupFileTabelContextMenu();
	void fillPieceDisplay();
public slots:
	void HandleNewTorrent(const QString &);
private slots:
	void UpdateUL(int);
	void UpdateDL(int);
	void OpenFileSelected();
	void OpenDirSelected();
	void setLowForCurrentFile();
	void setMediumForCurrentFile();
	void setHighForCurrentFile();
	void setNotDownloadForCurrentFile();
	void fileTabContextMenu(const QPoint &);
	void ShowAbout();
	void checkForUpdates();
	void ShowUpdateNitify(const QString&);
	void ShowNoUpdateNitify(const QString&);
	void retranslate();
	void ShowTorrentError(const QString&,const QString&);
	void enableNitifyShow();
	void showTorrentCompletedNotyfy(const QString,const QString);
	void showTorrentInfoNotyfy(const QString,const QString);
	void ShowCreateTorrentDialog();
	void ShowOpenTorrentDialog();
	void PauseSelected();
	void StopSelected();
	void ResumeSelected();
	void DeleteSelected();
	void UpdateInfoTab();
	void UpdatePeerTab();
	void UpdateFileTab();
	void UpadteTrackerTab();
	void OpenSettingsDialog();
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void updateTabWidget(int);
	void ProcessMagnet();
	void peformSearch();
	void copyDiscribtion();
	void clearPieceDisplay();
	void updateItemWidth(int,int);
	void AddTracker();
	void AddPeer();
	
};

#endif // LTORRENT_H

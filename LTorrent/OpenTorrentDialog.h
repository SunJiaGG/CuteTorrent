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
#ifndef OTD_H
#define OTD_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include "ui_OpenTorrentDialog.h"
#include "TorrentManager.h"
#include "StaticHelpers.h"
#include "FileTreeModel.h"
#include "MetaDataDownloadWaiter.h"

class OpenTorrentDialog : public QDialog , private Ui::OpenTorrentDialog
{
	Q_OBJECT

public:
	OpenTorrentDialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~OpenTorrentDialog();
	void SetData(QString filename);
	
	int execConditional();
private:
	QList<GroupForFileFiltering> filters;
	bool validTorrent;
	TorrentManager* mgr;
	QString torrentFilename;
	openmagnet_info _info;
	FileTreeModel* model;
	void setupGroupComboBox();
private slots:
    virtual void reject();
	void BrowseButton();
	void AccepTorrent();
	void ChangeGroup();
	void DownloadMetadataCompleted(openmagnet_info);
};
#endif

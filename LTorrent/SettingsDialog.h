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
#include <QDialog>
#include "ui_SettingsDialog.h"
#include "QApplicationSettings.h"
#include "GroupForFileFiltering.h"
class SettingsDialog : public QDialog , private Ui::SettingsDialog
{
	Q_OBJECT
private:
	QApplicationSettings* settings;
	QList<GroupForFileFiltering> filterGroups;
	QList<SchedulerTask> tasks;
	QDateTimeEdit* previousFocuse;
	void FillFilteringGroups();
	void FillTorrentTab();
	void FillHDDTab();
	void FillDTTab();
	void FillWebUITab();
	void SetupSchedullerTab();
public:
 	SettingsDialog(QWidget* parent=0,int flags=0);
	~SettingsDialog();
	void ApplySettingsToSession();
signals:
	void needRetranslate();
	void tasksChanged();
private slots:
	void ApplyAndClose();
	void ApplySettings();
	void addGroup();
	void removeGroup();
	void browseSavepathGroup();
	void browseDTPath();
	void showSelectedGroup(int);
	void SetDate(QDate date);
	void AddTask();
	void DeleteTask();
	void UpdateSchedullerTab( int index );
};
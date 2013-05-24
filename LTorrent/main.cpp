/*
CuteTorrent BitTorrent Client with dht support, user friendly interface
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

//#define DEBUG
#include "CuteTorrent.h"
#include <QDir>
#include <qtsingleapplication.h>
#include <cstdio>
#include <QStringList>
#include <QDebug>
#include <QDateTime>
#include "application.h"
#include <QMessageBox>
#include <QTextCodec>
#ifdef DEBUG

void myMessageOutput(QtMsgType type, const char *msg)
{
	fflush(stderr);
	switch (type) {
	 case QtDebugMsg:
		 fprintf(stderr, "Debug: %s\n", msg);
		 break;
	 case QtWarningMsg:
		 fprintf(stderr, "Warning: %s\n", msg);
		 break;
	 case QtCriticalMsg:
		 fprintf(stderr, "Critical: %s\n", msg);
		 break;
	 case QtFatalMsg:
		 fprintf(stderr, "Fatal: %s\n", msg);
		 abort();
	}
}
#endif // DEBUG

int main(int argc, char *argv[])
{
	
#ifdef DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	FILE * fp=freopen("ct_debug.log","a+",stderr);
	qInstallMsgHandler(myMessageOutput);
#endif // DEBUG
	
	Application::setStyle("Cleanlooks");
	Application a(argc, argv);
	QTextCodec *wantUnicode = QTextCodec::codecForName("UTF-8");
	/*QTextCodec::setCodecForTr(wantUnicode);
	QTextCodec::setCodecForLocale(wantUnicode);*/
	QTextCodec::setCodecForCStrings(wantUnicode);
	bool minimize=false,consoleWarint=false;
	QString file2open;
	if (a.isRunning())
	{
		if (argc>=2)
		for (int i=1;i<argc;i++)
		{
			if (argv[i][0]!='-')
			{
				a.sendMessage(QString::fromLocal8Bit(argv[i]));
				
			}
			
		}
		return -1;
	}
	else
	{
		if (argc>=2)
		{
			for (int i=1;i<argc;i++)
			{
				if (argv[i][0]=='-')
				{
					switch (argv[i][1])
					{
						case 'm' :
							minimize=true;
							break;
						default	 :
							break;
					}
					

				}
				else
				{
					file2open=QString::fromLocal8Bit(argv[i]);
				}
			
			}
		}
	}
	
	a.loadTranslations(":/translations");
	a.addLibraryPath(QCoreApplication::applicationDirPath ()+"/plugins");
	
	
	CuteTorrent w;
	
	a.setActivationWindow(&w);
	w.ConnectMessageReceved(&a);
	
	if (minimize)
	{
		w.showMinimized();
	}
	else
	{
		w.showNormal();
	}
	if (!file2open.isEmpty())
	{
		w.HandleNewTorrent(file2open);
	}
	int res=a.exec();
#ifdef DEBUG
	fclose(fp);
#endif // DEBUG
	return res;
}

/********************************************************************************
** Form generated from reading UI file 'CuteTorrent.ui'
**
** Created: Fri 24. May 10:41:25 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTETORRENT_H
#define UI_CUTETORRENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CuteTorrentClass
{
public:
    QAction *actionOpenTorrent;
    QAction *action_magnet;
    QAction *actionCreateTorrent;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionPause;
    QAction *actionStart;
    QAction *actionRemove;
    QAction *actionAboutCuteTorrent;
    QAction *actionCheckUpdate;
    QAction *actionSettings_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QListView *listView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QGraphicsView *piceDwonloadedView;
    QLabel *downloadSpeedLabel;
    QLabel *uploadedBytesLabel;
    QLabel *activetimeLabel;
    QLabel *uploadSpeedLabel;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *peerCoutLabel;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *timeleftLabel;
    QLabel *label_5;
    QLabel *seedCoutLabel;
    QLabel *downloadedBytesLabel;
    QLabel *totalSizeLabel;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *describtionLabel;
    QLabel *label_4;
    QLabel *pathLabel;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QTableWidget *peerTableWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QTableWidget *trackerTableWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QTableWidget *fileTableWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_CuteTorrent;
    QStatusBar *mystatusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CuteTorrentClass)
    {
        if (CuteTorrentClass->objectName().isEmpty())
            CuteTorrentClass->setObjectName(QString::fromUtf8("CuteTorrentClass"));
        CuteTorrentClass->resize(566, 659);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CuteTorrentClass->sizePolicy().hasHeightForWidth());
        CuteTorrentClass->setSizePolicy(sizePolicy);
        CuteTorrentClass->setContextMenuPolicy(Qt::NoContextMenu);
        CuteTorrentClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CuteTorrentClass->setWindowIcon(icon);
        CuteTorrentClass->setLayoutDirection(Qt::LeftToRight);
        actionOpenTorrent = new QAction(CuteTorrentClass);
        actionOpenTorrent->setObjectName(QString::fromUtf8("actionOpenTorrent"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MenuIcons/addTorrent.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenTorrent->setIcon(icon1);
        actionOpenTorrent->setShortcutContext(Qt::WindowShortcut);
        actionOpenTorrent->setSoftKeyRole(QAction::NoSoftKey);
        action_magnet = new QAction(CuteTorrentClass);
        action_magnet->setObjectName(QString::fromUtf8("action_magnet"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MenuIcons/addUrl.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_magnet->setIcon(icon2);
        actionCreateTorrent = new QAction(CuteTorrentClass);
        actionCreateTorrent->setObjectName(QString::fromUtf8("actionCreateTorrent"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MenuIcons/createTorrent.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreateTorrent->setIcon(icon3);
        actionExit = new QAction(CuteTorrentClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MenuIcons/quit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionExit->setMenuRole(QAction::QuitRole);
        actionSettings = new QAction(CuteTorrentClass);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/MenuIcons/preferencies.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon5);
        actionSettings->setMenuRole(QAction::PreferencesRole);
        actionPause = new QAction(CuteTorrentClass);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon6);
        actionStart = new QAction(CuteTorrentClass);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon7);
        actionRemove = new QAction(CuteTorrentClass);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/remove.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon8);
        actionAboutCuteTorrent = new QAction(CuteTorrentClass);
        actionAboutCuteTorrent->setObjectName(QString::fromUtf8("actionAboutCuteTorrent"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/MenuIcons/about.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutCuteTorrent->setIcon(icon9);
        actionAboutCuteTorrent->setMenuRole(QAction::AboutRole);
        actionCheckUpdate = new QAction(CuteTorrentClass);
        actionCheckUpdate->setObjectName(QString::fromUtf8("actionCheckUpdate"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/MenuIcons/checkUpdates.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheckUpdate->setIcon(icon10);
        actionSettings_2 = new QAction(CuteTorrentClass);
        actionSettings_2->setObjectName(QString::fromUtf8("actionSettings_2"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings_2->setIcon(icon11);
        centralWidget = new QWidget(CuteTorrentClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setAutoFillBackground(true);

        gridLayout_3->addWidget(listView, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        piceDwonloadedView = new QGraphicsView(tab);
        piceDwonloadedView->setObjectName(QString::fromUtf8("piceDwonloadedView"));
        piceDwonloadedView->setMaximumSize(QSize(16777215, 20));
        piceDwonloadedView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piceDwonloadedView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piceDwonloadedView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        piceDwonloadedView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|QGraphicsView::DontClipPainter|QGraphicsView::DontSavePainterState);

        gridLayout_4->addWidget(piceDwonloadedView, 1, 0, 1, 5);

        downloadSpeedLabel = new QLabel(tab);
        downloadSpeedLabel->setObjectName(QString::fromUtf8("downloadSpeedLabel"));

        gridLayout_4->addWidget(downloadSpeedLabel, 4, 1, 1, 2);

        uploadedBytesLabel = new QLabel(tab);
        uploadedBytesLabel->setObjectName(QString::fromUtf8("uploadedBytesLabel"));

        gridLayout_4->addWidget(uploadedBytesLabel, 3, 4, 1, 1);

        activetimeLabel = new QLabel(tab);
        activetimeLabel->setObjectName(QString::fromUtf8("activetimeLabel"));

        gridLayout_4->addWidget(activetimeLabel, 2, 1, 1, 2);

        uploadSpeedLabel = new QLabel(tab);
        uploadSpeedLabel->setObjectName(QString::fromUtf8("uploadSpeedLabel"));

        gridLayout_4->addWidget(uploadSpeedLabel, 4, 4, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 8, 0, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 8, 3, 1, 1);

        peerCoutLabel = new QLabel(tab);
        peerCoutLabel->setObjectName(QString::fromUtf8("peerCoutLabel"));

        gridLayout_4->addWidget(peerCoutLabel, 8, 4, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 4, 3, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 4, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 2, 3, 1, 1);

        timeleftLabel = new QLabel(tab);
        timeleftLabel->setObjectName(QString::fromUtf8("timeleftLabel"));

        gridLayout_4->addWidget(timeleftLabel, 2, 4, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 7, 0, 1, 1);

        seedCoutLabel = new QLabel(tab);
        seedCoutLabel->setObjectName(QString::fromUtf8("seedCoutLabel"));

        gridLayout_4->addWidget(seedCoutLabel, 8, 1, 1, 2);

        downloadedBytesLabel = new QLabel(tab);
        downloadedBytesLabel->setObjectName(QString::fromUtf8("downloadedBytesLabel"));

        gridLayout_4->addWidget(downloadedBytesLabel, 3, 1, 1, 2);

        totalSizeLabel = new QLabel(tab);
        totalSizeLabel->setObjectName(QString::fromUtf8("totalSizeLabel"));

        gridLayout_4->addWidget(totalSizeLabel, 7, 1, 1, 2);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 3, 3, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

        describtionLabel = new QLabel(tab);
        describtionLabel->setObjectName(QString::fromUtf8("describtionLabel"));
        describtionLabel->setContextMenuPolicy(Qt::ActionsContextMenu);

        gridLayout_4->addWidget(describtionLabel, 5, 1, 1, 4);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 7, 3, 1, 1);

        pathLabel = new QLabel(tab);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));

        gridLayout_4->addWidget(pathLabel, 7, 4, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        peerTableWidget = new QTableWidget(tab_3);
        if (peerTableWidget->columnCount() < 7)
            peerTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        peerTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        peerTableWidget->setObjectName(QString::fromUtf8("peerTableWidget"));
        peerTableWidget->setMinimumSize(QSize(0, 10));
        peerTableWidget->setMaximumSize(QSize(16777215, 150));
        peerTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        peerTableWidget->setGridStyle(Qt::NoPen);
        peerTableWidget->setSortingEnabled(true);
        peerTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        peerTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        peerTableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(peerTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        trackerTableWidget = new QTableWidget(tab_2);
        if (trackerTableWidget->columnCount() < 3)
            trackerTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        trackerTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        trackerTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        trackerTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        trackerTableWidget->setObjectName(QString::fromUtf8("trackerTableWidget"));
        trackerTableWidget->setMaximumSize(QSize(16777215, 150));
        trackerTableWidget->setLayoutDirection(Qt::LeftToRight);
        trackerTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        trackerTableWidget->setGridStyle(Qt::NoPen);
        trackerTableWidget->setSortingEnabled(true);
        trackerTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        trackerTableWidget->horizontalHeader()->setDefaultSectionSize(120);
        trackerTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        trackerTableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(trackerTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        fileTableWidget = new QTableWidget(tab_4);
        if (fileTableWidget->columnCount() < 4)
            fileTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        fileTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        fileTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        fileTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        fileTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        fileTableWidget->setObjectName(QString::fromUtf8("fileTableWidget"));
        fileTableWidget->setMaximumSize(QSize(16777215, 150));
        fileTableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        fileTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fileTableWidget->setGridStyle(Qt::NoPen);
        fileTableWidget->setSortingEnabled(true);
        fileTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        fileTableWidget->horizontalHeader()->setMinimumSectionSize(27);
        fileTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        fileTableWidget->horizontalHeader()->setStretchLastSection(true);
        fileTableWidget->verticalHeader()->setVisible(false);

        gridLayout_5->addWidget(fileTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 1);

        CuteTorrentClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CuteTorrentClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 566, 21));
        menuBar->setMinimumSize(QSize(0, 0));
        menuBar->setNativeMenuBar(false);
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_CuteTorrent = new QMenu(menuBar);
        menu_CuteTorrent->setObjectName(QString::fromUtf8("menu_CuteTorrent"));
        CuteTorrentClass->setMenuBar(menuBar);
        mystatusBar = new QStatusBar(CuteTorrentClass);
        mystatusBar->setObjectName(QString::fromUtf8("mystatusBar"));
        CuteTorrentClass->setStatusBar(mystatusBar);
        toolBar = new QToolBar(CuteTorrentClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setContextMenuPolicy(Qt::NoContextMenu);
        toolBar->setMovable(false);
        toolBar->setFloatable(true);
        CuteTorrentClass->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(tabWidget, listView);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_CuteTorrent->menuAction());
        menu->addAction(actionOpenTorrent);
        menu->addAction(action_magnet);
        menu->addSeparator();
        menu->addAction(actionCreateTorrent);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionSettings);
        menu_CuteTorrent->addAction(actionAboutCuteTorrent);
        menu_CuteTorrent->addAction(actionCheckUpdate);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionRemove);
        toolBar->addAction(actionSettings_2);

        retranslateUi(CuteTorrentClass);
        QObject::connect(actionCreateTorrent, SIGNAL(triggered()), CuteTorrentClass, SLOT(ShowCreateTorrentDialog()));
        QObject::connect(actionOpenTorrent, SIGNAL(triggered()), CuteTorrentClass, SLOT(ShowOpenTorrentDialog()));
        QObject::connect(actionStart, SIGNAL(triggered()), CuteTorrentClass, SLOT(ResumeSelected()));
        QObject::connect(actionPause, SIGNAL(triggered()), CuteTorrentClass, SLOT(PauseSelected()));
        QObject::connect(actionRemove, SIGNAL(triggered()), CuteTorrentClass, SLOT(DeleteSelected()));
        QObject::connect(actionSettings, SIGNAL(triggered()), CuteTorrentClass, SLOT(OpenSettingsDialog()));
        QObject::connect(actionCheckUpdate, SIGNAL(triggered()), CuteTorrentClass, SLOT(checkForUpdates()));
        QObject::connect(actionAboutCuteTorrent, SIGNAL(triggered()), CuteTorrentClass, SLOT(ShowAbout()));
        QObject::connect(action_magnet, SIGNAL(triggered()), CuteTorrentClass, SLOT(ProcessMagnet()));
        QObject::connect(actionSettings_2, SIGNAL(triggered()), CuteTorrentClass, SLOT(OpenSettingsDialog()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CuteTorrentClass);
    } // setupUi

    void retranslateUi(QMainWindow *CuteTorrentClass)
    {
        CuteTorrentClass->setWindowTitle(QApplication::translate("CuteTorrentClass", "\320\241uteTorrent", 0, QApplication::UnicodeUTF8));
        actionOpenTorrent->setText(QApplication::translate("CuteTorrentClass", "MENU_OPEN_TORRENT", 0, QApplication::UnicodeUTF8));
        actionOpenTorrent->setShortcut(QApplication::translate("CuteTorrentClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_magnet->setText(QApplication::translate("CuteTorrentClass", "MENU_OPEN_MAGNET", 0, QApplication::UnicodeUTF8));
        action_magnet->setShortcut(QApplication::translate("CuteTorrentClass", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionCreateTorrent->setText(QApplication::translate("CuteTorrentClass", "MENU_CREATE_TORRENT", 0, QApplication::UnicodeUTF8));
        actionCreateTorrent->setShortcut(QApplication::translate("CuteTorrentClass", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("CuteTorrentClass", "MENU_EXIT", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("CuteTorrentClass", "Alt+X", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("CuteTorrentClass", "MENU_CONFIGURATION", 0, QApplication::UnicodeUTF8));
        actionSettings->setShortcut(QApplication::translate("CuteTorrentClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("CuteTorrentClass", "STR_PAUSE", 0, QApplication::UnicodeUTF8));
        actionPause->setIconText(QApplication::translate("CuteTorrentClass", "HINT_PAUSE", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("CuteTorrentClass", "STR_START", 0, QApplication::UnicodeUTF8));
        actionStart->setIconText(QApplication::translate("CuteTorrentClass", "HINT_RESUME", 0, QApplication::UnicodeUTF8));
        actionRemove->setText(QApplication::translate("CuteTorrentClass", "STR_REMOVE", 0, QApplication::UnicodeUTF8));
        actionRemove->setIconText(QApplication::translate("CuteTorrentClass", "HINT_REMOVE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRemove->setToolTip(QApplication::translate("CuteTorrentClass", "STR_REMOVE", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAboutCuteTorrent->setText(QApplication::translate("CuteTorrentClass", "MENU_ABAUT", 0, QApplication::UnicodeUTF8));
        actionAboutCuteTorrent->setShortcut(QApplication::translate("CuteTorrentClass", "F1", 0, QApplication::UnicodeUTF8));
        actionCheckUpdate->setText(QApplication::translate("CuteTorrentClass", "MENU_CHECK_UPDATES", 0, QApplication::UnicodeUTF8));
        actionCheckUpdate->setShortcut(QApplication::translate("CuteTorrentClass", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        actionSettings_2->setText(QApplication::translate("CuteTorrentClass", "STR_SETTINGS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CuteTorrentClass", "INFO_ACTIVE_TIME", 0, QApplication::UnicodeUTF8));
        downloadSpeedLabel->setText(QString());
        uploadedBytesLabel->setText(QString());
        activetimeLabel->setText(QString());
        uploadSpeedLabel->setText(QString());
        label_10->setText(QApplication::translate("CuteTorrentClass", "INFO_SEED_COUNT", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CuteTorrentClass", "INFO_PEER_COUNT", 0, QApplication::UnicodeUTF8));
        peerCoutLabel->setText(QString());
        label_9->setText(QApplication::translate("CuteTorrentClass", "INFO_UPLOAD_SPEED", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CuteTorrentClass", "INFO_DOWNLOADED", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CuteTorrentClass", "INFO_DOWNLOAD_SPEED", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CuteTorrentClass", "INFO_REMAININF_TIME", 0, QApplication::UnicodeUTF8));
        timeleftLabel->setText(QString());
        label_5->setText(QApplication::translate("CuteTorrentClass", "INFO_TOTAL_SIZE", 0, QApplication::UnicodeUTF8));
        seedCoutLabel->setText(QString());
        downloadedBytesLabel->setText(QString());
        totalSizeLabel->setText(QString());
        label_8->setText(QApplication::translate("CuteTorrentClass", "INFO_UPLOADED", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CuteTorrentClass", "INFO_DESCRIBTION", 0, QApplication::UnicodeUTF8));
        describtionLabel->setText(QString());
        label_4->setText(QApplication::translate("CuteTorrentClass", "INFO_PATH", 0, QApplication::UnicodeUTF8));
        pathLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CuteTorrentClass", "TAB_INFO", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = peerTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CuteTorrentClass", "PEER_IP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = peerTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CuteTorrentClass", "PEER_CLIENT_NAME", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = peerTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CuteTorrentClass", "PEER_%", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = peerTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CuteTorrentClass", "PEER_DOWNLOAD_SPEED", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = peerTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CuteTorrentClass", "PEER_UPLOAD_SPEED", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = peerTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CuteTorrentClass", "PEER_DOWNLOADED", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = peerTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("CuteTorrentClass", "PEER_UPLOADED", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CuteTorrentClass", "TAB_PEERS", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = trackerTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("CuteTorrentClass", "TRACKER_URL", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = trackerTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("CuteTorrentClass", "TRACKER_STATUS", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = trackerTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("CuteTorrentClass", "TRACKER_NEXT_ANNOUNCE", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CuteTorrentClass", "TAB_TRACKERS", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = fileTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("CuteTorrentClass", "FILES_PATH", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = fileTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("CuteTorrentClass", "FILES_SIZE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = fileTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("CuteTorrentClass", "FILES_READY", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = fileTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("CuteTorrentClass", "FILES_PRIORITY", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CuteTorrentClass", "TAB_FILES", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("CuteTorrentClass", "MENU_FILE", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("CuteTorrentClass", "MENU_SETTINGS", 0, QApplication::UnicodeUTF8));
        menu_CuteTorrent->setTitle(QApplication::translate("CuteTorrentClass", "MENU_HELP", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("CuteTorrentClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CuteTorrentClass: public Ui_CuteTorrentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTETORRENT_H

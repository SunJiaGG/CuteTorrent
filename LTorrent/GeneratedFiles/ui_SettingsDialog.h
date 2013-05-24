/********************************************************************************
** Form generated from reading UI file 'SettingsDialog.ui'
**
** Created: Wed 22. May 15:00:32 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_4;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QPushButton *OKButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLabel *label_15;
    QLineEdit *activeLimitEdit;
    QLabel *label_7;
    QLabel *label_16;
    QLineEdit *activeSeedLimitEdit;
    QLabel *label_17;
    QLineEdit *activeDownloadLimitEdit;
    QSpinBox *uploadLimitEdit;
    QSpinBox *downloadLimitEdit;
    QGroupBox *proxyGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *proxyUsernameEdit;
    QLineEdit *proxyHostEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *proxyPwdEdit;
    QComboBox *proxyTypeComboBox;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *portEdit;
    QComboBox *localeComboBox;
    QCheckBox *runOnbootCheckBox;
    QCheckBox *magnetAssociationCheckBox;
    QCheckBox *startMinimizedCheckBox;
    QCheckBox *asociationCheckBox;
    QLabel *label_8;
    QWidget *tab_2;
    QGridLayout *gridLayout_17;
    QCheckBox *lowPrioDiskCheckBox;
    QCheckBox *alowReorderedOpsCheckBox;
    QLabel *label_20;
    QLabel *label_19;
    QCheckBox *useDiskReadAheadCheckBox;
    QCheckBox *useReadCasheCheckBox;
    QCheckBox *lockFilesCheckBox;
    QComboBox *diskIOCasheModeComboBox;
    QSpinBox *casheSizeLineEdit;
    QWidget *tab_3;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QListWidget *GroupsListWidget;
    QPushButton *removeGroupButton;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_8;
    QLineEdit *newGroupNameEdit;
    QPushButton *addNewGroupButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_5;
    QTextEdit *extensionsEdit;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_7;
    QLineEdit *groupSavePathEdit;
    QPushButton *BrowseGroupSavePathButton;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_4;
    QGridLayout *gridLayout_12;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_11;
    QComboBox *driveNumberComboBox;
    QGroupBox *customMoutGroupBox;
    QGridLayout *gridLayout_10;
    QLineEdit *customCommandEdit;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QLineEdit *DTPathEdit;
    QPushButton *browseDTPathButton;
    QWidget *tab;
    QGridLayout *gridLayout_19;
    QComboBox *tasksComboBox;
    QPushButton *addTaskButton;
    QPushButton *deleteTaskButton;
    QLabel *label_14;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_14;
    QDateTimeEdit *beginDateTimeEdit;
    QLabel *label_13;
    QLabel *label_9;
    QLineEdit *taskNameLineEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_15;
    QLabel *label_11;
    QLineEdit *dlLimitEdit;
    QLabel *label_12;
    QLineEdit *ulLimitEdit;
    QRadioButton *startAllRadioButton;
    QRadioButton *limitUlRadioButton;
    QRadioButton *limitDlRadioButton;
    QRadioButton *pauseAllRadioButton;
    QCalendarWidget *calendarWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_20;
    QGroupBox *webUIGroupBox;
    QGridLayout *gridLayout_18;
    QGroupBox *IPFilterGroupBox;
    QGridLayout *gridLayout_16;
    QTextEdit *ipFilterTextEdit;
    QGroupBox *webUILogginGroupBox;
    QGridLayout *gridLayout_21;
    QHBoxLayout *horizontalLayout;
    QLabel *label_22;
    QLineEdit *logLineEdit;
    QLabel *label_18;
    QLabel *label_10;
    QCheckBox *upnpCheckBox;
    QLabel *label_21;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *webPortLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *RunningLabel;
    QLabel *label_23;
    QLineEdit *rconPortLineEdit;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(627, 353);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(SettingsDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        gridLayout_4->addWidget(applyButton, 1, 3, 1, 1);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_4->addWidget(cancelButton, 1, 2, 1, 1);

        OKButton = new QPushButton(SettingsDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));

        gridLayout_4->addWidget(OKButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        tabWidget = new QTabWidget(SettingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_2 = new QGridLayout(tab_1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(tab_1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 3, 0, 1, 1);

        activeLimitEdit = new QLineEdit(groupBox_2);
        activeLimitEdit->setObjectName(QString::fromUtf8("activeLimitEdit"));

        gridLayout_3->addWidget(activeLimitEdit, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 4, 0, 1, 1);

        activeSeedLimitEdit = new QLineEdit(groupBox_2);
        activeSeedLimitEdit->setObjectName(QString::fromUtf8("activeSeedLimitEdit"));

        gridLayout_3->addWidget(activeSeedLimitEdit, 4, 1, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 5, 0, 1, 1);

        activeDownloadLimitEdit = new QLineEdit(groupBox_2);
        activeDownloadLimitEdit->setObjectName(QString::fromUtf8("activeDownloadLimitEdit"));

        gridLayout_3->addWidget(activeDownloadLimitEdit, 5, 1, 1, 1);

        uploadLimitEdit = new QSpinBox(groupBox_2);
        uploadLimitEdit->setObjectName(QString::fromUtf8("uploadLimitEdit"));
        uploadLimitEdit->setMaximum(99999);

        gridLayout_3->addWidget(uploadLimitEdit, 0, 1, 1, 1);

        downloadLimitEdit = new QSpinBox(groupBox_2);
        downloadLimitEdit->setObjectName(QString::fromUtf8("downloadLimitEdit"));
        downloadLimitEdit->setMaximum(99999);

        gridLayout_3->addWidget(downloadLimitEdit, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 2, 1, 2);

        proxyGroupBox = new QGroupBox(tab_1);
        proxyGroupBox->setObjectName(QString::fromUtf8("proxyGroupBox"));
        proxyGroupBox->setEnabled(true);
        proxyGroupBox->setCheckable(true);
        proxyGroupBox->setChecked(false);
        gridLayout = new QGridLayout(proxyGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(proxyGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        proxyUsernameEdit = new QLineEdit(proxyGroupBox);
        proxyUsernameEdit->setObjectName(QString::fromUtf8("proxyUsernameEdit"));

        gridLayout->addWidget(proxyUsernameEdit, 1, 1, 1, 1);

        proxyHostEdit = new QLineEdit(proxyGroupBox);
        proxyHostEdit->setObjectName(QString::fromUtf8("proxyHostEdit"));

        gridLayout->addWidget(proxyHostEdit, 0, 1, 1, 1);

        label_3 = new QLabel(proxyGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(proxyGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        proxyPwdEdit = new QLineEdit(proxyGroupBox);
        proxyPwdEdit->setObjectName(QString::fromUtf8("proxyPwdEdit"));

        gridLayout->addWidget(proxyPwdEdit, 2, 1, 1, 1);

        proxyTypeComboBox = new QComboBox(proxyGroupBox);
        proxyTypeComboBox->setObjectName(QString::fromUtf8("proxyTypeComboBox"));

        gridLayout->addWidget(proxyTypeComboBox, 3, 1, 1, 1);

        label_4 = new QLabel(proxyGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);


        gridLayout_2->addWidget(proxyGroupBox, 1, 0, 1, 2);

        label = new QLabel(tab_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        portEdit = new QLineEdit(tab_1);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        gridLayout_2->addWidget(portEdit, 0, 3, 1, 1);

        localeComboBox = new QComboBox(tab_1);
        localeComboBox->setObjectName(QString::fromUtf8("localeComboBox"));

        gridLayout_2->addWidget(localeComboBox, 0, 1, 1, 1);

        runOnbootCheckBox = new QCheckBox(tab_1);
        runOnbootCheckBox->setObjectName(QString::fromUtf8("runOnbootCheckBox"));

        gridLayout_2->addWidget(runOnbootCheckBox, 2, 2, 1, 1);

        magnetAssociationCheckBox = new QCheckBox(tab_1);
        magnetAssociationCheckBox->setObjectName(QString::fromUtf8("magnetAssociationCheckBox"));

        gridLayout_2->addWidget(magnetAssociationCheckBox, 3, 0, 1, 2);

        startMinimizedCheckBox = new QCheckBox(tab_1);
        startMinimizedCheckBox->setObjectName(QString::fromUtf8("startMinimizedCheckBox"));

        gridLayout_2->addWidget(startMinimizedCheckBox, 3, 2, 1, 1);

        asociationCheckBox = new QCheckBox(tab_1);
        asociationCheckBox->setObjectName(QString::fromUtf8("asociationCheckBox"));

        gridLayout_2->addWidget(asociationCheckBox, 2, 0, 1, 2);

        label_8 = new QLabel(tab_1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_17 = new QGridLayout(tab_2);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        lowPrioDiskCheckBox = new QCheckBox(tab_2);
        lowPrioDiskCheckBox->setObjectName(QString::fromUtf8("lowPrioDiskCheckBox"));

        gridLayout_17->addWidget(lowPrioDiskCheckBox, 4, 0, 1, 1);

        alowReorderedOpsCheckBox = new QCheckBox(tab_2);
        alowReorderedOpsCheckBox->setObjectName(QString::fromUtf8("alowReorderedOpsCheckBox"));

        gridLayout_17->addWidget(alowReorderedOpsCheckBox, 3, 1, 1, 1);

        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_17->addWidget(label_20, 2, 0, 1, 1);

        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_17->addWidget(label_19, 1, 0, 1, 1);

        useDiskReadAheadCheckBox = new QCheckBox(tab_2);
        useDiskReadAheadCheckBox->setObjectName(QString::fromUtf8("useDiskReadAheadCheckBox"));

        gridLayout_17->addWidget(useDiskReadAheadCheckBox, 3, 0, 1, 1);

        useReadCasheCheckBox = new QCheckBox(tab_2);
        useReadCasheCheckBox->setObjectName(QString::fromUtf8("useReadCasheCheckBox"));

        gridLayout_17->addWidget(useReadCasheCheckBox, 4, 1, 1, 1);

        lockFilesCheckBox = new QCheckBox(tab_2);
        lockFilesCheckBox->setObjectName(QString::fromUtf8("lockFilesCheckBox"));

        gridLayout_17->addWidget(lockFilesCheckBox, 3, 2, 1, 1);

        diskIOCasheModeComboBox = new QComboBox(tab_2);
        diskIOCasheModeComboBox->setObjectName(QString::fromUtf8("diskIOCasheModeComboBox"));

        gridLayout_17->addWidget(diskIOCasheModeComboBox, 1, 1, 1, 2);

        casheSizeLineEdit = new QSpinBox(tab_2);
        casheSizeLineEdit->setObjectName(QString::fromUtf8("casheSizeLineEdit"));
        casheSizeLineEdit->setMaximum(512000);

        gridLayout_17->addWidget(casheSizeLineEdit, 2, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_13 = new QGridLayout(tab_3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(150, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        GroupsListWidget = new QListWidget(groupBox_3);
        GroupsListWidget->setObjectName(QString::fromUtf8("GroupsListWidget"));

        gridLayout_5->addWidget(GroupsListWidget, 0, 1, 1, 1);

        removeGroupButton = new QPushButton(groupBox_3);
        removeGroupButton->setObjectName(QString::fromUtf8("removeGroupButton"));

        gridLayout_5->addWidget(removeGroupButton, 1, 1, 1, 1);


        gridLayout_13->addWidget(groupBox_3, 0, 0, 3, 1);

        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_8 = new QGridLayout(groupBox_9);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        newGroupNameEdit = new QLineEdit(groupBox_9);
        newGroupNameEdit->setObjectName(QString::fromUtf8("newGroupNameEdit"));

        gridLayout_8->addWidget(newGroupNameEdit, 0, 0, 1, 1);

        addNewGroupButton = new QPushButton(groupBox_9);
        addNewGroupButton->setObjectName(QString::fromUtf8("addNewGroupButton"));

        gridLayout_8->addWidget(addNewGroupButton, 0, 1, 1, 1);


        gridLayout_13->addWidget(groupBox_9, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 0, 0, 1, 1);

        extensionsEdit = new QTextEdit(groupBox_4);
        extensionsEdit->setObjectName(QString::fromUtf8("extensionsEdit"));

        gridLayout_6->addWidget(extensionsEdit, 1, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_7 = new QGridLayout(groupBox_5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupSavePathEdit = new QLineEdit(groupBox_5);
        groupSavePathEdit->setObjectName(QString::fromUtf8("groupSavePathEdit"));

        gridLayout_7->addWidget(groupSavePathEdit, 1, 0, 1, 1);

        BrowseGroupSavePathButton = new QPushButton(groupBox_5);
        BrowseGroupSavePathButton->setObjectName(QString::fromUtf8("BrowseGroupSavePathButton"));

        gridLayout_7->addWidget(BrowseGroupSavePathButton, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_6, 0, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_5, 2, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_12 = new QGridLayout(tab_4);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_4, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_11 = new QGridLayout(groupBox_8);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        driveNumberComboBox = new QComboBox(groupBox_8);
        driveNumberComboBox->setObjectName(QString::fromUtf8("driveNumberComboBox"));

        gridLayout_11->addWidget(driveNumberComboBox, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_8, 0, 1, 1, 1);

        customMoutGroupBox = new QGroupBox(tab_4);
        customMoutGroupBox->setObjectName(QString::fromUtf8("customMoutGroupBox"));
        customMoutGroupBox->setEnabled(true);
        customMoutGroupBox->setCheckable(true);
        customMoutGroupBox->setChecked(false);
        gridLayout_10 = new QGridLayout(customMoutGroupBox);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        customCommandEdit = new QLineEdit(customMoutGroupBox);
        customCommandEdit->setObjectName(QString::fromUtf8("customCommandEdit"));

        gridLayout_10->addWidget(customCommandEdit, 0, 0, 1, 1);


        gridLayout_12->addWidget(customMoutGroupBox, 1, 0, 1, 2);

        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        DTPathEdit = new QLineEdit(groupBox_6);
        DTPathEdit->setObjectName(QString::fromUtf8("DTPathEdit"));

        gridLayout_9->addWidget(DTPathEdit, 0, 0, 1, 1);

        browseDTPathButton = new QPushButton(groupBox_6);
        browseDTPathButton->setObjectName(QString::fromUtf8("browseDTPathButton"));

        gridLayout_9->addWidget(browseDTPathButton, 0, 1, 1, 1);


        gridLayout_12->addWidget(groupBox_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_19 = new QGridLayout(tab);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        tasksComboBox = new QComboBox(tab);
        tasksComboBox->setObjectName(QString::fromUtf8("tasksComboBox"));
        tasksComboBox->setMaximumSize(QSize(150, 16777215));

        gridLayout_19->addWidget(tasksComboBox, 1, 1, 1, 1);

        addTaskButton = new QPushButton(tab);
        addTaskButton->setObjectName(QString::fromUtf8("addTaskButton"));

        gridLayout_19->addWidget(addTaskButton, 1, 2, 1, 1);

        deleteTaskButton = new QPushButton(tab);
        deleteTaskButton->setObjectName(QString::fromUtf8("deleteTaskButton"));

        gridLayout_19->addWidget(deleteTaskButton, 1, 3, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(150, 16777215));

        gridLayout_19->addWidget(label_14, 1, 0, 1, 1);

        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        gridLayout_14 = new QGridLayout(groupBox_11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        beginDateTimeEdit = new QDateTimeEdit(groupBox_11);
        beginDateTimeEdit->setObjectName(QString::fromUtf8("beginDateTimeEdit"));

        gridLayout_14->addWidget(beginDateTimeEdit, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_11);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_14->addWidget(label_13, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_14->addWidget(label_9, 1, 0, 1, 1);

        taskNameLineEdit = new QLineEdit(groupBox_11);
        taskNameLineEdit->setObjectName(QString::fromUtf8("taskNameLineEdit"));
        taskNameLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_14->addWidget(taskNameLineEdit, 0, 1, 1, 1);

        groupBox = new QGroupBox(groupBox_11);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_15 = new QGridLayout(groupBox);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_15->addWidget(label_11, 2, 0, 1, 1);

        dlLimitEdit = new QLineEdit(groupBox);
        dlLimitEdit->setObjectName(QString::fromUtf8("dlLimitEdit"));
        dlLimitEdit->setEnabled(true);

        gridLayout_15->addWidget(dlLimitEdit, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_15->addWidget(label_12, 2, 2, 1, 1);

        ulLimitEdit = new QLineEdit(groupBox);
        ulLimitEdit->setObjectName(QString::fromUtf8("ulLimitEdit"));
        ulLimitEdit->setEnabled(true);

        gridLayout_15->addWidget(ulLimitEdit, 2, 3, 1, 1);

        startAllRadioButton = new QRadioButton(groupBox);
        startAllRadioButton->setObjectName(QString::fromUtf8("startAllRadioButton"));

        gridLayout_15->addWidget(startAllRadioButton, 0, 2, 1, 2);

        limitUlRadioButton = new QRadioButton(groupBox);
        limitUlRadioButton->setObjectName(QString::fromUtf8("limitUlRadioButton"));

        gridLayout_15->addWidget(limitUlRadioButton, 1, 2, 1, 2);

        limitDlRadioButton = new QRadioButton(groupBox);
        limitDlRadioButton->setObjectName(QString::fromUtf8("limitDlRadioButton"));

        gridLayout_15->addWidget(limitDlRadioButton, 1, 0, 1, 2);

        pauseAllRadioButton = new QRadioButton(groupBox);
        pauseAllRadioButton->setObjectName(QString::fromUtf8("pauseAllRadioButton"));

        gridLayout_15->addWidget(pauseAllRadioButton, 0, 0, 1, 2);


        gridLayout_14->addWidget(groupBox, 2, 0, 1, 2);

        calendarWidget = new QCalendarWidget(groupBox_11);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout_14->addWidget(calendarWidget, 0, 2, 3, 1);

        label_9->raise();
        beginDateTimeEdit->raise();
        groupBox->raise();
        label_13->raise();
        taskNameLineEdit->raise();
        calendarWidget->raise();

        gridLayout_19->addWidget(groupBox_11, 2, 0, 2, 4);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_20 = new QGridLayout(tab_5);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        webUIGroupBox = new QGroupBox(tab_5);
        webUIGroupBox->setObjectName(QString::fromUtf8("webUIGroupBox"));
        webUIGroupBox->setMaximumSize(QSize(100500, 100500));
        webUIGroupBox->setCheckable(true);
        webUIGroupBox->setChecked(false);
        gridLayout_18 = new QGridLayout(webUIGroupBox);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        IPFilterGroupBox = new QGroupBox(webUIGroupBox);
        IPFilterGroupBox->setObjectName(QString::fromUtf8("IPFilterGroupBox"));
        IPFilterGroupBox->setCheckable(true);
        IPFilterGroupBox->setChecked(false);
        gridLayout_16 = new QGridLayout(IPFilterGroupBox);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        ipFilterTextEdit = new QTextEdit(IPFilterGroupBox);
        ipFilterTextEdit->setObjectName(QString::fromUtf8("ipFilterTextEdit"));

        gridLayout_16->addWidget(ipFilterTextEdit, 0, 0, 1, 1);


        gridLayout_18->addWidget(IPFilterGroupBox, 0, 3, 9, 1);

        webUILogginGroupBox = new QGroupBox(webUIGroupBox);
        webUILogginGroupBox->setObjectName(QString::fromUtf8("webUILogginGroupBox"));
        webUILogginGroupBox->setMaximumSize(QSize(16777215, 16777215));
        webUILogginGroupBox->setCheckable(true);
        webUILogginGroupBox->setChecked(false);
        gridLayout_21 = new QGridLayout(webUILogginGroupBox);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_22 = new QLabel(webUILogginGroupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout->addWidget(label_22);

        logLineEdit = new QLineEdit(webUILogginGroupBox);
        logLineEdit->setObjectName(QString::fromUtf8("logLineEdit"));

        horizontalLayout->addWidget(logLineEdit);


        gridLayout_21->addLayout(horizontalLayout, 1, 0, 1, 3);


        gridLayout_18->addWidget(webUILogginGroupBox, 8, 0, 1, 3);

        label_18 = new QLabel(webUIGroupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_18->addWidget(label_18, 1, 0, 1, 1);

        label_10 = new QLabel(webUIGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_18->addWidget(label_10, 0, 0, 1, 1);

        upnpCheckBox = new QCheckBox(webUIGroupBox);
        upnpCheckBox->setObjectName(QString::fromUtf8("upnpCheckBox"));

        gridLayout_18->addWidget(upnpCheckBox, 4, 0, 1, 1);

        label_21 = new QLabel(webUIGroupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_18->addWidget(label_21, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(webUIGroupBox);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));

        gridLayout_18->addWidget(loginLineEdit, 0, 1, 1, 2);

        passwordLineEdit = new QLineEdit(webUIGroupBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_18->addWidget(passwordLineEdit, 1, 1, 1, 2);

        webPortLineEdit = new QLineEdit(webUIGroupBox);
        webPortLineEdit->setObjectName(QString::fromUtf8("webPortLineEdit"));

        gridLayout_18->addWidget(webPortLineEdit, 2, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(webUIGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(webUIGroupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        RunningLabel = new QLabel(webUIGroupBox);
        RunningLabel->setObjectName(QString::fromUtf8("RunningLabel"));
        RunningLabel->setEnabled(false);
        RunningLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/upload.ico")));

        horizontalLayout_2->addWidget(RunningLabel);


        gridLayout_18->addLayout(horizontalLayout_2, 6, 0, 1, 3);

        label_23 = new QLabel(webUIGroupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_18->addWidget(label_23, 3, 0, 1, 1);

        rconPortLineEdit = new QLineEdit(webUIGroupBox);
        rconPortLineEdit->setObjectName(QString::fromUtf8("rconPortLineEdit"));

        gridLayout_18->addWidget(rconPortLineEdit, 3, 1, 1, 1);


        gridLayout_20->addWidget(webUIGroupBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 4);

        QWidget::setTabOrder(OKButton, cancelButton);
        QWidget::setTabOrder(cancelButton, applyButton);
        QWidget::setTabOrder(applyButton, tabWidget);
        QWidget::setTabOrder(tabWidget, localeComboBox);
        QWidget::setTabOrder(localeComboBox, portEdit);
        QWidget::setTabOrder(portEdit, proxyGroupBox);
        QWidget::setTabOrder(proxyGroupBox, proxyHostEdit);
        QWidget::setTabOrder(proxyHostEdit, proxyUsernameEdit);
        QWidget::setTabOrder(proxyUsernameEdit, proxyPwdEdit);
        QWidget::setTabOrder(proxyPwdEdit, proxyTypeComboBox);
        QWidget::setTabOrder(proxyTypeComboBox, activeLimitEdit);
        QWidget::setTabOrder(activeLimitEdit, activeSeedLimitEdit);
        QWidget::setTabOrder(activeSeedLimitEdit, activeDownloadLimitEdit);
        QWidget::setTabOrder(activeDownloadLimitEdit, asociationCheckBox);
        QWidget::setTabOrder(asociationCheckBox, magnetAssociationCheckBox);
        QWidget::setTabOrder(magnetAssociationCheckBox, runOnbootCheckBox);
        QWidget::setTabOrder(runOnbootCheckBox, startMinimizedCheckBox);
        QWidget::setTabOrder(startMinimizedCheckBox, diskIOCasheModeComboBox);
        QWidget::setTabOrder(diskIOCasheModeComboBox, useDiskReadAheadCheckBox);
        QWidget::setTabOrder(useDiskReadAheadCheckBox, alowReorderedOpsCheckBox);
        QWidget::setTabOrder(alowReorderedOpsCheckBox, lowPrioDiskCheckBox);
        QWidget::setTabOrder(lowPrioDiskCheckBox, useReadCasheCheckBox);
        QWidget::setTabOrder(useReadCasheCheckBox, GroupsListWidget);
        QWidget::setTabOrder(GroupsListWidget, removeGroupButton);
        QWidget::setTabOrder(removeGroupButton, newGroupNameEdit);
        QWidget::setTabOrder(newGroupNameEdit, addNewGroupButton);
        QWidget::setTabOrder(addNewGroupButton, extensionsEdit);
        QWidget::setTabOrder(extensionsEdit, groupSavePathEdit);
        QWidget::setTabOrder(groupSavePathEdit, BrowseGroupSavePathButton);
        QWidget::setTabOrder(BrowseGroupSavePathButton, DTPathEdit);
        QWidget::setTabOrder(DTPathEdit, browseDTPathButton);
        QWidget::setTabOrder(browseDTPathButton, driveNumberComboBox);
        QWidget::setTabOrder(driveNumberComboBox, customMoutGroupBox);
        QWidget::setTabOrder(customMoutGroupBox, customCommandEdit);

        retranslateUi(SettingsDialog);
        QObject::connect(applyButton, SIGNAL(clicked()), SettingsDialog, SLOT(ApplySettings()));
        QObject::connect(OKButton, SIGNAL(clicked()), SettingsDialog, SLOT(ApplyAndClose()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SettingsDialog, SLOT(reject()));
        QObject::connect(addNewGroupButton, SIGNAL(clicked()), SettingsDialog, SLOT(addGroup()));
        QObject::connect(removeGroupButton, SIGNAL(clicked()), SettingsDialog, SLOT(removeGroup()));
        QObject::connect(BrowseGroupSavePathButton, SIGNAL(clicked()), SettingsDialog, SLOT(browseSavepathGroup()));
        QObject::connect(browseDTPathButton, SIGNAL(clicked()), SettingsDialog, SLOT(browseDTPath()));
        QObject::connect(GroupsListWidget, SIGNAL(currentRowChanged(int)), SettingsDialog, SLOT(showSelectedGroup(int)));
        QObject::connect(addTaskButton, SIGNAL(clicked()), SettingsDialog, SLOT(AddTask()));
        QObject::connect(deleteTaskButton, SIGNAL(clicked()), SettingsDialog, SLOT(DeleteTask()));
        QObject::connect(limitDlRadioButton, SIGNAL(clicked()), dlLimitEdit, SLOT(setFocus()));
        QObject::connect(limitUlRadioButton, SIGNAL(clicked()), ulLimitEdit, SLOT(setFocus()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "SETTINGS_DIALOG", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("SettingsDialog", "SETTINGS_ACCEPT_BUTTON", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SettingsDialog", "SETTINGS_CANCEL_BUTTON", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("SettingsDialog", "SETTINGS_OK_BITTON", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_2->setTitle(QApplication::translate("SettingsDialog", "RESTRICTIONS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_6->setWhatsThis(QApplication::translate("SettingsDialog", "UPLOAD_SPEED_LIMIT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("SettingsDialog", "UPLOAD_SPEED_LIMIT(Kb/s)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_15->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_TORRENTS_LIMIT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_15->setText(QApplication::translate("SettingsDialog", "ACTIVE_TORRENTS_LIMIT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        activeLimitEdit->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_TORRENTS_LIMIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_7->setWhatsThis(QApplication::translate("SettingsDialog", "DOWNLOAD_SPEED_LIMIT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_7->setText(QApplication::translate("SettingsDialog", "DOWNLOAD_SPEED_LIMIT(Kb/s)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_16->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_SEEDS_LIMIT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_16->setText(QApplication::translate("SettingsDialog", "ACTIVE_SEEDS_LIMIT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        activeSeedLimitEdit->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_SEEDS_LIMIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_17->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_DOWNLOADS_LIMIT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_17->setText(QApplication::translate("SettingsDialog", "ACTIVE_DOWNLOADS_LIMIT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        activeDownloadLimitEdit->setWhatsThis(QApplication::translate("SettingsDialog", "ACTIVE_DOWNLOADS_LIMIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        uploadLimitEdit->setSpecialValueText(QApplication::translate("SettingsDialog", "None", 0, QApplication::UnicodeUTF8));
        uploadLimitEdit->setSuffix(QApplication::translate("SettingsDialog", " Kb\\s", 0, QApplication::UnicodeUTF8));
        uploadLimitEdit->setPrefix(QString());
        downloadLimitEdit->setSpecialValueText(QApplication::translate("SettingsDialog", "None", 0, QApplication::UnicodeUTF8));
        downloadLimitEdit->setSuffix(QApplication::translate("SettingsDialog", " Kb\\s", 0, QApplication::UnicodeUTF8));
        downloadLimitEdit->setPrefix(QString());
        proxyGroupBox->setTitle(QApplication::translate("SettingsDialog", "USE_PROXY", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_TYPE_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("SettingsDialog", "PROXY_TYPE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        proxyUsernameEdit->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_USER_NAME_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        proxyHostEdit->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_HOST_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_USER_NAME_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("SettingsDialog", "PROXY_USER_NAME", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_HOST_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("SettingsDialog", "PROXY_HOST (IP:port)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        proxyPwdEdit->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_PASSWORD", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        proxyTypeComboBox->clear();
        proxyTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "Socks4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "Socks5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "Socks5 \321\201 \320\277\320\260\321\200\320\276\320\273\320\265\320\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "http", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "http \321\201 \320\277\320\260\321\200\320\276\320\273\320\265\320\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "i2p", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        proxyTypeComboBox->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_TYPE", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_4->setWhatsThis(QApplication::translate("SettingsDialog", "PROXY_PASSWORD_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("SettingsDialog", "PROXY_PASSWORD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsDialog", "LISTEN_PORT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        runOnbootCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "START_ON_BOOT_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        runOnbootCheckBox->setText(QApplication::translate("SettingsDialog", "START_ON_BOOT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        magnetAssociationCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "MAGNET_ASSOCIATION_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        magnetAssociationCheckBox->setText(QApplication::translate("SettingsDialog", "MAGNET_ASSOCIATION", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        startMinimizedCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "START_MINIMIZED_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        startMinimizedCheckBox->setText(QApplication::translate("SettingsDialog", "START_MINIMIZED", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        asociationCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "TORRENT_FILES_ASSOCIATION_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        asociationCheckBox->setText(QApplication::translate("SettingsDialog", "TORRENT_FILES_ASSOCIATION", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SettingsDialog", "LANGUAGE", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("SettingsDialog", "TAB_TORRENT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lowPrioDiskCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "LOW_PORIO_DISK_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lowPrioDiskCheckBox->setText(QApplication::translate("SettingsDialog", "LOW_PORIO_DISK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        alowReorderedOpsCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "ALOW_REORDERED_OPERATIONS_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        alowReorderedOpsCheckBox->setText(QApplication::translate("SettingsDialog", "ALOW_REORDERED_OPERATIONS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_20->setWhatsThis(QApplication::translate("SettingsDialog", "CASH_SIZE_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_20->setText(QApplication::translate("SettingsDialog", "CASH_SIZE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_19->setWhatsThis(QApplication::translate("SettingsDialog", "DISK_IO_CASH_MODE_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_19->setText(QApplication::translate("SettingsDialog", "DISK_IO_CASH_MODE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        useDiskReadAheadCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "USE_DISK_READ_AHEAD_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        useDiskReadAheadCheckBox->setText(QApplication::translate("SettingsDialog", "USE_DISK_READ_AHEAD", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        useReadCasheCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "USE_READ_CASHE_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        useReadCasheCheckBox->setText(QApplication::translate("SettingsDialog", "USE_READ_CASHE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lockFilesCheckBox->setWhatsThis(QApplication::translate("SettingsDialog", "LOCK_FILES_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lockFilesCheckBox->setText(QApplication::translate("SettingsDialog", "LOCK_FILES", 0, QApplication::UnicodeUTF8));
        diskIOCasheModeComboBox->clear();
        diskIOCasheModeComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "ENABLE_OS_CACHE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "DISABLE_OS_CACHE_FOR_ALIGNED_FILES", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "DISABLE_OS_CACHE", 0, QApplication::UnicodeUTF8)
        );
        casheSizeLineEdit->setSpecialValueText(QApplication::translate("SettingsDialog", "None", 0, QApplication::UnicodeUTF8));
        casheSizeLineEdit->setSuffix(QApplication::translate("SettingsDialog", " Kb", 0, QApplication::UnicodeUTF8));
        casheSizeLineEdit->setPrefix(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SettingsDialog", "TAB_HDD", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SettingsDialog", "FILTERING_GROUP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        GroupsListWidget->setWhatsThis(QApplication::translate("SettingsDialog", "GROUP_LISTBOX_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        removeGroupButton->setWhatsThis(QApplication::translate("SettingsDialog", "FILTERING_GROUP_DELETE_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        removeGroupButton->setText(QApplication::translate("SettingsDialog", "FILTERING_GROUP_DELETE", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("SettingsDialog", "ADD_CHANGE_GROUP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        newGroupNameEdit->setWhatsThis(QApplication::translate("SettingsDialog", "newGroupNameEdit_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        addNewGroupButton->setWhatsThis(QApplication::translate("SettingsDialog", "ADD_GROUP_BUTON_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        addNewGroupButton->setText(QApplication::translate("SettingsDialog", "ADD_GROUP_BUTON", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("SettingsDialog", "FILE_EXTENSIONS(FORMAT: jpg|png|bmp)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        extensionsEdit->setWhatsThis(QApplication::translate("SettingsDialog", "extensionsEdit_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QApplication::translate("SettingsDialog", "GROUP_SAVE_PATH", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        groupSavePathEdit->setWhatsThis(QApplication::translate("SettingsDialog", "groupSavePathEdit_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        BrowseGroupSavePathButton->setWhatsThis(QApplication::translate("SettingsDialog", "GROUP_SAVE_PATH_CHOISE_BUTTON_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        BrowseGroupSavePathButton->setText(QApplication::translate("SettingsDialog", "GROUP_SAVE_PATH_CHOISE_BUTTON", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SettingsDialog", "TAB_TORRENT_FILTERING", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("SettingsDialog", "DRIVE_NUMBER", 0, QApplication::UnicodeUTF8));
        driveNumberComboBox->clear();
        driveNumberComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        driveNumberComboBox->setWhatsThis(QApplication::translate("SettingsDialog", "driveNumberComboBox_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        customMoutGroupBox->setTitle(QApplication::translate("SettingsDialog", "DAEMONTOOLS_CUSTOM_COMMAND", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        customCommandEdit->setWhatsThis(QApplication::translate("SettingsDialog", "DAEMONTOOLS_COMMAND_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_6->setTitle(QApplication::translate("SettingsDialog", "DAEMONTOOLS_PATH", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        DTPathEdit->setWhatsThis(QApplication::translate("SettingsDialog", "DTPathEdit_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        browseDTPathButton->setAccessibleName(QApplication::translate("SettingsDialog", "DAEMONTOOLS_PATH_CHOISE_BUUTON_WIT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        browseDTPathButton->setText(QApplication::translate("SettingsDialog", "DAEMONTOOLS_PATH_CHOISE_BUUTON", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("SettingsDialog", "TAB_DAEMONTOOLS", 0, QApplication::UnicodeUTF8));
        addTaskButton->setText(QApplication::translate("SettingsDialog", "ADD_BUTTON", 0, QApplication::UnicodeUTF8));
        deleteTaskButton->setText(QApplication::translate("SettingsDialog", "DELETE_BUTTON", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SettingsDialog", "ACTIONS", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("SettingsDialog", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SettingsDialog", "ACTION_NAME", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SettingsDialog", "ACTION_BEGIN", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SettingsDialog", "ACTIONS", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SettingsDialog", "LIMIT_DOWNLOAD", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SettingsDialog", "LIMIT_UPLOAD", 0, QApplication::UnicodeUTF8));
        startAllRadioButton->setText(QApplication::translate("SettingsDialog", "START_ALL", 0, QApplication::UnicodeUTF8));
        limitUlRadioButton->setText(QApplication::translate("SettingsDialog", "LIMIT_UPLOAD", 0, QApplication::UnicodeUTF8));
        limitDlRadioButton->setText(QApplication::translate("SettingsDialog", "LIMIT_DOWNLOAD", 0, QApplication::UnicodeUTF8));
        pauseAllRadioButton->setText(QApplication::translate("SettingsDialog", "PUASE_ALL", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SettingsDialog", "TAB_SCEDULER", 0, QApplication::UnicodeUTF8));
        webUIGroupBox->setTitle(QApplication::translate("SettingsDialog", "WEB_CONTROLL_ENABLED", 0, QApplication::UnicodeUTF8));
        IPFilterGroupBox->setTitle(QApplication::translate("SettingsDialog", "WEB_UI_USE_IP_FILTER", 0, QApplication::UnicodeUTF8));
        ipFilterTextEdit->setHtml(QApplication::translate("SettingsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">allow all </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">#deny 192.168.1.* </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">#allow 192.168.1.10-192.168.1.15</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        webUILogginGroupBox->setTitle(QApplication::translate("SettingsDialog", "WEB_UI_LOGGING_ENABLED", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("SettingsDialog", "WEB_UI_LOG_NAME", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("SettingsDialog", "WEB_UI_PASSWORD", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SettingsDialog", "WEB_UI_LOGIN", 0, QApplication::UnicodeUTF8));
        upnpCheckBox->setText(QApplication::translate("SettingsDialog", "WEB_UI_UPNP_ENABLED", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("SettingsDialog", "WEB_UI_PORT", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SettingsDialog", "WEBUI_START", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SettingsDialog", "WEBUI_STOP", 0, QApplication::UnicodeUTF8));
        RunningLabel->setText(QString());
        label_23->setText(QApplication::translate("SettingsDialog", "RCON_PORT", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("SettingsDialog", "TAB_WEB_CONTROL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'OpenTorrentDialog.ui'
**
** Created: Wed 22. May 15:00:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENTORRENTDIALOG_H
#define UI_OPENTORRENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_OpenTorrentDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *pathEdit;
    QPushButton *browseButton;
    QComboBox *GroupComboBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *labelNameTitile;
    QLabel *labelCommentTitle;
    QLabel *labelSizeTitle;
    QLabel *loaderTextLabel;
    QTreeView *treeView;
    QLabel *loaderGifLabel;
    QLabel *labelNameData;
    QLabel *labelComentData;
    QLabel *labelSizeData;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *yesButton;

    void setupUi(QDialog *OpenTorrentDialog)
    {
        if (OpenTorrentDialog->objectName().isEmpty())
            OpenTorrentDialog->setObjectName(QString::fromUtf8("OpenTorrentDialog"));
        OpenTorrentDialog->resize(449, 533);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        OpenTorrentDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(OpenTorrentDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(OpenTorrentDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pathEdit = new QLineEdit(groupBox);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        gridLayout->addWidget(pathEdit, 0, 0, 1, 1);

        browseButton = new QPushButton(groupBox);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        gridLayout->addWidget(browseButton, 0, 1, 1, 1);

        GroupComboBox = new QComboBox(groupBox);
        GroupComboBox->setObjectName(QString::fromUtf8("GroupComboBox"));

        gridLayout->addWidget(GroupComboBox, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(OpenTorrentDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelNameTitile = new QLabel(groupBox_2);
        labelNameTitile->setObjectName(QString::fromUtf8("labelNameTitile"));

        gridLayout_2->addWidget(labelNameTitile, 0, 0, 1, 1);

        labelCommentTitle = new QLabel(groupBox_2);
        labelCommentTitle->setObjectName(QString::fromUtf8("labelCommentTitle"));

        gridLayout_2->addWidget(labelCommentTitle, 1, 0, 1, 2);

        labelSizeTitle = new QLabel(groupBox_2);
        labelSizeTitle->setObjectName(QString::fromUtf8("labelSizeTitle"));

        gridLayout_2->addWidget(labelSizeTitle, 2, 0, 1, 1);

        loaderTextLabel = new QLabel(groupBox_2);
        loaderTextLabel->setObjectName(QString::fromUtf8("loaderTextLabel"));

        gridLayout_2->addWidget(loaderTextLabel, 2, 5, 1, 1);

        treeView = new QTreeView(groupBox_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout_2->addWidget(treeView, 3, 0, 1, 6);

        loaderGifLabel = new QLabel(groupBox_2);
        loaderGifLabel->setObjectName(QString::fromUtf8("loaderGifLabel"));

        gridLayout_2->addWidget(loaderGifLabel, 2, 4, 1, 1);

        labelNameData = new QLabel(groupBox_2);
        labelNameData->setObjectName(QString::fromUtf8("labelNameData"));

        gridLayout_2->addWidget(labelNameData, 0, 2, 1, 4);

        labelComentData = new QLabel(groupBox_2);
        labelComentData->setObjectName(QString::fromUtf8("labelComentData"));

        gridLayout_2->addWidget(labelComentData, 1, 2, 1, 4);

        labelSizeData = new QLabel(groupBox_2);
        labelSizeData->setObjectName(QString::fromUtf8("labelSizeData"));

        gridLayout_2->addWidget(labelSizeData, 2, 1, 1, 3);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(266, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        cancelButton = new QPushButton(OpenTorrentDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_3->addWidget(cancelButton, 2, 2, 1, 1);

        yesButton = new QPushButton(OpenTorrentDialog);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));

        gridLayout_3->addWidget(yesButton, 2, 1, 1, 1);


        retranslateUi(OpenTorrentDialog);
        QObject::connect(browseButton, SIGNAL(clicked()), OpenTorrentDialog, SLOT(BrowseButton()));
        QObject::connect(cancelButton, SIGNAL(clicked()), OpenTorrentDialog, SLOT(reject()));
        QObject::connect(yesButton, SIGNAL(clicked()), OpenTorrentDialog, SLOT(AccepTorrent()));
        QObject::connect(GroupComboBox, SIGNAL(currentIndexChanged(int)), OpenTorrentDialog, SLOT(ChangeGroup()));

        QMetaObject::connectSlotsByName(OpenTorrentDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenTorrentDialog)
    {
        OpenTorrentDialog->setWindowTitle(QApplication::translate("OpenTorrentDialog", "DIALOG_OPEN_TORRENT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        OpenTorrentDialog->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_SAVE_PATH", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_BROWSE_BUTTON", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenTorrentDialog", "DISCRIBTION_LABEL", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_INFO", 0, QApplication::UnicodeUTF8));
        labelNameTitile->setText(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_INFO_NAME", 0, QApplication::UnicodeUTF8));
        labelCommentTitle->setText(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_INFO_DESCRIBTION", 0, QApplication::UnicodeUTF8));
        labelSizeTitle->setText(QApplication::translate("OpenTorrentDialog", "SIZE", 0, QApplication::UnicodeUTF8));
        loaderTextLabel->setText(QApplication::translate("OpenTorrentDialog", "RECIVING_METADATA", 0, QApplication::UnicodeUTF8));
        loaderGifLabel->setText(QString());
        labelNameData->setText(QString());
        labelComentData->setText(QString());
        labelSizeData->setText(QString());
        cancelButton->setText(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_CANCEL_BUTTON", 0, QApplication::UnicodeUTF8));
        yesButton->setText(QApplication::translate("OpenTorrentDialog", "OPEN_TORRENT_ADD_BUTTON", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenTorrentDialog: public Ui_OpenTorrentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENTORRENTDIALOG_H

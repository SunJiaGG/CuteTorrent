/********************************************************************************
** Form generated from reading UI file 'multipleDt.ui'
**
** Created: Wed 22. May 15:00:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLEDT_H
#define UI_MULTIPLEDT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DTMountDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QListView *listView;

    void setupUi(QDialog *DTMountDialog)
    {
        if (DTMountDialog->objectName().isEmpty())
            DTMountDialog->setObjectName(QString::fromUtf8("DTMountDialog"));
        DTMountDialog->resize(400, 157);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DTMountDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(DTMountDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        okButton = new QPushButton(DTMountDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        vboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(DTMountDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        vboxLayout->addWidget(cancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        gridLayout->addLayout(vboxLayout, 0, 1, 1, 1);

        listView = new QListView(DTMountDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(listView, 0, 0, 1, 1);


        retranslateUi(DTMountDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), DTMountDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTMountDialog);
    } // setupUi

    void retranslateUi(QDialog *DTMountDialog)
    {
        DTMountDialog->setWindowTitle(QApplication::translate("DTMountDialog", "DT_MOUNT_DILAOG", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("DTMountDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("DTMountDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DTMountDialog: public Ui_DTMountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLEDT_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *start;
    QLineEdit *file_name;
    QPushButton *view_file;
    QProgressBar *progress;
    QLabel *state_load;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *ports;
    QPushButton *fresh_com;
    QLabel *label;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(271, 154);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        start = new QPushButton(MainWindow);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(90, 50, 91, 41));
        file_name = new QLineEdit(MainWindow);
        file_name->setObjectName(QStringLiteral("file_name"));
        file_name->setGeometry(QRect(130, 10, 131, 20));
        view_file = new QPushButton(MainWindow);
        view_file->setObjectName(QStringLiteral("view_file"));
        view_file->setGeometry(QRect(190, 40, 75, 23));
        progress = new QProgressBar(MainWindow);
        progress->setObjectName(QStringLiteral("progress"));
        progress->setEnabled(false);
        progress->setGeometry(QRect(10, 100, 251, 23));
        progress->setValue(0);
        progress->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        state_load = new QLabel(MainWindow);
        state_load->setObjectName(QStringLiteral("state_load"));
        state_load->setGeometry(QRect(10, 130, 251, 20));
        state_load->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(MainWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 114, 35));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ports = new QComboBox(horizontalLayoutWidget);
        ports->setObjectName(QStringLiteral("ports"));

        horizontalLayout->addWidget(ports);

        fresh_com = new QPushButton(horizontalLayoutWidget);
        fresh_com->setObjectName(QStringLiteral("fresh_com"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/refresh.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        fresh_com->setIcon(icon1);
        fresh_com->setIconSize(QSize(25, 20));

        horizontalLayout->addWidget(fresh_com);

        horizontalLayout->setStretch(0, 80);
        horizontalLayout->setStretch(1, 20);
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(15, 50, 61, 41));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PC Bootloader", 0));
        start->setText(QApplication::translate("MainWindow", "\320\241\320\242\320\220\320\240\320\242", 0));
        view_file->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200...", 0));
        state_load->setText(QApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265 . . .", 0));
        fresh_com->setText(QString());
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/images/icon.jpg\"/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

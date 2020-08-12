/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *song_list;
    QListWidget *menu_list;
    QPushButton *play_pause;
    QPushButton *jump_forward;
    QRadioButton *shuffle;
    QPushButton *jump_backward;
    QLabel *now_playing_text;
    QSlider *progress_slider;
    QRadioButton *repeat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(799, 535);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        song_list = new QListWidget(centralWidget);
        song_list->setObjectName(QStringLiteral("song_list"));

        gridLayout->addWidget(song_list, 0, 2, 1, 7);

        menu_list = new QListWidget(centralWidget);
        menu_list->setObjectName(QStringLiteral("menu_list"));

        gridLayout->addWidget(menu_list, 0, 0, 1, 2);

        play_pause = new QPushButton(centralWidget);
        play_pause->setObjectName(QStringLiteral("play_pause"));

        gridLayout->addWidget(play_pause, 2, 7, 1, 1);

        jump_forward = new QPushButton(centralWidget);
        jump_forward->setObjectName(QStringLiteral("jump_forward"));

        gridLayout->addWidget(jump_forward, 2, 8, 1, 1);

        shuffle = new QRadioButton(centralWidget);
        shuffle->setObjectName(QStringLiteral("shuffle"));
        shuffle->setAutoExclusive(false);

        gridLayout->addWidget(shuffle, 2, 4, 1, 1);

        jump_backward = new QPushButton(centralWidget);
        jump_backward->setObjectName(QStringLiteral("jump_backward"));

        gridLayout->addWidget(jump_backward, 2, 6, 1, 1);

        now_playing_text = new QLabel(centralWidget);
        now_playing_text->setObjectName(QStringLiteral("now_playing_text"));

        gridLayout->addWidget(now_playing_text, 2, 0, 1, 4);

        progress_slider = new QSlider(centralWidget);
        progress_slider->setObjectName(QStringLiteral("progress_slider"));
        progress_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(progress_slider, 1, 0, 1, 9);

        repeat = new QRadioButton(centralWidget);
        repeat->setObjectName(QStringLiteral("repeat"));
        repeat->setAutoExclusive(false);

        gridLayout->addWidget(repeat, 2, 5, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        play_pause->setText(QApplication::translate("MainWindow", "|>", Q_NULLPTR));
        jump_forward->setText(QApplication::translate("MainWindow", ">>", Q_NULLPTR));
        shuffle->setText(QApplication::translate("MainWindow", "shuffle", Q_NULLPTR));
        jump_backward->setText(QApplication::translate("MainWindow", "<<", Q_NULLPTR));
        now_playing_text->setText(QString());
        repeat->setText(QApplication::translate("MainWindow", "repeat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

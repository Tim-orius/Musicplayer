#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <player.h>
#include <iostream>
#include <string>
#include <chrono>

#include <QListWidgetItem>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Player *player;

    void createMenu();

    QMenu *menuMenu;
    QAction *settingsAct;
    QAction *helpAct;
    QAction *filePathAct;

    std::string music_files;


private slots:
    void settings();
    void i_need_help();
    void file_path();

    void play();
    void forward();
    void backward();

signals:
    void imported();
};

#endif // MAINWINDOW_H

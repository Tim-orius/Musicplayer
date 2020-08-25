#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createMenu();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Msuic Player"));
    this->playpause = false;

    connect(this->ui->play_pause, SIGNAL(clicked(bool)), this, SLOT(play_and_pause()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenu(){
    filePathAct = new QAction(tr("&Choose Path"), this);
    filePathAct->setStatusTip(tr("Choose music directory"));
    connect(filePathAct, SIGNAL(triggered()), this, SLOT(file_path()));

    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip(tr("Information & help"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(i_need_help()));

    settingsAct = new QAction(tr("&Settings"), this);
    settingsAct->setStatusTip(tr("Set your preferences"));
    connect(settingsAct, SIGNAL(triggered()), this, SLOT(settings()));

    menuMenu = menuBar()->addMenu(tr("&Menu"));
    menuMenu->addAction(filePathAct);
    menuMenu->addAction(helpAct);
    menuMenu->addAction(settingsAct);
}

void MainWindow::file_path(){
    /*
    QFileDialog *dialog = new QFileDialog(nullptr, QString("Select music folder"));
    dialog->setFileMode(QFileDialog::Directory);
    if (dialog->exec()){
        this->music_files = dialog->selectedFiles().first().toUtf8().constData();
        emit imported();
    }
    std::cout << this->music_files << std::endl;
    */
    this->music_files = "/home/tim/Music/";
    this->player->set_music_files(this->music_files);

    for(int i=0; i<this->player->ammount; ++i){
        this->ui->song_list->addItem(QString::fromStdString(this->player->titles[i]->file_name));
    }
}

void MainWindow::settings(){
    std::cout << "2" << std::endl;
}

void MainWindow::i_need_help(){
    std::cout << "3" << std::endl;
}

void MainWindow::play_and_pause(){
    if(playpause){
        this->player->play();
        this->playpause = false;
    } else {
        this->player->pause();
        this->playpause = true;
    }
}

void MainWindow::play_new(){
    this->playpause = false;
    this->player->play_new();
}

void MainWindow::close(){
    this->playpause = true;
    this->player->close();
}

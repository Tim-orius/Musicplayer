#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createMenu();

    this->player = new Player();

    setWindowTitle(tr("Msuic Player"));
    this->playpause = false;
    this->shuffle_status = false;
    this->repeat_status = 0;

    connect(this->ui->play_pause, SIGNAL(clicked(bool)), this, SLOT(play_and_pause()));
    connect(this->ui->repeat_button, SIGNAL(clicked(bool)), this, SLOT(on_repeat()));
    connect(this->ui->shuffle_button, SIGNAL(clicked(bool)), this, SLOT(on_shuffle()));
    connect(this->ui->song_list, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListItemClicked(QListWidgetItem*)));
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
    QFileDialog *dialog = new QFileDialog(nullptr, QString("Select music folder"));
    dialog->setFileMode(QFileDialog::Directory);
    if (dialog->exec()){
        this->music_files = dialog->selectedFiles().first().toUtf8().constData();
        emit imported();
    }
    std::cout << this->music_files << std::endl;
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

void MainWindow::onListItemClicked(QListWidgetItem* item){
    QString item_text = item->text();
    this->player->play_new(item_text.toUtf8().constData());
}

void MainWindow::on_repeat(){
    switch(this->repeat_status){
    case 0:{
        this->repeat_status = 1;
        this->ui->repeat_button->setText("repeat (1)");
    }
    case 1:{
        this->repeat_status = 2;
        this->ui->repeat_button->setText("repeat (all)");
    }
    case 2:{
        this->repeat_status = 0;
        this->ui->repeat_button->setText("repeat (no)");
    }
    default:{
        this->repeat_status = 0;
        this->ui->repeat_button->setText("repeat (no)");
        std::cout << "default -- repeat" << std::endl;
    }
    }
}

void MainWindow::on_shuffle(){
    if(this->shuffle_status){
        this->ui->shuffle_button->setText("shuffle (n)");
    } else {
        this->ui->shuffle_button->setText("shuffle (y)");
    }

    this->shuffle_status = !this->shuffle_status;
}

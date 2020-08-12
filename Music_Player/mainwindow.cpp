#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*
    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);
    */

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    // layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);


    createMenu();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Msuic Player"));
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
    cout << this->music_files << endl;
    this->player->music_files = this->music_files;
    this->player->directory();
}

void MainWindow::settings(){
    cout << "2" << endl;
}

void MainWindow::i_need_help(){
    cout << "3" << endl;
}

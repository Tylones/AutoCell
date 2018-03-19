#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RenderArea *renderArea = new RenderArea;

    ui->scrollArea->setWidget(renderArea);
    ui->scrollArea->setWidgetResizable(true);


    setCentralWidget(ui->scrollArea);


    QObject::connect(ui->actionplay, &QAction::toggled,renderArea , &RenderArea::playIsChecked);
    QObject::connect(ui->actionnext, &QAction::triggered,renderArea , &RenderArea::next);
    QObject::connect(renderArea, &RenderArea::pause ,this, &MainWindow::pause);


}

void MainWindow::pause()
{
    ui->actionplay->setChecked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


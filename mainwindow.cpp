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


    QObject::connect(ui->actionplay, &QAction::triggered,renderArea , &RenderArea::play);
    QObject::connect(ui->actionpause, &QAction::triggered,renderArea , &RenderArea::pause);
    QObject::connect(ui->actionnext, &QAction::triggered,renderArea , &RenderArea::next);

}

MainWindow::~MainWindow()
{
    delete ui;
}


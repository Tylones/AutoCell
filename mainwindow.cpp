#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),renderArea(new RenderArea()),newCellDialog(new NewAutoCell(this))
{

    ui->setupUi(this);


    ui->scrollArea->setWidget(renderArea);
    ui->scrollArea->setWidgetResizable(true);


    setCentralWidget(ui->scrollArea);


    QObject::connect(ui->actionNew_AutoCell, &QAction::triggered,newCellDialog ,&NewAutoCell::show );
    QObject::connect(ui->actionplay, &QAction::toggled,renderArea , &RenderArea::playIsChecked);
    QObject::connect(ui->actionnext, &QAction::triggered,renderArea , &RenderArea::next);
    QObject::connect(renderArea, &RenderArea::pause ,this, &MainWindow::pause);
    QObject::connect(newCellDialog, &NewAutoCell::accepted,this ,&MainWindow::createNewAutoCell );


}

void MainWindow::pause()
{
    ui->actionplay->setChecked(false);
}

void MainWindow::createNewAutoCell()
{
    renderArea->setAutoCell(new OneD());
    ui->actionplay->setEnabled(true);
    ui->actionnext->setEnabled(true);

}


MainWindow::~MainWindow()
{
    delete ui;
}


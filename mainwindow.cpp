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


    QObject::connect(ui->actionNew_AutoCell, &QAction::triggered, newCellDialog ,&NewAutoCell::show );
    QObject::connect(ui->actionOpen_AutoCell, &QAction::triggered, openCellDialog, &OpenAutoCell::show);
    QObject::connect(ui->actionplay, &QAction::toggled,renderArea , &RenderArea::playIsChecked);
    QObject::connect(ui->actionnext, &QAction::triggered,renderArea , &RenderArea::next);
    QObject::connect(renderArea, &RenderArea::pause ,this, &MainWindow::pause);
    QObject::connect(newCellDialog, &NewAutoCell::accepted,this ,&MainWindow::createNewAutoCell );
    QObject::connect(openCellDialog, &OpenAutoCell::accepted, this, &MainWindow::openAutoCell);


}

void MainWindow::pause()
{
    ui->actionplay->setChecked(false);
}

void MainWindow::createNewAutoCell()
{

    if(newCellDialog->getType()=="Simple one dimension")
    {
        renderArea->setAutoCell(new OneD(newCellDialog->getWidth()));

    }
    else if(newCellDialog->getType()=="Game of life")
    {
        renderArea->setAutoCell(new jeuVie(newCellDialog->getHeight(),newCellDialog->getWidth()));

    }

    else if(newCellDialog->getType()=="Quad life")
    {
        renderArea->setAutoCell(new QuadLife(newCellDialog->getHeight(),newCellDialog->getWidth()));

    }

    ui->actionplay->setEnabled(true);
    ui->actionnext->setEnabled(true);

}

void MainWindow::openAutoCell(){
    if(openCellDialog->getFile().getNoeud("type") == "oneD")
        renderArea->setAutoCell(new OneD(openCellDialog->getFile().getNoeud("width").toInt()));
    else if (openCellDialog->getFile().getNoeud("type") == "jeuVie")
        renderArea->setAutoCell(new jeuVie(openCellDialog->getFile().getNoeud("height").toInt(), openCellDialog->getFile().getNoeud("width").toInt()));
    else if (openCellDialog->getFile().getNoeud("type") == "quadLife")
        renderArea->setAutoCell(new QuadLife(openCellDialog->getFile().getNoeud("height").toInt(), openCellDialog->getFile().getNoeud("width").toInt()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


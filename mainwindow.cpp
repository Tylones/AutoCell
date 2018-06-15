#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),renderArea(new RenderArea()),newCellDialog(new NewAutoCell(this)),openCellDialog(new OpenAutoCell(this)){

    ui->setupUi(this);


    ui->scrollArea->setWidget(renderArea);
    ui->scrollArea->setWidgetResizable(true);
    setCentralWidget(ui->scrollArea);
    QGridLayout *layout = new QGridLayout;
    vitesseSlider = new QSlider(Qt::Horizontal, this);
    vitesseSlider->setMinimumWidth(200);
    vitesseSlider->setMaximumWidth(250);
    vitesseSlider->setRange(1,500);
	vitesseSlider->setValue(400);
    ui->mainToolBar->addWidget(vitesseSlider);
    QObject::connect(ui->actionNew_AutoCell, &QAction::triggered, newCellDialog ,&NewAutoCell::show );
    QObject::connect(ui->actionOpen_AutoCell, &QAction::triggered, openCellDialog, &OpenAutoCell::show);
    QObject::connect(ui->actionplay, &QAction::toggled,renderArea , &RenderArea::playIsChecked);
	QObject::connect(ui->actionprevious, &QAction::triggered, renderArea, &RenderArea::previous);
	QObject::connect(ui->actiongenerate_randomly, &QAction::triggered, renderArea, &RenderArea::generate_randomly);
    QObject::connect(ui->actionnext, &QAction::triggered,renderArea , &RenderArea::next);
    QObject::connect(renderArea, &RenderArea::pause ,this, &MainWindow::pause);
    QObject::connect(newCellDialog, &NewAutoCell::accepted,this ,&MainWindow::createNewAutoCell );
    QObject::connect(openCellDialog, &OpenAutoCell::accepted, this, &MainWindow::openAutoCell);
    QObject::connect(ui->actionSave_AutoCell, &QAction::triggered, this, &MainWindow::saveAutoCell);
    QObject::connect(vitesseSlider, &QSlider::valueChanged, renderArea, &RenderArea::changeVitesse);
	QObject::connect(ui->actionreinit, &QAction::triggered, renderArea, &RenderArea::reinit);

	renderArea->changeVitesse(vitesseSlider->value());


}

void MainWindow::pause()
{
    ui->actionplay->setChecked(false);
}

void MainWindow::createNewAutoCell()
{

    if(newCellDialog->getType()=="Simple one dimension")
    {
		renderArea->setAutoCell(new OneD(newCellDialog->getWidth(),10,10,2,newCellDialog->getRule(),3));

    }
    else if(newCellDialog->getType()=="Game of life")
    {
		renderArea->setAutoCell(new jeuVie(newCellDialog->getHeight(),newCellDialog->getWidth(),10,10,newCellDialog->getNbMinVoisins(),newCellDialog->getNbMaxVoisins()));
        ui->actionprevious->setVisible(true);
    }

    else if(newCellDialog->getType()=="Quad life")
    {
		renderArea->setAutoCell(new QuadLife(newCellDialog->getHeight(),newCellDialog->getWidth(),10,10,newCellDialog->getNbMinVoisins(),newCellDialog->getNbMaxVoisins()));
        ui->actionprevious->setVisible(true);
    }

    ui->actionplay->setEnabled(true);
    ui->actionnext->setEnabled(true);

}

void MainWindow::openAutoCell(){
    Xml_Dom dom;
    dom.readFile(openCellDialog->getFileName());
    //qDebug(openCellDialog->getFileName().toLatin1());
    openCellDialog->setFile(&dom);
    //qDebug() << dom.getNoeud("type");
    if(openCellDialog->getFile().getNoeud("type") == "oneD")
        renderArea->setAutoCell(new OneD(openCellDialog->getFile().getNoeud("width").toInt()));
    else if (openCellDialog->getFile().getNoeud("type") == "jeuVie")
        renderArea->setAutoCell(new jeuVie(openCellDialog->getFile().getNoeud("height").toInt(), openCellDialog->getFile().getNoeud("width").toInt(), 10, 10, openCellDialog->getFile().getNoeud("nbMinVoisins").toInt(), openCellDialog->getFile().getNoeud("nbMaxVoisins").toInt() ));
    else if (openCellDialog->getFile().getNoeud("type") == "quadLife")
        renderArea->setAutoCell(new QuadLife(openCellDialog->getFile().getNoeud("height").toInt(), openCellDialog->getFile().getNoeud("width").toInt(), 10, 10, openCellDialog->getFile().getNoeud("nbMinVoisins").toInt(), openCellDialog->getFile().getNoeud("nbMaxVoisins").toInt()));
    else
        qDebug("échec de la quête");
    //qDebug() << renderArea->getAutoCell()->getWidth();
}

void MainWindow::saveAutoCell(){
    Xml_Dom dom;
    if(newCellDialog->getType()=="Simple one dimension"){
        dom.setNoeud("type", "oneD");
    }
    else if (newCellDialog->getType()=="Game of life"){
        dom.setNoeud("type", "jeuVie");
        dom.setNoeud("nbMaxVoisins", QString::number(newCellDialog->getNbMaxVoisins()));
        dom.setNoeud("nbMinVoisins", QString::number(newCellDialog->getNbMinVoisins()));
    }
    else{
        dom.setNoeud("type", "quadLife");
        dom.setNoeud("nbMaxVoisins", QString::number(newCellDialog->getNbMaxVoisins()));
        dom.setNoeud("nbMinVoisins", QString::number(newCellDialog->getNbMinVoisins()));
    }
    dom.setNoeud("width", QString::number(newCellDialog->getWidth()));
    dom.setNoeud("height", QString::number(newCellDialog->getHeight()) );
    dom.setNoeud("rule", QString::number(newCellDialog->getRule()));

    dom.writeFile(newCellDialog->getName());
}



MainWindow::~MainWindow()
{
    delete ui;
}


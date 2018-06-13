#include "openautocell.h"
#include "ui_openautocell.h"
#include <QDebug>

OpenAutoCell::OpenAutoCell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenAutoCell)
{
    ui->setupUi(this);
    file = nullptr;
    //QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(loadFile()) );
    QObject::connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(loadFileName()));
}

OpenAutoCell::~OpenAutoCell()
{
    delete ui;
}

const Xml_Dom &OpenAutoCell::getFile() const
{
    return *file;
}

void OpenAutoCell::loadFileName()
{
    QString fileName=QFileDialog::getOpenFileName(this, tr("Open File Name"), "./", tr("XML Files (*.xml)"));
    ui->lineEdit->setText(fileName);
}

QString OpenAutoCell::getFileName() const
{
    return ui->lineEdit->text();
}

void OpenAutoCell::setFile(const Xml_Dom *value)
{
    file = value;
}


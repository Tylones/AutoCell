#include "newautocell.h"
#include "ui_newautocell.h"

NewAutoCell::NewAutoCell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAutoCell)
{
    ui->setupUi(this);
}

NewAutoCell::~NewAutoCell()
{
    delete ui;
}

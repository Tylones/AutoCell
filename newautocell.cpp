#include "newautocell.h"
#include "ui_newautocell.h"

NewAutoCell::NewAutoCell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAutoCell)
{
    ui->setupUi(this);
    if(ui->comboBox->currentText()=="Simple one dimension")
    {
     ui->dHeight->setValue(1);
     ui->dHeight->setEnabled(false);
    }
    QObject::connect(ui->comboBox, &QComboBox::currentTextChanged,this ,&NewAutoCell::typeChanged );

}

NewAutoCell::~NewAutoCell()
{
    delete ui;
}

void NewAutoCell::typeChanged(QString s){
   if(s=="Simple one dimension")
   {
    ui->dHeight->setValue(1);
    ui->dHeight->setEnabled(false);
   }
   else
   {
       ui->dHeight->setValue(1);
       ui->dHeight->setEnabled(true);
   }

}

QString NewAutoCell::getType() const
{
    return ui->comboBox->currentText();
}

QString NewAutoCell::getName() const
{
    return ui->lineEdit->text();
}


int NewAutoCell::getHeight() const
{
    return ui->dHeight->value();
}

int NewAutoCell::getWidth() const
{
    return ui->dWidth->value();
}


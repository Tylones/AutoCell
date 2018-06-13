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
		ui->nbMinVoisins->setEnabled(false);
		ui->nbMaxVoisins->setEnabled(false);
	}
	QObject::connect(ui->comboBox, &QComboBox::currentTextChanged,this ,&NewAutoCell::typeChanged );

}

NewAutoCell::~NewAutoCell()
{
	delete ui;
}

int NewAutoCell::getNbMinVoisins() const
{
	return ui->nbMinVoisins->value();
}

int NewAutoCell::getNbMaxVoisins() const
{
	return ui->nbMaxVoisins->value();
}

int NewAutoCell::getRule() const
{
	return ui->nRule->value();
}

void NewAutoCell::typeChanged(QString s){
	if(s=="Simple one dimension")
	{
		ui->nRule->setEnabled(true);
		ui->dHeight->setValue(1);
		ui->dHeight->setEnabled(false);
		ui->nbMinVoisins->setEnabled(false);
		ui->nbMaxVoisins->setEnabled(false);
	}
	else
	{
		ui->nRule->setEnabled(false);
		ui->dHeight->setValue(1);
		ui->dHeight->setEnabled(true);
		ui->nbMinVoisins->setValue(2);
		ui->nbMinVoisins->setEnabled(true);
		ui->nbMaxVoisins->setValue(3);
		ui->nbMaxVoisins->setEnabled(true);
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


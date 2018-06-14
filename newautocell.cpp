#include "newautocell.h"
#include "ui_newautocell.h"

NewAutoCell::NewAutoCell(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NewAutoCell)
{

	ui->setupUi(this);
	if(ui->comboBox->currentText()=="Simple one dimension")
	{

		ui->dWidth->setValue(25);

		ui->dHeight->setVisible(false);
		ui->dHeight->setEnabled(false);
		ui->labelHeight->setVisible(false);
		ui->labelMin->setVisible(false);
		ui->nbMinVoisins->setVisible(false);
		ui->labelMax->setVisible(false);
		ui->nbMaxVoisins->setVisible(false);

	}
	QObject::connect(ui->comboBox, &QComboBox::currentTextChanged,this ,&NewAutoCell::typeChanged );
  QObject::connect(ui->lineEdit, &QLineEdit::textChanged, this, &NewAutoCell::nameChanged);

}

NewAutoCell::~NewAutoCell()
{
	delete ui;
}

void NewAutoCell::typeChanged(QString s){
	ui->dHeight->setValue(50);
	ui->dWidth->setValue(50);
	if(s=="Simple one dimension")
	{
		ui->nRule->setEnabled(true);
		ui->dHeight->setEnabled(false);
		ui->nbMinVoisins->setEnabled(false);
		ui->nbMaxVoisins->setEnabled(false);

		ui->dHeight->setVisible(false);
		ui->dHeight->setEnabled(false);
		ui->labelHeight->setVisible(false);
		ui->labelMin->setVisible(false);
		ui->nbMinVoisins->setVisible(false);
		ui->labelMax->setVisible(false);
		ui->nbMaxVoisins->setVisible(false);

		ui->labelRule->setVisible(true);
		ui->nRule->setVisible(true);
	}
	else
	{
		ui->dHeight->setVisible(true);
		ui->dHeight->setEnabled(true);
		ui->labelHeight->setVisible(true);
		ui->labelMin->setVisible(true);
		ui->nbMinVoisins->setVisible(true);
		ui->labelMax->setVisible(true);
		ui->nbMaxVoisins->setVisible(true);

		ui->nRule->setEnabled(false);
		ui->nbMinVoisins->setValue(2);
		ui->nbMinVoisins->setEnabled(true);
		ui->nbMaxVoisins->setValue(3);
		ui->nbMaxVoisins->setEnabled(true);

		ui->dHeight->setEnabled(true);

		ui->labelRule->setVisible(false);
		ui->nRule->setVisible(false);
	}

}

void NewAutoCell::nameChanged()
{
    /*if(ui->lineEdit->text()=="")
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);*/
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



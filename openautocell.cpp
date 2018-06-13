#include "openautocell.h"
#include "ui_openautocell.h"

OpenAutoCell::OpenAutoCell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenAutoCell)
{
    ui->setupUi(this);
    file = nullptr;
    QPushButton* okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(&OpenAutoCell::loadFile()) );

}

OpenAutoCell::~OpenAutoCell()
{
    delete ui;
}

const Xml_Dom &OpenAutoCell::getFile() const
{
    return *file;
}

void OpenAutoCell::loadFile()
{
    Xml_Dom dom(ui->comboBox->currentText() + ".xml");
    file = &dom;
}


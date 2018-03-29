#ifndef NEWAUTOCELL_H
#define NEWAUTOCELL_H

#include <QDialog>

namespace Ui {
class NewAutoCell;
}

class NewAutoCell : public QDialog
{
    Q_OBJECT

public:
    explicit NewAutoCell(QWidget *parent = 0);
    ~NewAutoCell();

private:
    Ui::NewAutoCell *ui;
};

#endif // NEWAUTOCELL_H

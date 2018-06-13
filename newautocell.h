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



    int getWidth() const;

    int getHeight() const;

    QString getName() const;

    QString getType() const;

public slots:
    void typeChanged(QString s);


private:
    Ui::NewAutoCell *ui;

};

#endif // NEWAUTOCELL_H

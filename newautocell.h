#ifndef NEWAUTOCELL_H
#define NEWAUTOCELL_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class NewAutoCell;
}
/*!
 * \brief Cette classe est une fenêtre de dialogue servant à créer de nouveaux automates cellulaires
 * et à choisir leurs configuration (taille, nombre de voisins...etc)
 */
class NewAutoCell : public QDialog
{
    Q_OBJECT

public:
    explicit NewAutoCell(QWidget *parent = 0);
    ~NewAutoCell();


	int getNbMinVoisins () const;

	int getNbMaxVoisins () const;

	int getRule() const;


    int getWidth() const;

    int getHeight() const;

    QString getName() const;

    QString getType() const;

public slots:
    void typeChanged(QString s);
    void nameChanged();

private:
    Ui::NewAutoCell *ui;

};

#endif // NEWAUTOCELL_H

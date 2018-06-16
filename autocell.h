#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QVector>
#include <QPoint>
#include "etat.h"

class AutoCell
{

public:
    QVector<QVector<int> > getMatrice() const;
	AutoCell(int width = 10, int height=10, int cellStates=2, int nb_neighborhood=3, QString name="");

    void setMatrice(const QVector<QVector<int> > &value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getCellWidth() const;
    void setCellWidth(int value);

    int getCellHeight() const;
    void setCellHeight(int value);

	void setValueEtat(int numEtat, int i, int j, int val);

	void reinit();

	virtual	void previous() = 0;



    QVector<QVector<int> > getNeighborhood() const;
    void setNeighborhood(const QVector<QVector<int> > &value);

    virtual void changeCellState(QPoint point)=0;

    virtual void nextState()=0;

    int getCurrentState() const;
    void setCurrentState(int value);

	QVector<Etat> getEtats() const;
    void setEtats(const QVector<Etat> &value);
	virtual void generateRandomly() = 0;
	const static int nbMaxEtats = 10;

	QString getName() const;
	void setName(const QString &value);

protected:

	QVector< Etat > etats;
	Etat etatInitial;
	QString name;
    int width;
    int height;
    int cellStates;
    int currentState;
    QVector< QVector <int> > neighborhood;

};

#endif // AUTOCELL_H

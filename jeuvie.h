#ifndef JEUVIE_H
#define JEUVIE_H
#include "autocell.h"
#include <QVector>
#include <QDebug>

class jeuVie : public AutoCell
{

public:
	jeuVie(int height = 100, int width=100, int cellWidth=10, int cellHeight=10,int nbMinVoisins=2,int nbMaxVoisins=3, QString name="");
	void changeCellState(const QPoint point);
	void nextState();
	virtual void generateRandomly();

	int getNbMinVoisins() const;
	void setNbMinVoisins(int value);

	int getNbMaxVoisins() const;
	void setNbMaxVoisins(int value);

	void previous();

private:
	bool willBorn(int x, int y, Etat etat);
	int nbMinVoisins;
	int nbMaxVoisins;
};

#endif // JEUVIE_H

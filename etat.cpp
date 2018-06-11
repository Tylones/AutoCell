#include "etat.h"



void Etat::setSize(int height, int width)
{
	matrice.resize(height);
	for(int i = 0; i < matrice.size(); i++)
		matrice[i].resize(width);
}

void Etat::setMatrice(const QVector<QVector<int> > &value)
{
	matrice = value;
}

void Etat::setValue(int x, int y, int val)
{
	matrice[x][y]=val;
}

void Etat::pushBack(int height)
{
	matrice.push_back(QVector < int > (height));
}

void Etat::pushFront(int height)
{
	matrice.push_front(QVector < int > (height));
}


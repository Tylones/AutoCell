#include "autocell.h"

AutoCell::AutoCell(int width,int height, int cellWidth, int cellHeight,int cellStates,int nb_neighborhood, QString name):
	width(width),height(height),cellWidth(cellWidth),cellHeight(cellHeight),cellStates(cellStates),
	currentState(0),etats(0),neighborhood(QVector< QVector <int> >(nb_neighborhood, QVector<int>(1))),
	name(name)
{
    if(height>1)
    {
        neighborhood.push_back(QVector<int>(nb_neighborhood));
    }

	etats.push_back(Etat(height,width));
}

QVector<QVector<int> >AutoCell::getMatrice() const
{
	return etats.last().getMatrice();
}

//void AutoCell::setMatrice(const QVector<QVector<int> > &value)
//{
//    matrice = value;
//}

int AutoCell::getWidth() const
{
    return width;
}

void AutoCell::setWidth(int value)
{
    width = value;
}

int AutoCell::getHeight() const
{
    return height;
}

void AutoCell::setHeight(int value)
{
    height = value;
}

int AutoCell::getCellWidth() const
{
    return cellWidth;
}

void AutoCell::setCellWidth(int value)
{
    cellWidth = value;
}

int AutoCell::getCellHeight() const
{
    return cellHeight;
}

void AutoCell::setCellHeight(int value)
{
	cellHeight = value;
}

void AutoCell::setValueEtat(int numEtat, int i, int j, int val)
{
	if(numEtat >= etats.size())
		etats.push_back(Etat(etats[0].getMatrice().size(),etats[0].getMatrice()[0].size()));
	etats[numEtat].setValue(i,j,val);
}

void AutoCell::reinit()
{
	while(!etats.isEmpty())
		etats.pop_front();
	Etat e = etatInitial;
	etats.push_back(e);
	currentState=0;
}


QVector<QVector<int> > AutoCell::getNeighborhood() const
{
    return neighborhood;
}

void AutoCell::setNeighborhood(const QVector<QVector<int> > &value)
{
    neighborhood = value;
}

int AutoCell::getCurrentState() const
{
    return currentState;
}

void AutoCell::setCurrentState(int value)
{
    currentState = value;
}

QVector<Etat> AutoCell::getEtats() const
{
    return etats;
}

void AutoCell::setEtats(const QVector<Etat> &value)
{
    etats = value;
}

QString AutoCell::getName() const
{
	return name;
}

void AutoCell::setName(const QString &value)
{
	name = value;
}

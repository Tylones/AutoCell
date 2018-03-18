#include "autocell.h"

AutoCell::AutoCell(int width,int height, int cellWidth, int cellHeight,int cellStates,int currentState):width(width),height(height),cellWidth(cellWidth),cellHeight(cellHeight),cellStates(cellStates),currentState(currentState),matrice(QVector< QVector <int> >(width, QVector<int>(height))),neighborhood(QVector< QVector <int> >(2, QVector<int>(1)))
{

}

QVector<QVector<int> >AutoCell::getMatrice() const
{
    return matrice;
}

void AutoCell::setMatrice(const QVector<QVector<int> > &value)
{
    matrice = value;
}

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

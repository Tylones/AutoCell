#include<QVector>
#ifndef ETAT_H
#define ETAT_H


class Etat
{

    QVector< QVector <int> > matrice;

public:
    Etat(int width, int height):matrice(width,height){};

    QVector<QVector<int> > getMatrice() const{return matrice;}
    void setMatrice(const QVector<QVector<int> > &value);
};

#endif // ETAT_H

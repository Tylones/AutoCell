#include<QVector>
#ifndef ETAT_H
#define ETAT_H


class Etat
{

    QVector< QVector <int> > matrice;

public:
	Etat():matrice(0){}
	Etat(int width, int height):matrice(width){
		for(int i = 0; i < matrice.size(); i++)
			matrice[i].resize(height);
	}
	void setSize(int, int);
	const QVector<QVector<int> >& getMatrice() const{return matrice;}
    void setMatrice(const QVector<QVector<int> > &value);
	void setValue(int x, int y, int val);
	void pushBack(int);
	void pushFront(int);
};

#endif // ETAT_H

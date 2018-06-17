#include<QVector>
#ifndef ETAT_H
#define ETAT_H


class Etat
{
	/*!
	 * \brief matrice de integer contenant l'état de chaque cellule
	 */
    QVector< QVector <int> > matrice;

public:
	Etat():matrice(0){}
	/*!
	 * \brief Constructeur d'Etat construisant une mamtrice de hauteur et largeur passées en paramètre
	 * \param width : largeur
	 * \param height : hauteur
	 */
	Etat(int width, int height):matrice(width){
		for(int i = 0; i < matrice.size(); i++)
			matrice[i].resize(height);
	}

	/*!
	 * \brief redimmensionne la matrice à une certaine taiile
	 */
	void setSize(int, int);
	const QVector<QVector<int> >& getMatrice() const{return matrice;}
    void setMatrice(const QVector<QVector<int> > &value);

	/*!
	 * \brief affecte une valeur à une case de la matrice
	 * \param x : numéro de ligne
	 * \param y : numéro de colonne
	 * \param val : valeur
	 */
	void setValue(int x, int y, int val);

	/*!
	 * \brief Rajoute une colonne à la fin de la matrice
	 */
	void pushBack(int);
	/*!
	 * \brief Rajoute une colonne au début de la matrice
	 */
	void pushFront(int);
};

#endif // ETAT_H

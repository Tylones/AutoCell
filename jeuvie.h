#ifndef JEUVIE_H
#define JEUVIE_H
#include "autocell.h"
#include <QVector>
#include <QDebug>

class jeuVie : public AutoCell
{

public:
	jeuVie(int height = 100, int width=100, int nbMinVoisins=2,int nbMaxVoisins=3, QString name="");
	/*!
	 * \brief Cette fonction permet de changer l'état d'une cellule
	 * \param point : QPoint récupéré lors du clic de l'utilisateur sur la render Area
	 */
	void changeCellState(const QPoint point);

	/*!
	 * \brief Cette fonction permet à l'automate de passer à l'état suivant
	 */
	void nextState();
	/*!
	 * \brief remplit aléatoirement la matrice de l'automate
	 */
	virtual void generateRandomly();

	int getNbMinVoisins() const;
	void setNbMinVoisins(int value);

	int getNbMaxVoisins() const;
	void setNbMaxVoisins(int value);
	/*!
	 * \brief Permet de repasser à l'état précédent, virtuelle car la méthode varie en fonction de la dimension de l'automate
	 */
	void previous();

private:
	/*!
	 * \brief Calcule si une cellule va être vivante lors de la prochaine génération
	 * \param x : coordonnée x (numéro de ligne)
	 * \param y : coordonnée y (numéro de colonne)
	 * \param etat : l'etat sur lequel effectuer le calcu
	 * \return retourne true si la cellule sera en vie, false sinon
	 */
	bool willBorn(int x, int y, Etat etat);
	/*!
	 * \brief nombre minimum de voisin pour qu'une cellule vivante reste en vie lors de la prochaine génération
	 */
	int nbMinVoisins;
	/*!
	 * \brief nombre minimum de voisin pour qu'une cellule vivante reste en vie lors de la prochaine génération
	 * nombre de voisins nécessaire pour qu'une cellule morte naisse lors de la prochaine génération
	 */
	int nbMaxVoisins;
};

#endif // JEUVIE_H

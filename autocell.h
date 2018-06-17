#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QVector>
#include <QPoint>
#include "etat.h"


/*!
 * \brief Cette classe abstraite est la classe mère de tous les automates cellulaires,
 * elle contient plusieurs attributs et méthodes nécessaires au bon fonctionnement de l'application
 * et facilitant l'ajout de nouveaux automates cellulaires
 */
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

	/*!
	 * \brief affecte une valeur à une cellule d'un état particulier
	 * \param numEtat : numéro de l'état à modifier
	 * \param i : indice de ligne
	 * \param j : indice de colonne
	 * \param val : valeur
	 */
	void setValueEtat(int numEtat, int i, int j, int val);

	/*!
	 * \brief réinitialise l'automate à son état initial
	 */
	void reinit();

	/*!
	 * \brief l'automate retourne à son état précédent
	 */
	virtual	void previous() = 0;



    QVector<QVector<int> > getNeighborhood() const;
    void setNeighborhood(const QVector<QVector<int> > &value);

	/*!
	 * \brief Cette fonction permet de changer l'état d'une cellule
	 * \param point : QPoint récupéré lors du clic de l'utilisateur sur la render Area
	 */
    virtual void changeCellState(QPoint point)=0;

	/*!
	 * \brief Cette fonction permet à l'automate de passer à l'état suivant
	 * Ce calcul étant propre à chaque automate, cette fonction est virtuelle
	 */
    virtual void nextState()=0;

    int getCurrentState() const;
    void setCurrentState(int value);

	QVector<Etat> getEtats() const;
    void setEtats(const QVector<Etat> &value);
	/*!
	 * \brief remplit aléatoirement la matrice de l'automate
	 */
	virtual void generateRandomly() = 0;
	/*!
	 * \brief nombre max d'états stockés dans le vecteur d'état. On le limite à 10 pour des raisons de performance
	 */
	const static int nbMaxEtats = 10;

	QString getName() const;
	void setName(const QString &value);

protected:
	/*!
	 * \brief vecteur stockant les différents états générés, permettant de naviguer parmis ceux-ci
	 */
	QVector< Etat > etats;
	/*!
	 * \brief etat de la matrice avant la première génération
	 */
	Etat etatInitial;
	/*!
	 * \brief Nom de l'automate
	 */
	QString name;
	/*!
	 * \brief largeur de l'automate
	 */
    int width;
	/*!
	 * \brief hauteur de l'automate
	 */
    int height;
	/*!
	 * \brief nombre d'états des cellules
	 */
    int cellStates;
	/*!
	 * \brief nombre d'états générés depuis l'état initial
	 */
    int currentState;
	/*!
	 * \brief voisinage
	 */
    QVector< QVector <int> > neighborhood;

};

#endif // AUTOCELL_H

#ifndef ONED_H
#define ONED_H
#include "autocell.h"
#include <QVector>
#include <QDebug>
#include<cmath>

/*!
 * \brief Cette classe est un automate cellulaire (donc héritant de la classe AutoCell),
 * se servant d'un numéro de règle allant de 0 à 255 pour calculer l'état de ses cellules
 * lors de nouvelle générations
 */

class OneD : public AutoCell
{
public:



	OneD(int width=100, int nbEtats=2,int r=126,int nb_neighborhood=3, QString name="");
	/*!
	 * \brief Cette fonction permet de changer l'état d'une cellule
	 * \param point : QPoint récupéré lors du clic de l'utilisateur sur la render Area
	 */
    void changeCellState(const QPoint point);
	/*!
	 * \brief Cette fonction permet à l'automate de passer à l'état suivant
	 */
    void nextState();
    QVector<int> getRules() const;
    void setRules(const QVector<int> &value);
	/*!
	 * \brief remplit le tableau de règles
	 * \param n : numéro de règle
	 */
    void setRules(const int n);
	/*!
	 * \brief remplit aléatoirement la matrice de l'automate
	 */
	void generateRandomly();
	/*!
	 * \brief Permet de repasser à l'état précédent, virtuelle car la méthode varie en fonction de la dimension de l'automate
	 */
	void previous();
	int getRule() const;
protected:
	static QVector< QVector < QVector <int> > > rulesTab;
    QVector<int>rule;
	static QVector < QVector < QVector <int> > >makeRules();



signals:





};

#endif // ONED_H

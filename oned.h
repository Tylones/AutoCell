#ifndef ONED_H
#define ONED_H
#include "autocell.h"
#include <QVector>
#include <QDebug>
#include<cmath>

class OneD : public AutoCell
{
public:



	OneD(int width=100, int nbEtats=2,int r=126,int nb_neighborhood=3, QString name="");

    void changeCellState(const QPoint point);
    void nextState();
    QVector<int> getRules() const;
    void setRules(const QVector<int> &value);
    void setRules(const int n);
	void generateRandomly();
	void previous();
	int getRule() const;
protected:
	static QVector< QVector < QVector <int> > > rulesTab;
    QVector<int>rule;
	static QVector < QVector < QVector <int> > >makeRules();



signals:





};

#endif // ONED_H

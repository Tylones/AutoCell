#ifndef ONED_H
#define ONED_H
#include "autocell.h"
#include <QVector>
#include <QDebug>

class OneD : public AutoCell
{
public:

    OneD(int width=100, int cellWidth=10, int cellHeight=10,int nbEtats=2,int r=126,int nb_neighborhood=3);

    void changeCellState(const QPoint point);
    void nextState();
    QVector<int> getRules() const;
    void setRules(const QVector<int> &value);
    void setRules(const int n);


protected:
    static QVector< QVector < QVector <int>> > rulesTab;
    QVector<int>rule;
    static QVector < QVector < QVector <int>> >makeRules();



signals:





};

#endif // ONED_H

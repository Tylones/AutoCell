#include "oned.h"

QVector < QVector < QVector <int>> > OneD::rulesTab=makeRules();

QVector < QVector < QVector <int>> >OneD::makeRules(){

    QVector < QVector < QVector <int>> > rules(256, QVector<QVector<int>>(9, QVector<int>(3)));
    //rules[0].push_back(QVector<int>(3));
    rules[0][0][0]=0;
    rules[0][0][1]=0;
    rules[0][0][2]=0;

    rules[0][1][0]=1;
    rules[0][1][1]=0;
    rules[0][1][2]=0;

    rules[0][2][0]=0;
    rules[0][2][1]=1;
    rules[0][2][2]=0;

    rules[0][3][0]=1;
    rules[0][3][1]=1;
    rules[0][3][2]=0;

    rules[0][4][0]=0;
    rules[0][4][1]=0;
    rules[0][4][2]=1;

    rules[0][5][0]=1;
    rules[0][5][1]=0;
    rules[0][5][2]=1;

    rules[0][6][0]=0;
    rules[0][6][1]=1;
    rules[0][6][2]=1;

    rules[0][7][0]=1;
    rules[0][7][1]=1;
    rules[0][7][2]=1;

    for(int i= 1;i<256;i++){
        int nb=i;
        for(int j=0;j<8;j++)
        {
            rules[i][7-j][0]=nb%2;
            nb=nb/2;
        }
}

    return rules;

}

QVector<int> OneD::getRules() const
{
    return rule;
}

void OneD::setRules(const int n)
{
    rule = OneD::rulesTab[n][0];
}

OneD::OneD(int width, int cellWidth, int cellHeight,int cellStates,int r,int nb_neighborhood):AutoCell(width,1,cellWidth,cellHeight,cellStates,nb_neighborhood),rule(QVector<int>(8))
{
    for(int i=0;i<8;i++)
    rule[7-i]=rulesTab[r][i][0];

    neighborhood[0][0]=-1;
    neighborhood[1][0]=0;
    neighborhood[2][0]=1;
}

void OneD::nextState()
{
    for (int i=0; i<width; i++)
    {
        int index;

        if(i<1)
            index=matrice[i+neighborhood[1][0]][currentState]*2+matrice[i+neighborhood[2][0]][currentState];

        else if(i>=width-2)
            index =matrice[i+neighborhood[0][0]][currentState]*4+matrice[i+neighborhood[1][0]][currentState]*2;

        else
            index=matrice[i+neighborhood[0][0]][currentState]*4+matrice[i+neighborhood[1][0]][currentState]*2+matrice[i+neighborhood[2][0]][currentState];

        matrice[i].push_back(rule[index]);
    }

    currentState++;
    height++;

    if(matrice[1][currentState]==1)
    {
        width++;
        matrice.push_front(QVector <int>(height));
    }

    if(matrice[width-1][currentState]==1)
    {
        width++;
        matrice.push_back(QVector <int>(height));
    }

}

void OneD::changeCellState(const QPoint point)
{

   if(point.x()/cellWidth < width && point.y()/cellHeight < height)
   {
       if(matrice[(point.x())/cellWidth][(point.y())/cellHeight]==1)
           matrice[(point.x())/cellWidth][(point.y())/cellHeight]=0;

       else
           matrice[(point.x())/cellWidth][(point.y())/cellHeight]=1;
   }
}


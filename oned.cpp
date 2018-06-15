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

void OneD::generateRandomly()
{
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
		  etats.last().setValue(i,j,rand()%2);
		}
	  }
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
	if(currentState == 0)
		etatInitial = etats[0];
	currentState++;
    height++;
    Etat etat(1,width);
    QVector<QVector <int>> lastMat= etats.last().getMatrice();

	for(int i = 0; i < width; i++){
		int index;
		if(i==0)
            index = lastMat[0][i]*2 + lastMat[0][i+1];
		else if(i == width-1)
            index = lastMat[0][i - 1]*4 + lastMat[0][i]*2;
		else
            index = lastMat[0][i - 1]*4 + lastMat[0][i]*2 + lastMat[0][i+1];
        etat.setValue(0,i,rule[index]);
	}

	etats.push_back(etat);

}

void OneD::changeCellState(const QPoint point)
{

   if(point.x() < width && point.y() < height)
   {
	   int x = point.x();
	   int y = point.y();
	   if(etats.last().getMatrice()[y][x]==1)
		   etats.last().setValue(y,x,0);

	   else{
		   //etats.last().getMatrice()[(point.x())/cellWidth][(point.y())/cellHeight]=1;

		   etats.last().setValue(y,x,1);

	   }
   }
}


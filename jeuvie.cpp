#include "jeuvie.h"



jeuVie::jeuVie(int height, int width, int cellWidth, int cellHeight, int nbEtats, int nb_neighborhood) : AutoCell(width, height, cellWidth, cellHeight, cellStates,3)
{
	etats.push_back(Etat(height,width));
}

void jeuVie::changeCellState(const QPoint point)
{
	if(point.x()/cellWidth < width && point.y()/cellHeight < height)
	{
		int x = point.x()/cellWidth;
		int y = point.y()/cellHeight;
		if(etats.last().getMatrice()[y][x]==1)
			etats.last().setValue(y,x,0);

		else{
			//etats.last().getMatrice()[(point.x())/cellWidth][(point.y())/cellHeight]=1;

			etats.last().setValue(y,x,1);

		}
	}

}

void jeuVie::nextState()
{
	currentState++;
	Etat etat(height, width);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			etat.setValue(i,j,willBorn(i,j,etats.last()));
			qDebug() << "i = " << i << "//" << "j = " << j;
		}
	}
	etats.push_back(etat);
}

bool jeuVie::willBorn(int x, int y, Etat etat)
{
	int n = 0;
	if(y > 0){
		n +=  etat.getMatrice()[x][y-1];
		if(x > 0)
			n += etat.getMatrice()[x-1][y-1];
		if(x < height-1)
			n += etat.getMatrice()[x+1][y-1];
	}
	if(y < width-1){
		n +=  etat.getMatrice()[x][y+1];
		if(x > 0)
			n += etat.getMatrice()[x-1][y+1];
		if(x < height-1)
			n += etat.getMatrice()[x+1][y+1];
	}
	if(x > 0)
		n += etat.getMatrice()[x-1][y];
	if(x < height-1)
		n += etat.getMatrice()[x+1][y] ;
	return((etat.getMatrice()[x][y]==1 && (n == 2 || n == 3)) || (etat.getMatrice()[x][y] == 0 && n == 3));
}



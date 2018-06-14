#include "jeuvie.h"



jeuVie::jeuVie(int height, int width, int cellWidth, int cellHeight, int nbMinVoisins, int nbMaxVoisins) : AutoCell(width, height, cellWidth, cellHeight, cellStates,3), nbMinVoisins(nbMinVoisins), nbMaxVoisins(nbMaxVoisins)
{

}

void jeuVie::changeCellState(const QPoint point)
{
	if(point.x() < width && point.y() < height)
	{
		int x = point.x();
		int y = point.y();
        if(etats[currentState%nbMaxEtats].getMatrice()[y][x]==1)
            etats[currentState%nbMaxEtats].setValue(y,x,0);

		else{
			//etats.last().getMatrice()[(point.x())/cellWidth][(point.y())/cellHeight]=1;

            etats[currentState%nbMaxEtats].setValue(y,x,1);

		}
	}

}

void jeuVie::nextState()
{
	Etat etat(height, width);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			etat.setValue(i,j,willBorn(i,j,etats[(currentState)%nbMaxEtats]));
		}
    }
	currentState++;

    if(currentState<nbMaxEtats)
		etats.push_back(etat);

    else
		etats[currentState%nbMaxEtats]=etat;
}

void jeuVie::generateRandomly()
{
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
          etats[currentState%nbMaxEtats].setValue(i,j,rand()%2);
		}
	  }
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
	//return((etat.getMatrice()[x][y]==1 && (n == 2 || n == 3)) || (etat.getMatrice()[x][y] == 0 && n == 3));
	return((etat.getMatrice()[x][y]==1 && (n >= nbMinVoisins && n <= nbMaxVoisins)) || (etat.getMatrice()[x][y]==0 && n == nbMaxVoisins));

}



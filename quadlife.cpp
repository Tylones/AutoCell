#include "quadlife.h"
#include <algorithm>



QuadLife::QuadLife(int height, int width, int nbMinVoisins, int nbMaxVoisins, QString name) : AutoCell(width, height, cellStates,3, name), nbMinVoisins(nbMinVoisins), nbMaxVoisins(nbMaxVoisins)
{

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            etats.last().setValue(i,j,2);
        }
    }

}

void QuadLife::changeCellState(QPoint point)
{
	if(point.x() < width && point.y() < height)
	{
		int x = point.x();
		int y = point.y();
        int value = etats[currentState%nbMaxEtats].getMatrice()[y][x];
		if(value < 6)
            etats[currentState%nbMaxEtats].setValue(y,x,++value);

		else{
			//etats.last().getMatrice()[(point.x())/cellWidth][(point.y())/cellHeight]=1;

            etats[currentState%nbMaxEtats].setValue(y,x,2);

		}
	}
}

void QuadLife::nextState()
{
	if(currentState == 0)
		etatInitial = etats[0];
	Etat etat(height, width);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			int value = etats[currentState%nbMaxEtats].getMatrice()[i][j];
			int nextValue = 2;
			if(value == 2 && willBorn(i,j,etats[currentState%nbMaxEtats])){
				nextValue = getNextValue(i,j,etats[currentState%nbMaxEtats]);
//				qDebug() << "CA MARCHE SAOEZPIEA value = " << nextValue;
			}
			else if(value !=2 && willBorn(i,j,etats[currentState%nbMaxEtats])){
				nextValue = value;

			}
			else
				nextValue = 2;
			etat.setValue(i,j,nextValue);
			//qDebug() << "i = " << i << "//" << "j = " << j << "value : " << value;
		}
	}
	currentState++;

    if(currentState<nbMaxEtats)
		etats.push_back(etat);
    else
        etats[currentState%nbMaxEtats]=etat;
	// etats.pop_front(); // pour tester la ram
}

void QuadLife::generateRandomly()
{
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
		  int value = rand()%8;
		  if(value > 4)
			value = 0;
		  value +=2;
		  etats[currentState%nbMaxEtats].setValue(i,j,value);
		}
	  }
}

int QuadLife::getNextValue(int x, int y, Etat etat)
{
	int nb[5]={0,0,0,0,0},ind=1;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if(!(i == 0 && j == 0 )){
				if(!(x == 0 && i == -1) && !(x == height-1 && i == 1) && !(y == 0 && j == -1) && !(y == width-1 && j == +1))
					switch (etat.getMatrice()[x+i][y+j]) {
					case 3:
						nb[1]++;
						break;
					case 4:
						nb[2]++;
						break;
					case 5:
						nb[3]++;
						break;
					case 6:
						nb[4]++;
						break;
					default:
						break;
					}
			}
		}
	}
	for(int i = 2; i < 5; i++){
		if(nb[i] > nb[ind])
			ind = i;
		else if(nb[i] == nb[ind] && rand()%2==0)
			   ind = i;
	}
	return ind+2;
}

bool QuadLife::willBorn(int x, int y, Etat etat)
{
	int n = 0;
	if(y > 0){
		n +=  etat.getMatrice()[x][y-1]!=2;
		if(x > 0)
			n += etat.getMatrice()[x-1][y-1]!=2;
		if(x < height-1)
			n += etat.getMatrice()[x+1][y-1]!=2;
	}
	if(y < width-1){
		n +=  etat.getMatrice()[x][y+1]!=2;
		if(x > 0)
			n += etat.getMatrice()[x-1][y+1]!=2;
		if(x < height-1)
			n += etat.getMatrice()[x+1][y+1]!=2;
	}
	if(x > 0)
		n += etat.getMatrice()[x-1][y]!=2;
	if(x < height-1)
		n += etat.getMatrice()[x+1][y]!=2;
	//return((etat.getMatrice()[x][y]!=2 && (n == 2 || n == 3)) || (etat.getMatrice()[x][y]==2 && n == 3));
	return((etat.getMatrice()[x][y]!=2 && (n >= nbMinVoisins && n <= nbMaxVoisins)) || (etat.getMatrice()[x][y]==2 && n == nbMaxVoisins));

}

int QuadLife::getNbMaxVoisins() const
{
	return nbMaxVoisins;
}

void QuadLife::setNbMaxVoisins(int value)
{
	nbMaxVoisins = value;
}

void QuadLife::previous()
{
	if(currentState>1)
		currentState--;
}

int QuadLife::getNbMinVoisins() const
{
	return nbMinVoisins;
}

void QuadLife::setNbMinVoisins(int value)
{
	nbMinVoisins = value;
}

#include "Plateau.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>



using namespace std;

Plateau::Plateau()//Constructor
{
	dimensionX = 10;
	dimensionY = 10;
	grille = new char*[dimensionX];
	for(size_t i=0;i<dimensionX;i++)
	{
		grille[i]=new char[dimensionY];
		for(size_t j=0;j<dimensionY;j++)
		{
			grille[i][j]='_';
		}
	}
}

Plateau::Plateau(size_t x)
{
	dimensionX = x;
	dimensionY = x;
	grille = new char*[x];
	for(size_t i=0;i<x;i++)
	{
		grille[i]=new char[x];
		for(size_t j=0;j<x;j++)
		{
			grille[i][j]='_';
		}
	}
}

Plateau::Plateau(size_t x, size_t y)
{
	dimensionX = x;
	dimensionY = y;
	grille = new char*[x];
	for(size_t i=0;i<x;i++)
	{
		grille[i]=new char[y];
		for(size_t j=0;j<y;j++)
		{
			grille[i][j]='_';
		}
	}
}

Plateau::Plateau(size_t x, size_t y,char c)
{
	dimensionX = x;
	dimensionY = y;
	grille = new char*[x];
	for(size_t i=0;i<x;i++)
	{
		grille[i]=new char[y];
		for(size_t j=0;j<y;j++)
		{
			grille[i][j]= c;
		}
	}
}

Plateau::~Plateau(){
	for (size_t i = 0 ; i < dimensionX ; i++){
		delete[] grille[i];
	}
	delete[] grille;
}//Destructor

char** Plateau::initGrille(size_t x)
{
	grille = new char*[x];
	for(size_t i=0;i<x;i++)
	{
		grille[x]=new char[x];
		for(size_t j=0;j<x;j++)
		{
			grille[i][j]='0';
		}
	}
	return grille;
}

void Plateau::afficherGrille()
{
	for(size_t i=0;i<dimensionX;i++)
	{
		for(size_t j=0;j<dimensionY;j++)
		{
			cout << grille[i][j] << "\t";
		}
		cout << endl;
	}
}

bool Plateau::libre(int x1,int x2,int y1,int y2){
	int minx = min(x1,x2);
	int miny = min(y1,y2);
	int maxx = max(x1,x2);
	int maxy = max(y1,y2);

	if(x1 == x2){
		for(int i = miny; i < maxy + 1;i++){
			if((grille[x1][i] != '0')){
				cout<<"La zone choisie n'est pas libre!"<<endl;
				return false;
			}
		}
	}
	else{
		for(int j = minx; j < maxx + 1;j++){
			if((grille[j][x1] != '0')){
				cout<<"La zone choisie n'est pas libre!"<<endl;
				return false;
			}
		}
	}
	return true;
}

void Plateau::placeBatiment(int x1,int x2,int y1,int y2, char c){	//Place un bâtiment selon les coordonnées de ses extremités
	int minx = min(x1,x2);
	int miny = min(y1,y2);
	int maxx = max(x1,x2);
	int maxy = max(y1,y2);

	if(x1 == x2){
		for(int i = miny; i < maxy + 1;i++){
			grille[x1][i] = c;
		}
	}
	else{
		for(int j = minx; j < maxx + 1;j++){
			grille[j][y1] = c;
		}
	}
}

size_t Plateau::getDimensionX() const
{
	return dimensionX;
}

size_t Plateau::getDimensionY() const
{
	return dimensionX;
}

char Plateau::getPositionGrille(size_t i, size_t j) const
{
	return grille[i][j];
}

void Plateau::setGrille(int i, int j, char c){
	grille[i][j] = c;
}

std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau)
{
	out << "/\t";
	for(size_t j=0;j<elPlateau.getDimensionY();j++)
	{
		out << j << "\t";
	}
	out << endl;

	for(size_t i=0;i<elPlateau.getDimensionX();i++)
	{
		out<< i << "\t";
		for(size_t j=0;j<elPlateau.getDimensionY();j++)
		{
			out << elPlateau.getPositionGrille(i,j) << "\t";
		}
		out << endl;
	}
	return out ;//<< "Plateau" << endl);
}

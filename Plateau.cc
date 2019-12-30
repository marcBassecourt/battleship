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

std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau)
{
	for(size_t i=0;i<elPlateau.getDimensionX();i++)
	{
		for(size_t j=0;j<elPlateau.getDimensionY();j++)
		{
			out << elPlateau.getPositionGrille(i,j) << "\t";
		}
		out << endl;
	}
	return out ;//<< "Plateau" << endl);
}

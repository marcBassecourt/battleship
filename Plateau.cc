#include "Plateau.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

Plateau::Plateau()//Constructor
{
	dimension = 10;
	grille = new char*[dimension];
	for(size_t i=0;i<dimension;i++)
	{
		grille[i]=new char[dimension];
		for(size_t j=0;j<dimension;j++)
		{
			grille[i][j]='_';	
		}
	}
}

Plateau::Plateau(size_t x)
{
	dimension = x;
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

Plateau::~Plateau(){}//Destructor

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
	for(size_t i=0;i<dimension;i++)
	{
		for(size_t j=0;j<dimension;j++)
		{
			cout << grille[i][j] << "\t";	
		}
		cout << endl;
	}
}

size_t Plateau::getDimension() const
{
	return dimension;
}

char Plateau::getPositionGrille(size_t i, size_t j) const
{
	return grille[i][j];
}

std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau)
{
	for(size_t i=0;i<elPlateau.getDimension();i++)
	{
		for(size_t j=0;j<elPlateau.getDimension();j++)
		{
			out << elPlateau.getPositionGrille(i,j) << "\t";	
		}
		out << endl;
	}
	return out ;//<< "Plateau" << endl);
}

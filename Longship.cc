#include "Longship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Longship::id=0;

Longship::Longship()//Constructor
{
	id++;
	taille=5;
	//bool tab[taille];
	tab.push_back(taille);
	coule = false;
	for(size_t i=0;i<taille;i++)
	{
		tab[i]=false;
	}
}

Longship::~Longship(){}//Destructor

size_t Longship::getTaille() const
{
	return taille;
}

bool Longship::getTouche(int x) const
{
	return tab[x];
}

bool Longship::getCoule() const
{
	for(size_t i=0; i<taille;i++)
	{
		if(!getTouche(i))//Si le bateau n'est pas touché à un endroit du bateau
			return false;
	}
	return true;
}

string Longship::toString() const
{
	string buffer;
	buffer = " Le longship " + to_string(id);
	if(getCoule())
		buffer+= " a coulé.";
	else
		buffer+= " n'a pas coulé.";
	return buffer;
}

unsigned int Longship::getId() const
{
	return id;
}

#include "Shortship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Shortship::id=0;

Shortship::Shortship()//Constructor
{
	id++;
	taille=3;
	//bool tab[taille];
	coule = false;
	for(const auto& i:tab)
	{
		tab[i]=false;
	}
}

Shortship::~Shortship(){}//Destructor

size_t Shortship::getTaille() const
{
	return taille;
}

bool Shortship::getTouche(int x) const
{
	return tab[x];
}

bool Shortship::getCoule() const
{
	for(size_t i=0; i<taille;i++)
	{
		//cout << " Aie Caramba." << endl;
		if(getTouche(i)!=true)//Si le bateau n'est pas touché à un endroit du bateau
			return false;
	}
	return true;
}

string Shortship::toString() const
{
	string buffer;
	buffer = " Le Shortship " + to_string(id);
	if(getCoule()==true)
		buffer+= " a coulé.";
	else
		buffer+= " n'a pas coulé.";
	return buffer;
}

unsigned int Shortship::getId() const
{
	return id;
}

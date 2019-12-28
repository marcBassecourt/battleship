#include "Middleship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Middleship::id=0;

Middleship::Middleship()//Constructor
{
	id++;
	taille=4;
	//bool tab[taille];
	coule = false;
	for(const auto& i:tab)
	{
		tab[i]=false;
	}
}

Middleship::~Middleship(){}//Destructor

size_t Middleship::getTaille() const
{
	return taille;
}

bool Middleship::getTouche(int x) const
{
	return tab[x];
}

bool Middleship::getCoule() const
{
	for(size_t i=0; i<taille;i++)
	{
		//cout << " Aie Caramba." << endl;
		if(getTouche(i)!=true)//Si le bateau n'est pas touché à un endroit du bateau
			return false;
	}
	return true;
}

string Middleship::toString() const
{
	string buffer;
	buffer = " Le Middleship " + to_string(id);
	if(getCoule()==true)
		buffer+= " a coulé.";
	else
		buffer+= " n'a pas coulé.";
	return buffer;
}

unsigned int Middleship::getId() const
{
	return id;
}

#include "Middleship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Middleship::id=0;

Middleship::Middleship()//Constructor
{
	cpt_Touche = 4;
	id++;
	taille=4;
	//bool tab[taille];
	coule = false;
}

Middleship::~Middleship(){}//Destructor

size_t Middleship::getTaille() const
{
	return taille;
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

#include "Shortship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Shortship::id=0;

Shortship::Shortship()//Constructor
{
	cpt_Touche = 3;
	id++;
	taille=3;
	//bool tab[taille];
	coule = false;
}

Shortship::~Shortship(){}//Destructor

size_t Shortship::getTaille() const
{
	return taille;
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

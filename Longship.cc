#include "Longship.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

unsigned int Longship::id=0;

Longship::Longship()//Constructor
{
	cpt_Touche = 5;
	id++;
	taille=5;
	coule = false;
}

Longship::~Longship(){}//Destructor

size_t Longship::getTaille() const
{
	return taille;
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

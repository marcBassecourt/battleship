#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include "Plateau.hh"

class Main
{
	public:
		/*placerBateau();
		attaquer(unsigned int a, unsigned int b);// coordonnées*/
		std::string toString() const;
		
	private:
		Plateau plateauServeur, plateauClient;
		Longship longship;
		Middleship middleship;
		Shortship shortship;
		bool joueur;
		
};

#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include "classBat.hh"

class Batiment:public classBat
{
protected:
	size_t taille;
	std::vector<bool> tab;
	unsigned int cpt_Touche; //Compteur servant à savoir si le bateau coule ou non

	public:
		virtual size_t getTaille() const = 0;
		virtual bool getTouche(int x) const = 0;
		virtual std::string toString() const = 0;


};

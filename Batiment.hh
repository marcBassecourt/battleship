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
	unsigned int cpt_Touche; //Compteur servant à savoir si le bateau coule ou non
	bool coule;

	public:
		virtual size_t getTaille() const = 0;
		int getTouche()const{return cpt_Touche;};
		bool getCoule()const{
			if(getTouche() != 0){return false;}
			else return true;}
		virtual std::string toString() const = 0;
		void touche();


};

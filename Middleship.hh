#pragma once
#include "Bateau.hh"
#include <string>

class Middleship:public Bateau
{
	public:
		Middleship();//Constructor
		~Middleship();//Destructor
		size_t getTaille() const;
		bool getTouche(int x) const;
		std::string toString() const;
		//bool setCoule(bool y);
		bool getCoule() const;
		unsigned int getId() const;
		
	private:
		static unsigned int id;
		bool coule;
		
		size_t taille;
		bool tab[];
};
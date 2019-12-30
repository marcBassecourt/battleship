#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

class Plateau
{
	public:
		Plateau();
		Plateau(size_t x);
		Plateau(size_t x, size_t y);
		~Plateau();
		char** initGrille(size_t x);// tableau vide
		void afficherGrille();
		size_t getTailleGrille() const;
		std::string toString() const;
		size_t getDimension() const;
		char getPositionGrille(size_t i, size_t j) const;
		
	private:
		size_t dimension;
		char** grille;		
};
std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau);

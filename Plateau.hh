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
		size_t getDimensionX() const;
		size_t getDimensionY() const;
		char getPositionGrille(size_t i, size_t j) const;

	private:
		size_t dimensionX;
		size_t dimensionY;
		char** grille;
};
std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau);

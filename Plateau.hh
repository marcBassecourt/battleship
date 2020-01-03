#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)

class Plateau
{
	public:
		Plateau();
		Plateau(size_t x);
		Plateau(size_t x, size_t y);
		Plateau(size_t x, size_t y,char c);
		~Plateau();
		char** initGrille(size_t x);// tableau vide
		void afficherGrille();
		size_t getTailleGrille() const;
		std::string toString() const;
		size_t getDimensionX() const;
		size_t getDimensionY() const;
		char getPositionGrille(size_t i, size_t j) const;
		void placeBatiment(int x1,int x2,int y1,int y2,char c); //Place un bâtiment selon les coordonnées de ses extremités
		bool libre(int x1,int x2,int y1,int y2);	//Vérifie si la zone est libre ou non.

	private:
		size_t dimensionX;
		size_t dimensionY;
		char** grille;
};
std::ostream& operator<<(std::ostream& out, const Plateau& elPlateau);

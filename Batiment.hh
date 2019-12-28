#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>

class Batiment
{
	public:
		virtual size_t getTaille() const = 0;
		virtual bool getTouche(int x) const = 0;
		virtual std::string toString() const = 0;
		
	private:
		size_t taille;
		bool tab[];
};

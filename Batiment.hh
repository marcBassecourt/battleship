#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

class Batiment
{
	public:
		virtual size_t getTaille() const = 0;
		virtual bool getTouche(int x) const = 0;
		virtual std::string toString() const = 0;
		
	protected:
		size_t taille;
		std::vector<bool> tab;
};

#pragma once
#include <iostream>
#include "Batiment.hh"
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class Phare:public Batiment
{
	public:
		Phare();//Constructors
		~Phare();//Destructor
		size_t getTaille() const;
		bool getTouche(int x) const;
		std::string toString() const;
};

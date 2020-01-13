#pragma once
#include "Bateau.hh"
#include <string>

class Longship:public Bateau
{
public:
		static unsigned int id;
		Longship();//Constructor
		~Longship();//Destructor
		size_t getTaille() const;
		std::string toString() const;
		unsigned int getId() const;

	protected:
};

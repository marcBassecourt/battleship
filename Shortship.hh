#pragma once
#include "Bateau.hh"
#include <string>

class Shortship:public Bateau
{
	public:
		static unsigned int id;
		Shortship();//Constructor
		~Shortship();//Destructor
		size_t getTaille() const;
		std::string toString() const;
		unsigned int getId() const;

	protected:
};

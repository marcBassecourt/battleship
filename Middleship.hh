#pragma once
#include "Bateau.hh"
#include <string>

class Middleship:public Bateau
{
	public:
		static unsigned int id;
		Middleship();//Constructor
		~Middleship();//Destructor
		size_t getTaille() const;
		std::string toString() const;
		unsigned int getId() const;

	protected:
};

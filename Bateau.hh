#pragma once
#include "Batiment.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

class Bateau:public Batiment
{
	public:
		virtual size_t getTaille() const = 0;
		virtual std::string toString() const = 0;
		virtual unsigned int getId() const = 0;

	protected:
};

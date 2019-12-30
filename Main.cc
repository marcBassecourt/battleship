#include <iostream>
#include "Batiment.hh"
#include "Longship.hh"
#include "Middleship.hh"
#include "Shortship.hh"
#include "Bateau.hh"
#include "Main.hh"
#include "Phare.hh"
#include "Plateau.hh"
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	Plateau elPlateau;
	
	cout << elPlateau;
	/*size_t dimension=10;
	char plateau=initGrille(dimension);
	plateau.grille;*/
	
	string buf;
	Phare l;
	buf=l.toString();
	cout << buf << endl;
	l.~Phare();
	
	return 0;
}

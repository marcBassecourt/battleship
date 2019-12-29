#include <iostream>
#include "Batiment.hh"
#include "Longship.hh"
#include "Middleship.hh"
#include "Shortship.hh"
#include "Bateau.hh"
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	//jeu.jouer();
	string buf;
	cout << "Walid" << endl;
	
	Longship l;
	buf=l.toString();
	cout << buf << endl;
	//l.~Longship();
	
	Middleship m;
	buf=m.toString();
	cout << buf << endl;
	//m.~Middleship();
	
	/*buf=l.toString();
	cout << buf << endl;*/
	
	Shortship s;
	buf=s.toString();
	cout << buf << endl;
	//s.~Shortship();
	return 0;
}

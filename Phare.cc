#include "Phare.hh"


using namespace std;

Phare::Phare()//Constructor
{
	cpt_Touche = 2;
	taille=2;
	coule = false;
}

Phare::~Phare(){}//Destructor

size_t Phare::getTaille() const
{
	return taille;
}


std::string Phare::toString() const
{

	cout << "Le phare ";
	if(getCoule())
		cout << "a été trouvé, il éclaire donc sa zone environnante." << endl;
	else
		cout << "n'a pas été trouvé." << endl;
	return " ";
}

//LE PHARE DOIT ECLAIRER SUR L'INTERFACE GRAPHIQUE

#include "Phare.hh"


using namespace std;

Phare::Phare()//Constructor
{
	cpt_Touche = 2;
	taille=2;
	tab.push_back(taille);
	for(size_t i=0;i<taille;i++)
	{
		tab[i]=false;
	}
}

Phare::~Phare(){}//Destructor

size_t Phare::getTaille() const
{
	return taille;
}

bool Phare::getTouche(int x) const
{
	return tab[x];
}

std::string Phare::toString() const
{

	cout << "Le phare ";
	if(getTouche(1))
		cout << "a été trouvé, il éclaire donc sa zone environnante." << endl;
	else
		cout << "n'a pas été trouvé." << endl;
	return " ";
}

//LE PHARE DOIT ECLAIRER SUR L'INTERFACE GRAPHIQUE

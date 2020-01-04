#include <iostream>
#include "Batiment.hh"
#include "Longship.hh"
#include "Middleship.hh"
#include "Shortship.hh"
#include "Bateau.hh"
#include "Jeu.hh"
#include "Phare.hh"
#include "Plateau.hh"
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

Jeu::Jeu():plateauJ1(15,15,'0'),plateauJ2(15,15,'0'),plateauVisibleJ1(15,15),plateauVisibleJ2(15,15){
	char nom[15];
	system("clear");
	cout<<"Entrez le nom du 1er joueur :"<<flush;
	scanf("%s",nom);
 	players[0] = Joueur(nom);
	cout<<"Entrez le nom du 2e joueur :";
	scanf("%s",nom);
 	players[1] = Joueur(nom);
}

void Jeu::initJeu(){		//Fonction qui permet aux joueur de placer leurs bateaux
	system("clear");
	cout<<players[0].getName()<<" c'est à vous ! \n"<<flush;		//Joueur 1
	placerBatiment(plateauJ1,'L');
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'M');
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'S');
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'P');
	cout<<(plateauJ1)<<endl;
	system("clear");
	cout<<players[1].getName()<<" c'est à vous ! \n"<<flush;		//Joueur 2
	placerBatiment(plateauJ2,'L');
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'M');
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'S');
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'P');
	cout<<(plateauJ2)<<endl;
}

void Jeu::placerBatiment(Plateau &P, char c){ 	//Le char c permet de définir quel type de bâtiment on souhaite placer
	int size = 0;
	string str;
	unsigned int k = 0;
	switch(c){															//On définit la taille souhaitée du bâtiment
		case'L':
			size = 5;
			str = "longship";
			break;
		case'M':
			size = 4;
			str = "middleship";
			break;
		case'S':
			size = 3;
			str = "shortship";
			break;
		case'P':
			size = 2;
			str = "phare";
			break;
		default:
			break;
	}
	cout<<P;
	cout<<"Placez votre "<< str << " de taille "<<size<<".";

	while(k == 0){
		int x1,y1,x2,y2;
		cout<<"\nVeuillez entrer les coordonnées de début du bâtiment \nX:";
		scanf("%u",&x1);
		cout << "\nY:";
		scanf("%u",&y1);
		cout<<"\nVeuillez entrer les coordonnées de fin du bâtiment \nX:";
		scanf("%u",&x2);
		cout<<"\nY:";
		scanf("%u",&y2);
		if(((x1 == x2) || (y1 == y2 )) && ((abs(x1 - x2 + y1 - y2)) == (size-1))){
			if(P.libre(x1,x2,y1,y2)){
				k = 1;
				P.placeBatiment(x1,x2,y1,y2,c);
			}
		}
		else{
			cout<<"\n Veuillez entrer des coordonnées valides !";

		}
	}


}


int main()
{
	Jeu game;
	game.initJeu();
	//system("clear");
	//cout<<(game.plateauJ1)<<endl;
	//cout<<(game.plateauJ2)<<endl;
	// Plateau elPlateau;
	//
	// cout << elPlateau;
	// /*size_t dimension=10;
	// char plateau=initGrille(dimension);
	// plateau.grille;*/
	//
	// string buf;
	// Phare l;
	// buf=l.toString();
	// cout << buf << endl;
	// l.~Phare();

	return 0;
}

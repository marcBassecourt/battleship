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

void Jeu::initJeu(){
	system("clear");
	cout<<players[0].getName()<<" c'est à vous ! \nPlacez votre longship de taille 5 !"<<flush;
	placerBatiment(plateauJ1,'L');
	cout<<"Placez votre middleship de taille 4 !";
	placerBatiment(plateauJ1,'M');
	cout<<"Placez votre shortship de taille 3 !";
	placerBatiment(plateauJ1,'S');
	cout<<"Placez votre phare de taille 2 !";
	placerBatiment(plateauJ1,'P');
	system("clear");
	cout<<players[1].getName()<<" c'est à vous ! \nPlacez votre longship de taille 5 !"<<flush;
	placerBatiment(plateauJ2,'L');
	cout<<"Placez votre middleship de taille 4 !";
	placerBatiment(plateauJ2,'M');
	cout<<"Placez votre shortship de taille 3 !";
	placerBatiment(plateauJ2,'S');
	cout<<"Placez votre phare de taille 2 !";
	placerBatiment(plateauJ2,'P');
}

void Jeu::placerBatiment(Plateau &P, char c){ 	//Le char c permet de définir quel type de bâtiment on souhaite placer
	int size = 0;
	unsigned int k = 0;
	switch(c){															//On définit la taille souhaitée du bâtiment
		case'L':
			size = 5;
			break;
		case'M':
			size = 4;
			break;
		case'S':
			size = 3;
			break;
		case'P':
			size = 2;
			break;
		default:
			break;
	}

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
	system("clear");
	cout<<(game.plateauJ1)<<flush;
	game.initJeu();
	system("clear");
	cout<<(game.plateauJ1)<<flush;
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

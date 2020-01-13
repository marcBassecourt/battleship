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

Jeu::Jeu():plateauJ1(15,15,'0'),plateauJ2(15,15,'0'),plateauVisibleJ1(15,15,'~'),plateauVisibleJ2(15,15,'~'){
	char nom[15];
	system("clear");
	cout<<"Entrez le nom du 1er joueur :"<<flush;
	scanf("%s",nom);
 	players[0] = Joueur(nom);
	cout<<"Entrez le nom du 2e joueur :";
	scanf("%s",nom);
 	players[1] = Joueur(nom);
}

void Jeu::initJeu(){		//Fonction qui permet aux joueur de placer leurs bâtiments
	system("clear");
	cout<<players[0].getName()<<" c'est à vous ! \n"<<flush;		//Joueur 1
	placerBatiment(plateauJ1,'L',0);
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'M',0);
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'S',0);
	cout<<(plateauJ1)<<endl;
	placerBatiment(plateauJ1,'P',0);
	cout<<(plateauJ1)<<endl;
	system("clear");
	cout<<players[1].getName()<<" c'est à vous ! \n"<<flush;		//Joueur 2
	placerBatiment(plateauJ2,'L',1);
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'M',1);
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'S',1);
	cout<<(plateauJ2)<<endl;
	placerBatiment(plateauJ2,'P',1);
	cout<<(plateauJ2)<<endl;
}

void Jeu::placerBatiment(Plateau &P, char c,int i){ 	//Le char c permet de définir quel type de bâtiment on souhaite placer
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
				players[i].addBatiment(c);
			}
		}
		else{
			cout<<"\n Veuillez entrer des coordonnées valides !";

		}
	}


}

void Jeu::tirer(Plateau &p,Plateau &pvisible,int i){	//Fonction pour tirer à une coordonnée précise
	int x1,y1;
	int k = 0;
	int finJeu = 0;
	system("clear");
	cout<<(pvisible)<<endl<<flush;
	while(k == 0){
		cout<<players[i].getName()<<" à vous de tirer. Veuillez entrer les coordonnées à cibler!"<<endl;
		cout<<"X:";
		scanf("%u",&x1);
		cout << "\nY:";
		scanf("%u",&y1);
		if((x1 >= 0 && x1 < (int)p.getDimensionX()) &&(y1 >= 0 && y1 < (int)p.getDimensionY())){
			k++;
		}
		else{
			cout<<"Veuillez entrer des coordonnées valides."<<endl;
		}
	}

	if(p.getPositionGrille((size_t)x1,(size_t)y1) != '0'){	//Si la zone visée est un bâtiment
		players[i].toucheBatiment(p.getPositionGrille((size_t)x1,(size_t)y1));
		pvisible.setGrille(x1,y1,'X');
		p.setGrille(x1,y1,'X');
		if(players[i].mort()){
			finJeu++;
			system("clear");
			cout<<"Fin de la partie, "<<players[i].getName()<<" a gagné!"<<flush;
		}
	}
	else{
		pvisible.setGrille(x1,y1,'0');
		cout<<"Raté!"<<endl;
	}
}

void Jeu::waitEnter(int i,int j){	//Attend la touche entrée
	switch(j){
		case 0:
			cout<<"\n"<<players[i].getName()<<" veuillez appuyer sur Entrée pour donner la main à votre adversaire.";
			break;
		case 1:
			system("clear");
			cout<<players[i].getName()<<" veuillez appuyer sur Entrée pour Jouer."<<flush;
			break;
		default:
			break;
	}
	char temp = 'x';
	cin.ignore();
	while (temp != '\n')
		cin.get(temp);
}

void Jeu::play(){		//Fonction de jeu
	initJeu();
	while(1){
		waitEnter(0,1);
		tirer(plateauJ2,plateauVisibleJ1,0);
		waitEnter(0,0);
		waitEnter(1,1);
		tirer(plateauJ1,plateauVisibleJ2,1);
		waitEnter(1,0);
	}
}

int main()
{
	Jeu game;
	game.play();


	// Jeu game;
	// game.tirer(game.plateauJ2,game.plateauVisibleJ1,0);
	// game.initJeu();
	// game.tirer(game.plateauJ2,game.plateauVisibleJ1,0);



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

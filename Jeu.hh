#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include "Plateau.hh"
#include "Joueur.hh"

class Jeu
{

public:
	Jeu();
	std::string toString() const;
	void initJeu();
	void placerBatiment(Plateau &p,char c,int i);
	void tirer(Plateau &p,Plateau &pvisible,int i);
	void play();
	void waitEnter(int i,int j);

	Plateau plateauJ1, plateauJ2, plateauVisibleJ1, plateauVisibleJ2;
	Joueur players[2];


};

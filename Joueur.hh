#pragma once
#include <string>
#include <vector>
#include "Batiment.hh"
#include "Longship.hh"
#include "Middleship.hh"
#include "Shortship.hh"
#include "Bateau.hh"
#include "Phare.hh"
#include "Plateau.hh"


class Joueur {
protected:
  std::string name;
  size_t _id;
  std::vector<Batiment*> batsJoueur;
public:
  Joueur(){};
  Joueur(std::string s):name(s){};
  std::string getName()const{return name;};

  bool mort();
  void addBatiment(char c);     //Ajoute un bâtiments
  bool toucheBatiment(char c);  //Touche 1 fois un bâtiment
  void toString();
};

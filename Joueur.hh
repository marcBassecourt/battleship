#pragma once
#include <string>


class Joueur {
protected:
  std::string name;
  size_t _id;

public:
  Joueur(){};
  Joueur(std::string s):name(s){};
  std::string getName()const{return name;};


  void toString();
};

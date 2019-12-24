#pragma once
#include <string>


class Joueur {
protected:
  size_t _id;
  std::string name;
  static int _cpt_id;

public:
  Joueur(std::string s):name(s),_id(_cpt_id++){};


  void toString();
};

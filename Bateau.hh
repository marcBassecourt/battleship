#pragma once
#include <string>


class Bateau {
protected:
  size_t _id;
  std::string typeBateau;
  static int _cpt_id;
  int taille;
public:
  Bateau():_id(_cpt_id++){};
  Bateau(int t):_id(_cpt_id++),taille(t){};


  virtual void toString() const = 0;
};

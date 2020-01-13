#include "Joueur.hh"

void Joueur::toString(){
  cout<<name<<endl;
}

void Joueur::addBatiment(char c){
  switch(c){
    case 'L':
      batsJoueur.push_back(new Longship());
      break;
    case 'M':
      batsJoueur.push_back(new Middleship());
      break;
    case 'S':
      batsJoueur.push_back(new Shortship());
      break;
    case 'P':
      batsJoueur.push_back(new Phare());
      break;
    default:
      break;
  }
}

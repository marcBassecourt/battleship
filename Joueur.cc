#include "Joueur.hh"

void Joueur::toString(){
  cout<<name<<" possède "<<batsJoueur.size()<<" bâtiments."<<endl;
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

void Joueur::toucheBatiment(char c){
  cout<<"Touché !";
  switch(c){
    case 'L':
      batsJoueur[0]->touche();
      if(batsJoueur[0]->getCoule()){batsJoueur.erase(batsJoueur.begin());}
      break;
    case 'M':
      batsJoueur[1]->touche();
      if(batsJoueur[1]->getCoule()){batsJoueur.erase(batsJoueur.begin()+1);}
      break;
    case 'S':
      batsJoueur[2]->touche();;
      if(batsJoueur[2]->getCoule()){batsJoueur.erase(batsJoueur.begin()+2);}
      break;
    case 'P':
      batsJoueur[3]->touche();
      if(batsJoueur[3]->getCoule()){batsJoueur.erase(batsJoueur.begin()+3);}
      break;
    default:
      break;
  }
}

bool Joueur::mort(){
  if(batsJoueur.size() == 0){
    return true;
  }
  else{
    return 0;
  }
}

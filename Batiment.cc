#include "Batiment.hh"

void Batiment::touche(){
  cpt_Touche--;
  if(getCoule()){
    std::cout<<"Coulé!\n"<<std::endl;
  }
}

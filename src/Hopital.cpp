#include "Hopital.h"

Hopital::Hopital()//constructeur
{
    nom_hop=" ";
    adresse_hop=" ";
    payement_ambulance=0.0;

}

istream& operator>>(istream& in, Hopital &H)
{
  cout<<" Entrer le nom de L'hopital : "<<endl;
  in>>H.nom_hop;
  cout<<" Entrer l'adresse :"<<endl;
  in>>H.adresse_hop;
  cout<<" payement Ambulance "<<endl;
  in>>H.payement_ambulance;
  return in;
}
ostream& operator<<(ostream& out, Hopital& H)
{
  out<<"   Le nom de L hopital est "<<H.nom_hop<<endl;
  out<<"         l'adresse         "<<H.adresse_hop<<endl;
  out<<"      payement Ambulance   "<<H.payement_ambulance<<endl;
  return out;
}
ostream& operator<<(ostream& sortie, Hopital* H)
{
    sortie<<setw(20)<<H->adresse_hop<<" "<<setw(20)<<H->nom_hop<<" "<<setw(20)<<H->payement_ambulance;
    return sortie;
}
istream& operator>>(istream& entre, Hopital *H)
{
   entre>>H->adresse_hop;
   entre>>H->nom_hop;
   entre>>H->payement_ambulance;
   return entre;
}
void Hopital::enregistrer_hop()
{
    fstream f;
    f.open("fichier_Hopitaux.txt",ios::out|ios::app);
    if(! f.is_open()) exit(-1);
    f<<this<<endl;
    f.close();

}
void Hopital::recuperer_hop()
{
    fstream f;
    f.open("fichier_Hopitaux",ios::in);
    if(! f.is_open())exit(-1);
    Hopital*H=new Hopital;
    f>>H;
   f.close();
}
void Hopital::afficher_hop()
{
    fstream f;
    f.open("fichier_Hopitaux.txt",ios::in);
    if(! f.is_open())exit(-1);

    Hopital a;
    while(f >> a) {
        cout<<a.nom_hop<<'\n'<<a.adresse_hop<<'\n'<<a.payement_ambulance<<endl;;
    }

    f.close();
}
Hopital::~Hopital()
{
    //dtor
}

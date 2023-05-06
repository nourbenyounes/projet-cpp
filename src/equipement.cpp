
#include "equipement.h"
#include <string>
#include <iostream>

using namespace std;

equipement::equipement()
{
    id_mat=0;
    nb_mat=0;
    etat_exploitable="";
}

int equipement::getIdMat(){
    return id_mat;
}


int equipement::getNbMat() {
    return nb_mat;
}

void equipement::setNbMat(int nb) {
    nb_mat = nb;
}

bool equipement::getEtatExploitable(){
    return etat_exploitable;
}

void equipement::setEtatExploitable(bool etat) {
    etat_exploitable = etat;
}

istream& operator>> (istream& in,equipement& eq)
{


    cout << "Entrez l'ID du materiel : "<<endl;
    in>>eq.id_mat;
    cout << "Entrez le nombre de materiel : "<<endl;
    in>>eq.nb_mat;
    cout << "L'equipement est-il exploitable (1 pour oui, 0 pour non) ? "<<endl;
    in>>eq.etat_exploitable;
    return in;
}


ostream& operator<<(ostream& out,equipement& eq)
{

    out<<"\n       id materiel    "<<eq.id_mat<<endl;
    out<<"\n           nom        "<<eq.nb_mat<<endl;
    if((eq.etat_exploitable==0))
        cout<<"ATTENTION cet item est indisponible dans  le centre!!"<<endl;
    else
        cout<<"cet item est disponible dans le centre"<<endl;

}
ostream& operator<<(ostream& sortie,equipement*e)
{
      sortie<<setw(10)<<e->id_mat<<" "<<setw(10)<<e->nb_mat<<" "<<setw(10)<<e->etat_exploitable;
    return sortie;
}
istream& operator>>(istream& entre,equipement*e)
{
    entre>>e->id_mat;
    entre>>e->nb_mat;
    entre>>e->etat_exploitable;
    return entre;
}
void equipement::enregistrer_eq()
{
    fstream f;
    f.open("fichier_Equipements.txt",ios::out|ios::app);
    if(! f.is_open()) exit(-1);
    f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();

}
void equipement::recuperer_eq()
{
    fstream f;
    f.open("fichier_Equipements.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}

void equipement::afficher_eq()
{
    fstream f;
    f.open("fichier_Equipements.txt",ios::in);
    if(! f.is_open())exit(-1);

    equipement a;
    while(f >> a) {
        cout<<a.id_mat<<'\n'<<a.nb_mat<<'\n'<<a.etat_exploitable<<endl;;
    }

    f.close();
}
equipement::~equipement(){}



//template
/*
template<class T>
equipement<T>::equipement(T ID,T NB ,bool etat)
{
    id_mat=ID;
    nb_mat=NB;
    etat_exploitable=etat;
}
template<class T>
T equipement<T>::getIdMat(){
    return id_mat;
}

template<class T>
T equipement<T>::getNbMat() {
    return nb_mat;
}
template<class T>
void equipement<T>::setNbMat(T nb) {
    nb_mat = nb;
}
template<class T>
bool equipement<T>::getEtatExploitable(){
    return etat_exploitable;
}
template<class T>
void equipement<T>::setEtatExploitable(bool etat) {
    etat_exploitable = etat;
}

template<class T>
istream& operator>> (istream& in,equipement<T>& eq)
{


    cout << "Entrez l'ID du materiel : ";
    in>>eq.id_mat;
    cout << "Entrez le nombre de materiel : ";
    in>>eq.nb_mat;
    cout << "L'equipement est-il exploitable (1 pour oui, 0 pour non) ? ";
    in>>eq.etat_exploitable;
    return in;
}
template<class T>
ostream& operator<< (ostream& out,equipement<T>& eq)
{

    out<<"\n id materiel "<<eq.id_mat<<endl;
    out<<"\n etat "<<eq.etat_exploitable<<endl;
    out<<"\n nombre "<<eq.nb_mat<<endl;
    return out;
}
template<class T>
equipement<T>::~equipement()
{}
*/

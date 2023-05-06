#include "ambulance.h"
#include <string>
#include <iostream>
#include<vector>
#include<CHAUFFEUR.h>
#include <AMBULANCIER.h>
#include<iomanip>
using namespace std;



ambulance::ambulance()
{
    id_ambulance=0;
    localisation="centre";
    est_dispo=true;
    nb_amb++;
}

int ambulance::nb_amb=0;
int ambulance::retourner_nb_amb()
{
    cout<<" \n le nombre totale des ambulances crees "<<endl;
    return nb_amb;
}


istream& operator>>(istream& in, ambulance& amb)
{
    cout << "Entrez l'ID de l'ambulance : "<<endl;
    in >> amb.id_ambulance;

    cout << "Est-ce que l'ambulance est disponible ? (1 pour oui, 0 pour non) : "<<endl;
    in >> amb.est_dispo;


    return in;
}

ostream& operator<<(ostream& out,ambulance& amb)
{
    cout<<"Id de l'ambulance "<<amb.id_ambulance<<endl;
    cout<<"La disponibilit� "<<amb.est_dispo<<endl;

    return out;
}


int ambulance::getIdAmbulance() {
    return id_ambulance;
}

void ambulance::setIdAmbulance(int id_ambulance) {
    ambulance::id_ambulance = id_ambulance;
}

string& ambulance::getLocalisation() {
    return localisation;
}

void ambulance::setLocalisation(string& localisation) {
    ambulance::localisation = localisation;
}

bool ambulance::isDispo() {
    return est_dispo;
}

void ambulance::setDispo(bool dispo) {
    ambulance::est_dispo = dispo;
}


ostream& operator<<(ostream& sortie,ambulance*a)
{
      sortie<<setw(10)<<a->id_ambulance<<" "<<setw(10)<<a->est_dispo;
    return sortie;
}
istream& operator>>(istream& entre, ambulance* a)
{
    entre>>a->id_ambulance;
    entre >>a->est_dispo;
    return entre;
}
void ambulance::enregistrer_amb()
{
    fstream f;
    f.open("fichier_Ambulances.txt",ios::out|ios::app);
    if(! f.is_open()) exit(-1);
    f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();

}

void ambulance::afficher_amb()
{
    fstream f;
    f.open("fichier_Ambulances.txt",ios::in);
    if(! f.is_open())exit(-1);

    ambulance a;
    while(f >> a) {
        cout<<a.id_ambulance<<'\n'<<a.est_dispo<<endl;
    };

    f.close();
}


    void ambulance::recuperer_amb()
{
    fstream f;
    f.open("fichier_Ambulances.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}

int ambulance::getD(){ return est_dispo;}
int ambulance::sD(int disp){ambulance::est_dispo = disp; }
ambulance::~ambulance()
{
    nb_amb--;
}

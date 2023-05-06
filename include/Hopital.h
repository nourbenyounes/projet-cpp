#ifndef HOPITAL_H
#define HOPITAL_H
#include <string>
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class Hopital
{   private:
    string nom_hop;
    string adresse_hop;
    float payement_ambulance;

    public:
        Hopital();
        string getNomHop(){return nom_hop;}
        friend ostream& operator<<(ostream&, Hopital&);
        friend istream& operator>>(istream&, Hopital&);
        friend ostream& operator<<(ostream&, Hopital*);
        friend istream& operator>>(istream&, Hopital*);
        void enregistrer_hop();
        void recuperer_hop();
        virtual ~Hopital();
        void afficher_hop();



};
#endif // AMBULANCE_H

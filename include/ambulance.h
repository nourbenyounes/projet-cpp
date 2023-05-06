#ifndef AMBULANCE_H
#define AMBULANCE_H
#include <string>
#include <iostream>
#include<vector>
#include<fstream>
#include"EMPLOYE.h"
#include<equipement.h>
using namespace std;

class ambulance
{
    int id_ambulance;
    string localisation;
    bool est_dispo;
    static int nb_amb; //attribut statique
   // vector<EMPLOYE*> tab;
    public:
        ambulance();
        static int retourner_nb_amb(); //methode statique
        int getIdAmbulance();
        void setIdAmbulance(int);
        string& getLocalisation();
        void setLocalisation(string&);
        bool isDispo();
        void setDispo(bool);
        friend ostream& operator<<(ostream&,ambulance&);
        friend istream& operator>>(istream&,ambulance&);
        friend ostream& operator<<(ostream&,ambulance*);
        friend istream& operator>>(istream&,ambulance*);
        void enregistrer_amb();
        void recuperer_amb();
        virtual ~ambulance();
        int getD();
        int sD(int);
        void afficher_amb();

};

#endif // AMBULANCE_H

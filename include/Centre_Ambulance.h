#ifndef CENTRE_AMBULANCE_H
#define CENTRE_AMBULANCE_H
#include <string>
#include <iostream>
#include<vector>
#include<ambulance.h>
#include"EMPLOYE.h"
#include<Appel.h>
#include<equipement.h>
#include<Hopital.h>
#include<AMBULANCIER.h>
#include<CHAUFFEUR.h>
#include<list>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

class Centre_Ambulance
{
    private:
        int id_centre;
        map<int,ambulance> amb;  //map
        vector<EMPLOYE*> emp;
        vector<Appel> app;
        vector<equipement> eq;
        list<Hopital> hop;  // la liste des hopitaux de la r�gion

    public:
        static void creer(fstream);

        Centre_Ambulance();
        Centre_Ambulance(const Centre_Ambulance&);

    void ajouter_employe();
        void ajouter_ambulance(ambulance);
        void ajouter_equipement(equipement);
        void ajouter_appel(Appel);
        void ajouter_hopital(Hopital);

        void supprimer_employe(int);
        void supprimer_ambulance(int);
        void supprimer_equipement(int);
        void supprimer_appel(int);
        void supprimer_hopital(string);

        void modifier_employe(int);
        void modifier_ambulance(ambulance);
        void modifier_equipement(equipement,int);
        void modifier_appel(Appel,int);
        void modifier_hopital(string,Hopital);
        void afficher_lesAmb();
        void afficher_lesEmp();
        void afficher_lesEq();
        void afficher_lesHops();
        void afficher_lesApp();
        map<int,ambulance> getAmbulances();
        void trouveAmb(int);
        vector<EMPLOYE*> getEmployes();
        EMPLOYE* trouverEmploye(int);
        vector<equipement> getEq();
        void trouveEq(int);
        void trouveHop(string);
        list<Hopital> gethops();
        void trouveApp(int);
        vector<Appel> getApp();


        friend ostream& operator<<(ostream&,Centre_Ambulance&);
        friend istream& operator>>(istream&,Centre_Ambulance&);

        virtual ~Centre_Ambulance();

};

#endif // CENTRE_AMBULANCE_H


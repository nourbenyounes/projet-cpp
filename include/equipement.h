#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <string>
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class equipement
{
    int id_mat;
    int nb_mat;
    bool etat_exploitable;
    public:
        equipement();
        virtual ~equipement();
        int getIdMat();
        int getNbMat();
        void setNbMat(int);
        bool getEtatExploitable();
        void setEtatExploitable(bool);
        friend ostream& operator<<(ostream&,equipement&);
        friend istream& operator>>(istream&,equipement&);
        friend ostream& operator<<(ostream&,equipement*);
        friend istream& operator>>(istream&,equipement*);
        void enregistrer_eq();
        void recuperer_eq();
        void afficher_eq();



};
/*
template<class T>
class equipement
{
    T id_mat;
    T nb_mat;
    bool etat_exploitable;
    public:
        equipement(T=0,T=0,bool=true);
        virtual ~equipement();
        T getIdMat();
        T getNbMat();
        void setNbMat(T);
        bool getEtatExploitable();
        void setEtatExploitable(bool);
        friend ostream& operator<< <>(ostream&,equipement<T>&);
        friend istream& operator>> <>(istream&,equipement<T>&);

};*/

#endif // EQUIPEMENT_H

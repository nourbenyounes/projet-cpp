#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
using namespace std;
#include<vector>
#include"string"
#include<iomanip>
class EMPLOYE
{
    protected:
        int id_emp;
        string nom;
        float salaire_brut;
        vector<float> liste_primes;
        bool est_dispo;
    public:
        EMPLOYE();
        EMPLOYE(const EMPLOYE&);

        bool getEst_Dispo();
        int getIdEmp(){return id_emp;}

        virtual float calcul_salaire_trimestriel()=0;

        EMPLOYE& operator=(const EMPLOYE &);

        friend ostream& operator<<(ostream& ,EMPLOYE&);
        friend istream& operator>>(istream& ,EMPLOYE&);


        virtual ~EMPLOYE();

};

#endif // EMPLOYE_H

/*
template<class I,class F >
class EMPLOYE
{
    protected:
        I id_emp;
        string nom;
        F salaire_brut;
        vector<F> liste_primes;
        bool est_dispo;
    public:
        EMPLOYE();
        EMPLOYE(const EMPLOYE&);

        bool getEst_Dispo();
        I getIdEmp(){return id_emp;}

        virtual F calcul_salaire_trimestriel()=0;

        EMPLOYE& operator=(const EMPLOYE &);

        friend ostream& operator<< <>(ostream& ,EMPLOYE&);
        friend istream& operator>> <>(istream& ,EMPLOYE&);


        virtual ~EMPLOYE();

};*/

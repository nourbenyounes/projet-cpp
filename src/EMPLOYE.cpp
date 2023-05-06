
#include "EMPLOYE.h"
using namespace std;

EMPLOYE::EMPLOYE()
{
id_emp=0;
nom="";
salaire_brut=0;
est_dispo=true;

}

EMPLOYE::EMPLOYE(const EMPLOYE&emp )
{
    id_emp=emp.id_emp;
    nom=emp.nom;
    salaire_brut=emp.salaire_brut;
    est_dispo=emp.est_dispo;
    for(int i=0;i<emp.liste_primes.size();i++)
        liste_primes[i]=emp.liste_primes[i];
}

bool EMPLOYE::getEst_Dispo()
{
    return est_dispo;
}

EMPLOYE& EMPLOYE::operator=(const EMPLOYE& e)
{

    if(this!=&e)
    {
        id_emp=e.id_emp;
        nom=e.nom;
        salaire_brut=e.salaire_brut;
        est_dispo=e.est_dispo;
        for(int i=0;i<e.liste_primes.size();i++)
            liste_primes[i]=e.liste_primes[i];

    }
    return *this;
}

istream& operator>>(istream& in ,EMPLOYE& emp)
{
    cout<<" saisir id d'employe "<<endl;
    in>>emp.id_emp;
    cout<<" saisir le nom d'employe "<<endl;
    in>>emp.nom;
    cout<<" saisir le salair brut d'employe "<<endl;
    in>>emp.salaire_brut;
    cout<<" l'employe est disponible?? (1 si oui 0 sinon)"<<endl;
    in>>emp.est_dispo;
    cout<<" remplir la liste des primes ce trimestre "<<endl;
    float x;
    char choix;
    do
    {
        in>>x;
        emp.liste_primes.push_back(x);
        cout<<"\n d'autre primes( o:oui || n: non) ?? "<<endl;
        cin>>choix;
    }
    while(choix=='o'||choix=='O');

    return in;
}

ostream& operator<<(ostream& out ,EMPLOYE& emp)
{
    out<<"      id d'employe            "<<emp.id_emp<<endl;

    out<<"     le nom d'employe         "<<emp.nom<<endl;
    out<<"  le salaire brut d'employe   "<<emp.salaire_brut<<endl;
    if(emp.est_dispo==0)
    out<<"     l'emplye est occupe      "<<endl;
    else
    out<<"   l'employe est disponible   "<<endl;
    out<<"      la liste des primes     "<<endl;
    for(int i=0;i<emp.liste_primes.size();i++)
    out<<"    "<<emp.liste_primes[i]<<"|";
        cout<<endl;
    return out;
}

EMPLOYE::~EMPLOYE()
{
    //dtor
}
/*
template<class I,class F >
EMPLOYE<I,F>::EMPLOYE()
{
id_emp=0;
nom="";
salaire_brut=0;
est_dispo=true;

}
template<class I,class F >
EMPLOYE<I,F>::EMPLOYE(const EMPLOYE<I,F> &emp )
{
    id_emp=emp.id_emp;
    nom=emp.nom;
    salaire_brut=emp.salaire_brut;
    est_dispo=emp.est_dispo;
    for(int i=0;i<emp.liste_primes.size();i++)
        liste_primes[i]=emp.liste_primes[i];
}
template<class I,class F >
bool EMPLOYE<I,F>::getEst_Dispo()
{
    return est_dispo;
}
template<class I,class F >
EMPLOYE<I,F>& EMPLOYE<I,F>::operator=(const EMPLOYE<I,F> & e)
{

    if(this!=&e)
    {
        id_emp=e.id_emp;
        nom=e.nom;
        salaire_brut=e.salaire_brut;
        est_dispo=e.est_dispo;
        for(int i=0;i<e.liste_primes.size();i++)
            liste_primes[i]=e.liste_primes[i];

    }
    return *this;
}
template<class I,class F >
istream& operator>>(istream& in ,EMPLOYE<I,F>& emp)
{
    cout<<" saisir id d'employe "<<endl;
    in>>emp.id_emp;
    cout<<" saisir le nom d'employe "<<endl;
    in>>emp.nom;
    cout<<" saisir le salair brut d'employe "<<endl;
    in>>emp.salaire_brut;
    cout<<" l'employe est disponible?? (1 si oui 0 sinon)"<<endl;
    in>>emp.est_dispo;
    cout<<" remplir la liste des primes ce trimestre "<<endl;
    float x;
    char choix;
    do
    {
        in>>x;
        emp.liste_primes.push_back(x);
        cout<<"\n d'autre primes( o:oui || n: non) ?? "<<endl;
        cin>>choix;
    }
    while(choix=='o'||choix=='O');

    return in;
}
template<class I,class F >
ostream& operator<<(ostream& out ,EMPLOYE<I,F>& emp)
{
    out<<"      id d'employe            "<<emp.id_emp<<endl;

    out<<"     le nom d'employe         "<<emp.nom<<endl;
    out<<"  le salaire brut d'employe   "<<emp.salaire_brut<<endl;
    if(emp.est_dispo==0)
    out<<"     l'emplye est occupe      "<<endl;
    else
    out<<"   l'employe est disponible   "<<endl;
    out<<"      la liste des primes     "<<endl;
    for(int i=0;i<emp.liste_primes.size();i++)
    out<<"    "<<emp.liste_primes[i]<<"|";
        cout<<endl;
    return out;
}
template<class I,class F >
EMPLOYE<I,F>::~EMPLOYE()
{
    //dtor
}*/



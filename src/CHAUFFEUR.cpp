#include "CHAUFFEUR.h"
CHAUFFEUR::CHAUFFEUR():EMPLOYE()
{
    permis_valide=true;
    num_permis=0;
}

CHAUFFEUR::CHAUFFEUR(const CHAUFFEUR& ch):EMPLOYE(ch)
{
    permis_valide=ch.permis_valide;
    num_permis=ch.num_permis;
}

CHAUFFEUR& CHAUFFEUR::operator=(CHAUFFEUR&w)
{
     if(this !=&w)
    {
        EMPLOYE *ch1=this;
        EMPLOYE *ch2=&w;
        *ch1= *ch2;
        num_permis=w.num_permis;
        permis_valide=w.permis_valide;
    }
    return *this;
}


float CHAUFFEUR::calcul_salaire_trimestriel()
{
    float salaire;
    salaire=salaire_brut*3;
    for(int i=0;i<liste_primes.size();i++)
        salaire+=liste_primes[i];
    return salaire;
}


ostream& operator<<(ostream& out,CHAUFFEUR& ch)
{
    EMPLOYE *e=&ch;
    out<<*e;
    out<<"      numero de permis        "<<ch.num_permis<<endl;
    if(ch.permis_valide=0)
    out<<"    le permis est invalide    "<<endl;
    else
    out<<"     le permis est valide     "<<endl;
    return out;

}


istream& operator>>(istream& in,CHAUFFEUR& ch)
{
    EMPLOYE *e=&ch;
    in>>*e;
    cout<<" \n donner le numero de permis "<<endl;
    in>>ch.num_permis;
    cout<<" le permis est-il valide ?? (1 si oui 0 sinon)"<<endl;
    in>>ch.permis_valide;
    return in;

}

ostream& operator<<(ostream& sortie, CHAUFFEUR*ch)
{
    sortie<<setw(10)<<ch->id_emp<<" "<<setw(10)<<ch->nom<<" "<<setw(10)<<ch->salaire_brut;
    for(int i=0;i<ch->liste_primes.size();i++)
        sortie<<" "<<setw(10)<<ch->liste_primes[i];

    sortie<<" "<<setw(10)<<ch->num_permis;
    return sortie;
}



istream& operator>>(istream& entre,CHAUFFEUR*ch)
{
     entre>>ch->id_emp;
     entre>>ch->nom;
     entre>>ch->salaire_brut;
    for(int i=0;i<ch->liste_primes.size();i++)
        entre>>ch->liste_primes[i];
     entre>>ch->num_permis;
     return entre;
}

void CHAUFFEUR::enregistrer_ch()
{
    fstream f;
   f.open("fichier_employes.txt",ios::in | ios::out | ios::app);
        if(!f.is_open()) exit(-1);
    f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();
}

void CHAUFFEUR::recuperer_ch()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}
void CHAUFFEUR::afficher_chauffeur()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);

    CHAUFFEUR a;
    while(f >> a) {
        cout<<a<<endl;;
    }

    f.close();
}


CHAUFFEUR::~CHAUFFEUR()
{

}
/*template<class I,class F >
CHAUFFEUR<I,F>::CHAUFFEUR():EMPLOYE<I,F>()
{
    permis_valide=true;
    num_permis=0;
}
template<class I,class F >
CHAUFFEUR<I,F>::CHAUFFEUR(const CHAUFFEUR<I,F>& ch):EMPLOYE<I,F>(ch)
{
    permis_valide=ch.permis_valide;
    num_permis=ch.num_permis;
}
template<class I,class F >
CHAUFFEUR<I,F>& CHAUFFEUR<I,F>::operator=(CHAUFFEUR<I,F>&w)
{
     if(this !=&w)
    {
        EMPLOYE<I,F> *ch1=this;
        EMPLOYE<I,F> *ch2=&w;
        *ch1= *ch2;
        num_permis=w.num_permis;
        permis_valide=w.permis_valide;
    }
    return *this;
}

template<class I,class F >
float CHAUFFEUR<I,F>::calcul_salaire_trimestriel()
{
    float salaire;
    salaire=salaire_brut*3;
    for(int i=0;i<liste_primes.size();i++)
        salaire+=liste_primes[i];
    return salaire;
}

template<class I,class F >
ostream& operator<<(ostream& out,CHAUFFEUR<I,F>& ch)
{
    EMPLOYE<I,F> *e=&ch;
    out<<*e;
    out<<"      numero de permis        "<<ch.num_permis<<endl;
    if(ch.permis_valide=0)
    out<<"    le permis est invalide    "<<endl;
    else
    out<<"     le permis est valide     "<<endl;
    return out;

}

template<class I,class F >
istream& operator>>(istream& in,CHAUFFEUR<I,F>& ch)
{
    EMPLOYE<I,F> *e=&ch;
    in>>*e;
    cout<<" \n donner le numero de permis "<<endl;
    in>>ch.num_permis;
    cout<<" le permis est-il valide ?? (1 si oui 0 sinon)"<<endl;
    in>>ch.permis_valide;
    return in;

}
template<class I,class F >
ostream& operator<<(ostream& sortie, CHAUFFEUR<I,F>*ch)
{
    sortie<<setw(10)<<ch->id_emp<<" "<<setw(10)<<ch->nom<<" "<<setw(10)<<ch->salaire_brut;
    for(int i=0;i<ch->liste_primes.size();i++)
        sortie<<" "<<setw(10)<<ch->liste_primes[i];

    sortie<<" "<<setw(10)<<ch->num_permis;
    return sortie;
}


template<class I,class F >
istream& operator>>(istream& entre,CHAUFFEUR<I,F>*ch)
{
     entre>>ch->id_emp;
     entre>>ch->nom;
     entre>>ch->salaire_brut;
    for(int i=0;i<ch->liste_primes.size();i++)
        entre>>ch->liste_primes[i];
     entre>>ch->num_permis;
     return entre;
}
template<class I,class F >
void CHAUFFEUR<I,F>::enregistrer_ch()
{
    fstream f;
   f.open("fichier_employes.txt",ios::in | ios::out | ios::app);
        if(!f.is_open()) exit(-1);
    f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();
}
template<class I,class F >
void CHAUFFEUR<I,F>::recuperer_ch()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}

template<class I,class F >
CHAUFFEUR<I,F>::~CHAUFFEUR()
{

}*/

#include "AMBULANCIER.h"

AMBULANCIER::AMBULANCIER():EMPLOYE()
{
    horaire="";
    categorie="";
}

AMBULANCIER::AMBULANCIER(const AMBULANCIER& amb):EMPLOYE(amb)
{
    horaire=amb.horaire;
    categorie=amb.categorie;
    for(int i=0;i<amb.nb_cas.size();i++)
    nb_cas[i]=amb.nb_cas[i];
}

AMBULANCIER& AMBULANCIER::operator=(AMBULANCIER&w)
{
    if(this !=&w)
    {
        EMPLOYE *amb1=this;
        EMPLOYE *amb2=&w;
        *amb1=*amb2;
        horaire=w.horaire;
        categorie=w.categorie;
        for(int i=0;i<w.nb_cas.size();i++)
            nb_cas[i]=w.nb_cas[i];
    }
    return *this;
}

ostream& operator<<(ostream& out,AMBULANCIER& amb)
{
EMPLOYE *e=&amb;
    out<<*e;
    out<<"      l horaire de travail       "<<amb.horaire<<endl;

    out<<"          la categorie           "<<amb.categorie<<endl;
    out<<" nombre de cas trait�s par jour  "<<endl;
    for(int i=0;i<amb.nb_cas.size();i++)
    out<<"  "<<amb.nb_cas[i]<<" |";
    cout<<endl;
    return out;
}

istream& operator>>(istream& in,AMBULANCIER& amb)
{
    EMPLOYE *e=&amb;
    in>>*e;
    cout<<" \n donner l'horaire de travail "<<endl;
    in>>amb.horaire;
    cout<<" \n donner la categorie "<<endl;
    in>>amb.categorie;
    int n;
    cout<<" \n donner le nombre jours du travail ce mois "<<endl;
    int x;
    in>>x;
    cout<<" \n le nombre de cas traitees par jour"<<endl;
    for(int i=0;i<x;i++)
        {
        cout<<" \n le jour  "<<i+1<<"  ";
        in>>n;
        amb.nb_cas.push_back(n);
        }

}

float AMBULANCIER::calcul_salaire_trimestriel()
{
    float salaire=salaire_brut *3;
    for(int i=0;i<liste_primes.size();i++)
        salaire+=liste_primes[i];
    int pt;
    int sompt;
    for(int i=0;i<nb_cas.size();i++)
    {
        if(nb_cas[i]>7)
            {pt=nb_cas[i]-7;
            sompt+=pt;}
    }
    salaire=salaire+((salaire_brut*sompt)/100);

    return salaire;
}

ostream& operator<<(ostream& sortie,AMBULANCIER*amb)
{
    sortie<<setw(10)<<amb->id_emp<<" "<<setw(10)<<amb->nom<<" "<<setw(10)<<amb->salaire_brut;
    for(int i=0;i<amb->liste_primes.size();i++)
        sortie<<" "<<setw(10)<<amb->liste_primes[i];
    sortie<<" "<<setw(10)<<amb->categorie<<" "<<setw(10)<<amb->horaire;
     for(int i=0;i<amb->nb_cas.size();i++)
        sortie<<" "<<setw(10)<<amb->nb_cas[i];

    return sortie;
}


istream& operator>>(istream& entre,AMBULANCIER*amb)
{

     entre>>amb->id_emp;
     entre>>amb->nom;
     entre>>amb->salaire_brut;
    for(int i=0;i<amb->liste_primes.size();i++)
        entre>>amb->liste_primes[i];
     entre>>amb->horaire;
     entre>>amb->categorie;
     for(int i=0;i<amb->nb_cas.size();i++)
        entre>>amb->nb_cas[i];
     return entre;
}


void AMBULANCIER::enregistrer_am()
{
    fstream f;
   f.open("fichier_employes.txt",ios::in | ios::out | ios::app);
        if(!f.is_open()) exit(-1);
     f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();
}
void AMBULANCIER::recuperer_am()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}

AMBULANCIER::~AMBULANCIER()
{
}
void AMBULANCIER::afficher_ambulancier()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);

    AMBULANCIER a;
    while(f >> a) {
        cout<<a<<endl;
    };

    f.close();
}

/*
template<class I,class F >
AMBULANCIER<I,F>::AMBULANCIER():EMPLOYE<I,F>()
{
    horaire="";
    categorie="";
}
template<class I,class F >
AMBULANCIER<I,F>::AMBULANCIER(const AMBULANCIER& amb):EMPLOYE<I,F>(amb)
{
    horaire=amb.horaire;
    categorie=amb.categorie;
    for(int i=0;i<amb.nb_cas.size();i++)
    nb_cas[i]=amb.nb_cas[i];
}
template<class I,class F >
AMBULANCIER<I,F>& AMBULANCIER<I,F>::operator=(AMBULANCIER&w)
{
    if(this !=&w)
    {
        EMPLOYE<I,F> *amb1=this;
        EMPLOYE<I,F> *amb2=&w;
        *amb1=*amb2;
        horaire=w.horaire;
        categorie=w.categorie;
        for(int i=0;i<w.nb_cas.size();i++)
            nb_cas[i]=w.nb_cas[i];
    }
    return *this;
}
template<class I,class F >
ostream& operator<<(ostream& out,AMBULANCIER<I,F>& amb)
{
EMPLOYE<I,F> *e=&amb;
    out<<*e;
    out<<"      l horaire de travail       "<<amb.horaire<<endl;

    out<<"          la categorie           "<<amb.categorie<<endl;
    out<<" nombre de cas trait�s par jour  "<<endl;
    for(int i=0;i<amb.nb_cas.size();i++)
    out<<"  "<<amb.nb_cas[i]<<" |";
    cout<<endl;
    return out;
}
template<class I,class F >
istream& operator>>(istream& in,AMBULANCIER<I,F>& amb)
{
    EMPLOYE<I,F> *e=&amb;
    in>>*e;
    cout<<" \n donner l'horaire de travail "<<endl;
    in>>amb.horaire;
    cout<<" \n donner la categorie "<<endl;
    in>>amb.categorie;
    int n;
    cout<<" \n donner le nombre jours du travail ce mois "<<endl;
    int x;
    in>>x;
    cout<<" \n le nombre de cas traitees par jour"<<endl;
    for(int i=0;i<x;i++)
        {
        cout<<" \n le jour  "<<i+1<<"  ";
        in>>n;
        amb.nb_cas.push_back(n);
        }

}
template<class I,class F >
float AMBULANCIER<I,F>::calcul_salaire_trimestriel()
{
    float salaire=salaire_brut *3;
    for(int i=0;i<liste_primes.size();i++)
        salaire+=liste_primes[i];
    int pt;
    int sompt;
    for(int i=0;i<nb_cas.size();i++)
    {
        if(nb_cas[i]>7)
            {pt=nb_cas[i]-7;
            sompt+=pt;}
    }
    salaire=salaire+((salaire_brut*sompt)/100);

    return salaire;
}
template<class I,class F >
ostream& operator<<(ostream& sortie,AMBULANCIER<I,F>*amb)
{
    sortie<<setw(10)<<amb->id_emp<<" "<<setw(10)<<amb->nom<<" "<<setw(10)<<amb->salaire_brut;
    for(int i=0;i<amb->liste_primes.size();i++)
        sortie<<" "<<setw(10)<<amb->liste_primes[i];
    sortie<<" "<<setw(10)<<amb->categorie<<" "<<setw(10)<<amb->horaire;
     for(int i=0;i<amb->nb_cas.size();i++)
        sortie<<" "<<setw(10)<<amb->nb_cas[i];

    return sortie;
}
template<class I,class F >
istream& operator>>(istream& entre,AMBULANCIER<I,F>*amb)
{

     entre>>amb->id_emp;
     entre>>amb->nom;
     entre>>amb->salaire_brut;
    for(int i=0;i<amb->liste_primes.size();i++)
        entre>>amb->liste_primes[i];
     entre>>amb->horaire;
     entre>>amb->categorie;
     for(int i=0;i<amb->nb_cas.size();i++)
        entre>>amb->nb_cas[i];
     return entre;
}

template<class I,class F >
void AMBULANCIER<I,F>::enregistrer_am()
{
    fstream f;
   f.open("fichier_employes.txt",ios::in | ios::out | ios::app);
        if(!f.is_open()) exit(-1);
     f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();
}
template<class I,class F >
void AMBULANCIER<I,F>::recuperer_am()
{
    fstream f;
    f.open("fichier_employes.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}
template<class I,class F >
AMBULANCIER<I,F>::~AMBULANCIER()
{
}
*/

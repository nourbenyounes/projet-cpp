#include "Appel.h"

Appel::Appel()//constructeur
{
    num_appel=000000;
    localisation=" ";
    temps=" ";
}

istream& operator>> (istream& in, Appel &A)//saisie
{
    cout<<"Appel Numero:"<<endl;
    in>>A.num_appel;
    cout<<" donner la localisation  "<<endl;
    in>>A.localisation;
    cout<<" donner le temps de l appel "<<endl;
    in>>A.temps;
    return in;

}
ostream& operator<< (ostream& out, Appel& A)//affichage
{
    out<<"        Appel Numero        "<<A.num_appel<<endl;;
    out<<" la localisation mentionnee "<<A.localisation<<endl;
    out<<"   le temps de l appel est  "<<A.temps<<endl;
    return out;
}

Appel Appel::operator> (Appel& A)//surcharge de l'op�rateur >
{
    if (num_appel<A.num_appel)
        return(*this);
    else return(A);
}
istream& operator>>(istream& entre, Appel* A)
{
   entre>>A->num_appel;
   entre>>A->localisation;
   entre>>A->temps;
   return entre;
}
ostream& operator<<(ostream& sortie, Appel* A)
{
    sortie<<setw(20)<<A->num_appel<<" "<<setw(20)<<A->localisation<<" "<<setw(20)<<A->temps;
    return sortie;

}

void Appel::enregistrer_ap()
{
    fstream f;
    f.open("fichier_Appels.txt",ios::out|ios::app);
    if(! f.is_open()) exit(-1);
    f<<this<<endl;
    f.seekg(0, ios::end);
    f.close();

}
void Appel::recuperer_ap()
{
    fstream f;
    f.open("fichier_Appels.txt",ios::in);
    if(! f.is_open())exit(-1);
    f>>this;
   f.close();
}
void Appel::afficher_appel()
{
    fstream f;
    f.open("fichier_Appels.txt",ios::in);
    if(! f.is_open())exit(-1);

    Appel a;
    while(f >> a) {
        cout<<a.num_appel<<'\n'<<a.localisation<<'\n'<<a.temps<<endl;;
    }

    f.close();
}

Appel::~Appel()
{
    //dtor
}

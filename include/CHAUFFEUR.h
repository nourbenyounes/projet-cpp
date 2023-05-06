#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H
#include <EMPLOYE.h>
#include<iomanip>
#include<fstream>
using namespace std;

class CHAUFFEUR : public EMPLOYE
{
    private:
        bool permis_valide;
        int num_permis;
    public:
        CHAUFFEUR();
        CHAUFFEUR(const CHAUFFEUR&);

        float calcul_salaire_trimestriel();

        CHAUFFEUR& operator=(CHAUFFEUR &);

        friend ostream& operator<< (ostream&,CHAUFFEUR&);
        friend istream& operator>> (istream&,CHAUFFEUR&);

        friend ostream& operator<<(ostream&,CHAUFFEUR*);
        friend istream& operator>>(istream&,CHAUFFEUR*);

        void enregistrer_ch();
        void recuperer_ch();
        virtual ~CHAUFFEUR();
        void afficher_chauffeur();


};

#endif // CHAUFFEUR_H
/*template<class I,class F>
class CHAUFFEUR : public EMPLOYE<I,F>
{
    private:
        bool permis_valide;
        int num_permis;
    public:
        CHAUFFEUR();
        CHAUFFEUR(const CHAUFFEUR&);

        float calcul_salaire_trimestriel();

        CHAUFFEUR& operator=(CHAUFFEUR &);

        friend ostream& operator<< <>(ostream&,CHAUFFEUR&);
        friend istream& operator>> <>(istream&,CHAUFFEUR&);

        friend ostream& operator<<(ostream&,CHAUFFEUR*);
        friend istream& operator>>(istream&,CHAUFFEUR*);

        void enregistrer_ch();
        void recuperer_ch();
        virtual ~CHAUFFEUR();

};*/

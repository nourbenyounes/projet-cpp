#ifndef AMBULANCIER_H
#define AMBULANCIER_H
using namespace std;
#include <EMPLOYE.h>
#include<vector>
#include<iomanip>
#include<fstream>

class AMBULANCIER : public EMPLOYE
{
    private:
        string horaire;
        string categorie;
        vector<int> nb_cas; //une liste qui contient les nombre des cas par mois
    public:
        AMBULANCIER();
        AMBULANCIER(const AMBULANCIER&);

        float calcul_salaire_trimestriel();

        AMBULANCIER& operator=(AMBULANCIER&);

        friend ostream& operator<< (ostream&,AMBULANCIER&);
        friend istream& operator>> (istream&,AMBULANCIER&);

        friend ostream& operator<<(ostream&,AMBULANCIER*);
        friend istream& operator>>(istream&,AMBULANCIER*);

        void enregistrer_am();
        void recuperer_am();
        void afficher_ambulancier();

        virtual ~AMBULANCIER();


};

#endif // AMBULANCIER_H
/*template<class I,class F>
class AMBULANCIER : public EMPLOYE<I,F>
{
    private:
        string horaire;
        string categorie;
        vector<int> nb_cas; //une liste qui contient les nombre des cas par mois
    public:
        AMBULANCIER();
        AMBULANCIER(const AMBULANCIER&);

        float calcul_salaire_trimestriel();

        AMBULANCIER& operator=(AMBULANCIER&);

        friend ostream& operator<< <>(ostream&,AMBULANCIER&);
        friend istream& operator>> <>(istream&,AMBULANCIER&);

        friend ostream& operator<<(ostream&,AMBULANCIER*);
        friend istream& operator>>(istream&,AMBULANCIER*);

        void enregistrer_am();
        void recuperer_am();

        virtual ~AMBULANCIER();


};*/

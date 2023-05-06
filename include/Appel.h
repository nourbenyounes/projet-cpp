#ifndef APPEL_H
#define APPEL_H
#include<string>
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Appel
{
      private:
    int num_appel;
    string localisation;
    string temps;
    public:
        Appel();
        int getNumApp(){return num_appel;}
        Appel operator> (Appel&);
        friend ostream& operator<<(ostream&, Appel&);
        friend istream&operator>>(istream& , Appel &);
        friend ostream& operator<<(ostream&, Appel*);
        friend istream&operator>>(istream& , Appel*);
        void enregistrer_ap();
        void recuperer_ap();
        void afficher_appel();

        virtual ~Appel();

};



#endif // APPEL_H

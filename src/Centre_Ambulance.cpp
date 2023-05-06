#include "Centre_Ambulance.h"

Centre_Ambulance::Centre_Ambulance()
{
    id_centre=0;

}

Centre_Ambulance::Centre_Ambulance(const Centre_Ambulance& centre)
{
    id_centre = centre.id_centre;
    for (const auto& it : centre.amb) {
        ambulance a(it.second); // Copie l'ambulance
        amb.insert(make_pair(it.first, a)); // Ins�re la copie dans la nouvelle map
    }
    equipement eQ;
    for (int i = 0; i < centre.eq.size(); i++) {
        eQ=equipement(centre.eq[i]);
        eq.push_back(eQ);
    }
    EMPLOYE *e;
   for(int i=0;i<centre.emp.size();i++)
    {
        if(typeid(*centre.emp[i])==typeid(CHAUFFEUR))
            e=new CHAUFFEUR(static_cast<const CHAUFFEUR&>(*centre.emp[i]));
        else
            e=new AMBULANCIER(static_cast<const AMBULANCIER&>(*centre.emp[i]));
        emp.push_back(e);
    }
     for (list<Hopital>::const_iterator it = centre.hop.begin(); it != centre.hop.end(); it++) {
        hop.push_back(*it);
    }
   for(int i=0;i<centre.app.size();i++)
    {   Appel *A=new Appel;
        app.push_back(centre.app[i]);}
}

//ajout

void Centre_Ambulance::ajouter_employe()
{                   EMPLOYE* e;
                int choixa;
                cout<<"\n [AJOUT] \n taper 1: chauffeur ; taper 2: ambulancier "<<endl;
                cin>>choixa;
                if(choixa==1)
                {
                    e=new CHAUFFEUR();
                    cin >>static_cast<CHAUFFEUR&>(*e);
                }
                else if (choixa==2)
                {
                    e=new AMBULANCIER();
                    cin >>static_cast<AMBULANCIER&>(*e);
                }
                else
                {
                    cout<<" \n choix invalide "<<endl;

                }
    emp.push_back(e);
}
void Centre_Ambulance::ajouter_ambulance(ambulance a)
{
     amb.insert(make_pair(a.getIdAmbulance(), a));
}
void Centre_Ambulance::ajouter_equipement(equipement e)
{
    eq.push_back(e);
}
void Centre_Ambulance::ajouter_appel(Appel a)
{
    app.push_back(a);
}
void Centre_Ambulance::ajouter_hopital(Hopital h)
{
    hop.push_back(h);
}

//supprission

void Centre_Ambulance::supprimer_employe(int id)
{
  emp.erase(
        remove_if(emp.begin(), emp.end(),
        [&](EMPLOYE* e) { return e->getIdEmp() == id; }), emp.end()
    );
}

void Centre_Ambulance::supprimer_ambulance(int id)
{
    auto it = amb.find(id);
    if (it != amb.end())
    {
        amb.erase(it);
    }
}
void Centre_Ambulance::supprimer_equipement(int id)
{
    int ind;
    for(int i=0;i<eq.size();i++)
    {
        if(eq[i].getIdMat()==id)
            ind=i;
    }
    eq.erase(eq.begin()+ind);
}
void Centre_Ambulance::supprimer_appel(int num)
{
    int ind;
    for(int i=0;i<app.size();i++)
    {
        if(app[i].getNumApp()==num)
            ind=i;
    }
    app.erase(app.begin()+ind);
}


void Centre_Ambulance::supprimer_hopital(string nom)
{
    // Recherche de l'�l�ment de la liste avec le nom donn�
    auto it = find_if(hop.begin(), hop.end(), [nom](Hopital& h) { return h.getNomHop() == nom; });

    // Si l'�l�ment est trouv�, supprimer l'�l�ment de la liste
    if (it != hop.end()) {
        hop.erase(it);
    } else {
        // Si l'�l�ment n'a pas �t� trouv�, afficher un message d'erreur
        cout << "Hopital non trouve." << endl;
    }
}


//modification
void Centre_Ambulance::modifier_employe(int id)
{
    int ind;
    EMPLOYE* e;
                int choixa;
                cout<<"\n[MODIFICATION]\n taper 1: chauffeur ; taper 2: ambulancier "<<endl;
                cin>>choixa;
                if(choixa==1)
                {
                    e=new CHAUFFEUR();

                    cin >>static_cast<CHAUFFEUR&>(*e);
                }
                else if (choixa==2)
                {
                    e=new AMBULANCIER();
                    cout<<"Donner l'id du chauffeur à modifier"<<endl;
                    cin>>id;
                    cin >>static_cast<AMBULANCIER&>(*e);
                }
                else
                {
                    cout<<" \n choix invalide "<<endl;

                }
    for(int i=0;i<emp.size();i++)
    {
        if(emp[i]->getIdEmp()==id)
            ind=i;
    }
    emp[ind]=e;
}



void Centre_Ambulance::modifier_ambulance(ambulance a)
{
    int id;
    id=a.getIdAmbulance();
    ambulance& am = amb.at(id);
    int nDisp=a.getD();
    am.sD(nDisp);

}





void Centre_Ambulance::modifier_equipement(equipement e,int id)
{
    int ind;
    for(int i=0;i<eq.size();i++)
    {
        if(eq[i].getIdMat()==id)
            ind=i;
    }
    eq[ind]=e;

}
void Centre_Ambulance::modifier_appel(Appel a,int num)
{
    int ind;
    for(int i=0;i<app.size();i++)
    {
        if(app[i].getNumApp()==num)
            ind=i;
    }
    app[ind]=a;
}

//write

istream& operator>>(istream& in, Centre_Ambulance& centre) {

    cout << "Entrez l'ID du centre : "<<endl;
    in>>centre.id_centre;

    cout<<"___________________________________"<<endl;
    cout<<"++++++++++++++EMPLOYEES+++++++++++++"<<endl;
    cout<<"___________________________________"<<endl;

    EMPLOYE *e;
    int choixa;
    char rep;
    cout<<" \n remplissage la liste des employes "<<endl;
    do
    {
        cout<<"\n taper 1: chauffeur ; taper 2: ambulancier "<<endl;
        in>>choixa;
        if(choixa==1)
        {
            e=new CHAUFFEUR();
            in >>static_cast<CHAUFFEUR&>(*e);
        }
        else if (choixa==2)
        {
            e=new AMBULANCIER();
            in >>static_cast<AMBULANCIER&>(*e);
        }
        else
        {
            cout<<" \n choix invalide "<<endl;

        }

        centre.emp.push_back(e);
        cout<<"\n rajouter d'autre employe? (o:oui ;n:non) "<<endl;
        in>>rep;
    }
    while(rep=='o' || rep=='O');
    cout<<"___________________________________"<<endl;
    cout<<"++++++++++++++AMBULANCES+++++++++++++"<<endl;
    cout<<"___________________________________"<<endl;

    cout<<"combien y-a-t-il d ambulances dans le centre?"<<endl;
    int choix;
    in>>choix;
  // exception
    try
    {
    if (choix <= 0) throw -1;

    for (int i = 0; i < choix; i++)
    {
        ambulance a = ambulance();
        cout << "Entrez les informations des ambulances : " << endl;
        cout << "Ambulance: " << i + 1 << " : " << endl;
        in >> a;
        centre.amb[a.getIdAmbulance()] = a;
        cout<<"___________________________________"<<endl;
    }
    }
    catch (int e)
    {
    cout << " le nombre d'ambulance est errone " << endl;
    }

    cout<<"___________________________________"<<endl;
    cout<<"++++++++++++++EQUIPEMENT+++++++++++++"<<endl;
    cout<<"___________________________________"<<endl;

char choix2;
    int i=0;
    do
    {
        equipement eQ= equipement();
        centre.eq.push_back(eQ);
        cout << "Entrez ses informations : " << endl;
        cout << "Materiel: " << i+1 << " : " << endl;
        in >> centre.eq[i];
        cout<<"\n Voulez-vous ajouter un materiel( 1:oui || 0: non) ?? "<<endl;
        cin>>choix2;
        i++;
        cout<<"___________________________________"<<endl;

    }
    while(choix2=='1');

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++++HOPITAL++++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;

    Hopital H;
    cout<<" Remplissage du tableau des hopitaux "<<endl;
    int nbH;
    cout<<" Entrer le nombre des hopitaux "<<endl;
    cin>>nbH;
    for(int i=0;i<nbH;i++)
    {   cin>>(H);
        centre.hop.push_back(H);
        cout<<"_____________________________________"<<endl;}

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++APPEL+++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;
    Appel A;
    cout<<" APPEL "<<endl;
    int ch;
    do
    {
        cin>>A;
        centre.app.push_back(A);
        cout<<"Nouveau appel? (1:(oui) 0:(non))"<<endl;
        cin>>ch;
    }
    while(ch==1);
    cout<<"___________________________________"<<endl;


    return in;

    }

//read

ostream& operator<<(ostream& out,Centre_Ambulance& centre)
{
    out<<"\n Id du centre: "<<centre.id_centre<<endl;

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++++AMBULANCES++++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;

    for_each(centre.amb.begin(), centre.amb.end(),
    [&](pair<const int, ambulance>& a) {
        int id = const_cast<int&>(a.first);
        out << "Ambulance: " << id << " : " << a.second << endl;
        cout<<"___________________________________"<<endl;

    });


    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++EQUIPEMENT++++++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;

    for (int i=0;i<centre.eq.size(); i++)
       {cout << "item :" << i+1 << " : " << centre.eq[i]<< endl;
        cout<<"___________________________________"<<endl;}

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++++HOPITAL+++++++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;
    for (auto it = centre.hop.begin(); it != centre.hop.end(); it++) {
    cout << *it << endl;
    cout << "_____________________________________" << endl;
    }

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++++++APPEL+++++++++++++++ "<<endl;
    cout<<"___________________________________"<<endl;
    for(int i=0;i<centre.app.size();i++)
     {cout<<centre.app[i];
     cout<<"_____________________________________"<<endl;}

    cout<<"___________________________________"<<endl;
    cout<<" ++++++++++LISTE_EMPLOYEES+++++++++ "<<endl;
    cout<<"___________________________________"<<endl;

for(int i=0;i<centre.emp.size();i++)
    {
        if(typeid(*centre.emp[i])==typeid(CHAUFFEUR))
        {
            cout<<"Employe "<<i+1<<" :CHAUFFEUR "<<endl;
           cout<< static_cast<CHAUFFEUR&>(*centre.emp[i]);}

        else if(typeid(*centre.emp[i])==typeid(AMBULANCIER))
           {cout<<"Employe "<<i+1<<" :AMBULANCIER "<<endl;
           cout<< static_cast<AMBULANCIER&>(*centre.emp[i]);
           }

           cout<<"___________________________________"<<endl;
    }

    return out;
}
//affichage
    void Centre_Ambulance::afficher_lesAmb(){

        for(auto const& element : amb) {
            int id = element.first;
            ambulance a = element.second;
            cout << "Ambulance " << id << " : " << a << endl;
        }}
    void Centre_Ambulance::afficher_lesEmp(){

            for(int i=0;i<emp.size();i++)
    {
        if(typeid(*emp[i])==typeid(CHAUFFEUR))
        {
            cout<<"Employe "<<i+1<<" :CHAUFFEUR "<<endl;
           cout<< static_cast<CHAUFFEUR&>(*emp[i]);
            cout<<"***********************"<<endl;}
        else if(typeid(*emp[i])==typeid(AMBULANCIER))
           {cout<<"Employe "<<i+1<<" :AMBULANCIER "<<endl;
           cout<< static_cast<AMBULANCIER&>(*emp[i]);
           cout<<"***********************"<<endl;

           } }

    }
    void Centre_Ambulance::afficher_lesEq(){
            for (int i=0;i<eq.size(); i++)
           {cout << "L'equipement No :" << i+1 << "est" << eq[i]<< endl;
            cout<<"********************************"<<endl;}
    }
    void Centre_Ambulance::afficher_lesHops(){
                for (auto it = hop.begin(); it != hop.end(); it++) {
                cout << *it << endl;
                cout << "*******************************" << endl;
                }
    }
    void Centre_Ambulance::afficher_lesApp(){
            for (int i=0;i<app.size(); i++)
           {cout << "L'appel No :" << i+1 << "est" << app[i]<< endl;
            cout<<"********************************"<<endl;}

    }



map<int,ambulance> Centre_Ambulance::getAmbulances(){
    return amb;
}


vector<equipement> Centre_Ambulance::getEq(){return eq;}
vector<Appel> Centre_Ambulance::getApp(){return app;}

vector<EMPLOYE*> Centre_Ambulance::getEmployes(){
    return emp;
}
list<Hopital> Centre_Ambulance::gethops(){return hop;}

//recherche
EMPLOYE* Centre_Ambulance::trouverEmploye(int id) {
    for (EMPLOYE* e : emp) {
        if (e->getIdEmp() == id) {
            return e;
        }
    }
    return nullptr; // Employé non trouvé
}
void Centre_Ambulance::trouveAmb(int id)
{
    try {
        ambulance& am = amb.at(id);
        cout << am << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Erreur: l'ID d'ambulance " << id << " n'existe pas." << endl;
    }
}

void Centre_Ambulance::trouveEq(int id)
{
    int ind;
    for(int i=0;i<eq.size();i++)
    {
        if(eq[i].getIdMat()==id)
            ind=i;
    }
    cout<<eq[ind]<<endl;
}
void Centre_Ambulance::trouveHop(string nom){
     auto it = find_if(hop.begin(), hop.end(), [nom](Hopital& h) { return h.getNomHop() == nom; });
    if (it != hop.end()) { cout<<* it<<endl;}
    else {cout<<"L'hopital avec un tel nom ne se trouve pas"<<endl;}



}

void Centre_Ambulance::trouveApp(int id)
{
    int ind;
    for(int i=0;i<app.size();i++)
    {
        if(app[i].getNumApp()==id)
            ind=i;
    }
    cout<<app[ind]<<endl;
}






void Centre_Ambulance::modifier_hopital(string nom, Hopital h) {
    for (auto it = hop.begin(); it != hop.end(); ++it) {
        if (it->getNomHop() == nom) {
            *it = h; // Modifier l'hôpital
        }
    }
}



Centre_Ambulance::~Centre_Ambulance()
{
  for(int i=0;i<emp.size();i++)
      delete emp[i];
  emp.clear();
}

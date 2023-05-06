#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "EMPLOYE.h"
#include "AMBULANCIER.h"
#include "CHAUFFEUR.h"
#include "Hopital.h"
#include "equipement.h"
#include "ambulance.h"
#include "Centre_Ambulance.h"
#include "Appel.h"

using namespace std;

void afficher_menu_principal() {
    cout << "====== MENU PRINCIPAL ======" << endl;
    cout << "1. Gestion des ambulances" << endl;
    cout << "2. Gestion des employes" << endl;
    cout << "3. Gestion des equipements" << endl;
    cout << "4. Gestion des hôpitaux" << endl;
    cout << "5. Gestion des appels" << endl;
    cout << "6. Afficher le centre" << endl;
    cout << "7. Remplir le fichier" << endl;
    cout << "8. Afficher le fichier" << endl;
   cout << "9. Quitter" << endl;
    cout << "====== MENU PRINCIPAL ======" << endl;

}

void afficher_menu_ambulance() {
    cout << "====== MENU GESTION DES AMBULANCES ======" << endl;
    cout << "1. Ajouter une ambulance" << endl;
    cout << "2. Modifier une ambulance" << endl;
    cout << "3. Afficher les ambulances" << endl;
    cout << "4. Rechercher une ambulance" << endl;
    cout << "5. Supprimer une ambulance" << endl;
    cout << "6. Retour au menu principal" << endl;
    cout << "====== MENU GESTION DES AMBULANCES ======" << endl;

}

void afficher_menu_employe() {
cout << "====== MENU GESTION DES EMPLOYES ======" << endl;
cout << "1. Ajouter un employe" << endl;
cout << "2. Modifier un employe" << endl;
cout << "3. Afficher les employe" << endl;
cout << "4. Rechercher un employe" << endl;
cout << "5. Supprimer un employe" << endl;
cout << "6. Retour au menu principal" << endl;
cout << "====== MENU GESTION DES EMPLOYES ======" << endl;

}

void afficher_menu_equipement() {
cout << "====== MENU GESTION DES EQUIPEMENTS ======" << endl;
cout << "1. Ajouter un équipement" << endl;
cout << "2. Modifier un équipement" << endl;
cout << "3. Afficher les équipements" << endl;
cout << "4. Rechercher un équipement" << endl;
cout << "5. Supprimer un équipement" << endl;
cout << "6. Retour au menu principal" << endl;
cout << "====== MENU GESTION DES EQUIPEMENTS ======" << endl;

}

void afficher_menu_hopital() {
cout << "====== MENU GESTION DES HOPITAUX ======" << endl;
cout << "1. Ajouter un hôpital" << endl;
cout << "2. Modifier un hôpital" << endl;
cout << "3. Afficher les hôpitaux" << endl;
cout << "4. Rechercher un hôpital" << endl;
cout << "5. Supprimer un hôpital" << endl;
cout << "6. Retour au menu principal" << endl;
cout << "====== MENU GESTION DES HOPITAUX ======" << endl;

}

void afficher_menu_appel() {
cout << "====== MENU GESTION DES APPELS ======" << endl;
cout << "1. Ajouter un appel" << endl;
cout << "2. Modifier un appel" << endl;
cout << "3. Afficher les appels" << endl;
cout << "4. Rechercher un appel" << endl;
cout << "5. Supprimer un appel" << endl;
cout << "6. Retour au menu principal" << endl;
cout << "====== MENU GESTION DES APPELS ======" << endl;

}

int main(){
    int n=0;
    Centre_Ambulance centre;
    cout<<"Remplissez votre centre:"<<endl;
    //cin>>centre;
    while (n!=9){
        afficher_menu_principal();
        cout<<"Donner un choix"<<endl;
        cin>>n;
        if(n==1){
    int choix1=0;
    while(choix1 !=6){
        afficher_menu_ambulance();
        choix1=0;
        cout<<"Donner un choix"<<endl;
        cin>>choix1;
        if(choix1==1){
            int ajout_ambulance=1;
            if (ajout_ambulance == 1) {
                ambulance a;
                cin >> a;
                centre.ajouter_ambulance(a);
            }
        }
        else if(choix1==2){
            ambulance a;
            cin>>a;
            centre.modifier_ambulance(a);
        }
        else if (choix1==3){
                centre.afficher_lesAmb();

}else if (choix1==4){
            int id;
            cout<<"Donner L'id de l'ambulance à trouver"<<endl;
            cin>>id;
            centre.trouveAmb(id);
       }
                else if(choix1==5){
            int id;
            cout<<"donner L'id de l'ambulance à supprimer"<<endl;
            cin>>id;
            centre.supprimer_ambulance(id);
        }else if (choix1>6){cout<<"choix invalide"<<endl;}
    }
}else if(n==2){
    int choix2=0;

    while(choix2 !=6){
        afficher_menu_employe();
        choix2=0;
        cout<<"Donner un choix"<<endl;
        cin>>choix2;
        if(choix2==1){
               centre.ajouter_employe();

        }else if (choix2==2){
                int id;
                    cout<<"Donner l'id de l'emloye à modifier"<<endl;
                    cin>>id;

                centre.modifier_employe(id);

        }
        else if(choix2==3){
                centre.afficher_lesEmp();

        }else if(choix2==4){
            int id;
            cout << "Entrez l'ID de l'employé à trouver: ";
            cin >> id;

            EMPLOYE* e = centre.trouverEmploye(id);
            if (e == nullptr) {
                cout << "Employé non trouvé." << endl;
            } else {
                cout << "\n Employé trouvé: " << *e << endl;
            }
            }else if (choix2==5){
                        int id;
                        cout << "Entrez l'ID de l'employé à supprimer: ";
                        cin >> id;

                        EMPLOYE* e = centre.trouverEmploye(id);
                        if (e != nullptr)  {
                            centre.supprimer_employe(id);
                        }
                    }else if (choix2>6){cout<<"choix invalide"<<endl;}}}
else if(n==3){
        int choix3=0;
        while(choix3 !=6){
        afficher_menu_equipement();
        choix3=0;
        cout<<"Donner un choix"<<endl;
        cin>>choix3;
        if(choix3==1){
            equipement eq;
            cin>>eq;
            centre.ajouter_equipement(eq);
        }else if(choix3==2){
            int id;
            equipement eq;
            cout<<"Donner l'id de l'equipement à modifier"<<endl;
            cin>>id;
            cout<<"donner le nouvel equipement"<<endl;
            cin>>eq;
            centre.modifier_equipement(eq,id);

        }else if (choix3==3){
            centre.afficher_lesEq();

        }else if(choix3==5){
            int id;
            cout<<"Donner l'id de l'equipement à supprimer"<<endl;
            cin>>id;
            centre.supprimer_equipement(id);
        }else if(choix3==4){
            int id;
            cout<<"Donner l'id de l'equipement à trouver"<<endl;
            cin>>id;
            centre.trouveEq(id);

        }else if (choix3>6){cout<<"choix invalide"<<endl;}}}

else if (n==4){
    int choix4=0;
        while(choix4 !=6){
        afficher_menu_hopital();
        choix4=0;
        cout<<"Donner un choix"<<endl;
        cin>>choix4;
        if(choix4==1){
                Hopital h;
                cin>>h;
                centre.ajouter_hopital(h);}
        else if(choix4==4){
            string nom;
            cout<<"Donner le nom de l'hopital à trouver"<<endl;
            cin>>nom;
            centre.trouveHop(nom);
        }
        else if(choix4==3){
                centre.afficher_lesHops();

        }else if(choix4==2){
            string nom;
            Hopital hop;
            cout<<"Donner le nom de l'hopital à modifier"<<endl;
            cin>>nom;
            cin>>hop;
            centre.modifier_hopital(nom,hop);

        }else if(choix4==5){
            string nom;
            cout<<"Donner le nom de l'hopital à supprimer"<<endl;
            cin>>nom;
            centre.supprimer_hopital(nom);
        }else if(choix4>6){cout<<"Choix invalide"<<endl;}}}

else if (n==5){

       int choix5=0;
        while(choix5 !=6){
        afficher_menu_appel();
        choix5=0;
        cout<<"Donner un choix"<<endl;
        cin>>choix5;
        if(choix5==1){
                Appel app;
                cin>>app;
                centre.ajouter_appel(app);}
        else if (choix5==4){
            int id;
            cout<<"donner l'id de l'appel à trouver"<<endl;
            cin>>id;
            centre.trouveApp(id);
        }else if(choix5==3){
            centre.afficher_lesApp();

        }else if(choix5==2){
            int id;
            Appel a;
            cout<<"Donner l'id de l'appel à modifier"<<endl;
            cin>>id;
            cin>>a;
            centre.modifier_appel(a,id);


        }else if (choix5==5){
            int id;
            cout<<"Donner l'id de l'appel à supprimer"<<endl;
            cin>>id;
            centre.supprimer_appel(id);


        }else if(choix5>6){cout<<"choix invalide"<<endl;}
}}
else if (n==6){cout<<centre<<endl;}
else if (n>9){cout<<"Choix invalide"<<endl;}
else if(n==7){
    vector<equipement> eq;
    eq=centre.getEq();
    for (int i=0;i<eq.size(); i++)
           {  eq[i].enregistrer_eq()  ;
               }
        vector<Appel> app;
    app=centre.getApp();
    for (int i=0;i<app.size(); i++)
           {  app[i].enregistrer_ap()  ;
               }
                map<int, ambulance> ambulances = centre.getAmbulances();

        for(auto const& element : ambulances) {
            int id = element.first;
            ambulance a = element.second;
            a.enregistrer_amb();
        }        list<Hopital> hop;
                hop=centre.gethops();
                for (auto it = hop.begin(); it != hop.end(); it++) {
                        it->enregistrer_hop();
                        }
    vector<EMPLOYE*> emp = centre.getEmployes();
    for(int i=0; i<emp.size(); i++) {
        if(typeid(*emp[i])==typeid(CHAUFFEUR)) {
            dynamic_cast<CHAUFFEUR*>(emp[i])->enregistrer_ch();
        }
        else if(typeid(*emp[i])==typeid(AMBULANCIER)) {
            dynamic_cast<AMBULANCIER*>(emp[i])->enregistrer_am();
        }
    }


}else if (n==8){
    ambulance amb;
    amb.afficher_amb();
    Hopital hop;
    hop.afficher_hop();
    Appel app;
    app.afficher_appel();
    equipement eq;
    eq.afficher_eq();

}
}

return 1;
}

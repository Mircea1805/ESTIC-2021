#include <iostream>
#include <cstring>
#include <iomanip>
#include "editura.h"
#include "publicatie.h"

using namespace std;

extern editura ed[10];
extern int nE;

//GUI
 void tipar_pub (publicatie pub[], int n) //tipareste o publicatie
{
    for(int i = 0; i < n; i++){
    cout<<"Titlu:     "<<pub[i].titlu<<endl;
    cout<<"Editura:   "<<nume_ed(ed,nE,pub[i].id_editura)<<endl;
    cout<<"Pret:      "<<pub[i].pret<<endl;
    cout<<"Frecventa: "<<pub[i].frecv<<endl;
    cout<<"------------------------------------"<<endl;
    }
}

/* CR U D */

int adauga_pub (publicatie pub[],  int &n)
 {   //se va testa in prealabil daca mai pot adauga, in caz contrar returneaza -1
     //id-ul este si numarul de ordine
     cout<<"A D A U G A R E    P U B L I C A T I E:"<<endl;
     pub[n].id_pub=n;
     //citeste titlul
     cout<<"Titlul publicatiei: ";cin.getline(pub[n].titlu,50);
     cout<<"Pretul publicatiei: ";cin >> pub[n].pret;
     cin.get();
     cout<<"Frecventa publicatiei (intervalul de timp in zile dintre doua numere): ";cin >> pub[n].frecv;
     cin.get();
     // va mai adauga si editura, pt demonstratie se initializeaza cu 0
     int x;
     do{
       cout<<"Selectie editura dupa nume"<<endl;
       x=cauta_ed(ed,nE);
      if(x>=0) pub[n].id_editura=x;
       else cout<<"Introdu un nume de editura care exista."<<endl;
     } while (x<0);
     cout<<"Adaugare efectuata!"<<endl;
     n++;
     return n;
 }

 int cauta_pub (publicatie pub[],  int n)
 {   //cautare dupa titlu, daca gaseste returneaza indicele
     //altfel returneaza -1
     char titlu[50];
     cout<<"Cauta dupa titlu publicatie: ";cin.getline(titlu,50);
     for ( int i=0;i<n;i++) //returneaza primul indice pe care il gaseste
        if (strcmp(pub[i].titlu, titlu)==0) return i;
     return -1;
 }

 int modifica_pub (publicatie pub[],  int n)
 {   cout<<"M O D I F I C A R E    P U B L I C A T I E"<<endl;
     int x=cauta_pub(pub,n);
     if (x<0)
     {
         cout<<"Publicatia cu acest titlu nu exista!"<<endl;
         return -1;
     }
     cout<<"Introduceti noile informatii despre publicatie"<<endl;
     //citeste titlul
     cout<<"Noul titlu al publicatiei:";cin.getline(pub[x].titlu,50);
     // idem cauta noua editura
     int y;
     do{
       cout<<"Selectie editura dupa nume"<<endl;
       y=cauta_ed(ed,nE);
       if(y>=0) pub[n].id_editura=y;
       else cout<<"Introdu un nume de editura care exista."<<endl;
     } while (y<0);
     cout<<"Modificare efectuata!"<<endl;
     return x; // este >=0 daca s-a modificat cu succes.
 }

 int sterge_pub (publicatie pub[],  int &n)
 {   cout<<"S T E R G E R E    P U B L I C A T I E"<<endl;
     int x=cauta_pub(pub,n);
     if (x<0)
     {
         cout<<"Publicatia cu acest titlu nu exista!"<<endl;
         return -1;
     }

     cout<<"Confirmati stergerea? (d/n)";
     char ch; cin>>ch; cin.get();
     if (ch=='d' || ch=='D')
     {
         for (int i=x;i<n-1;i++) pub[i]=pub[i+1];
         n--;
         cout<<"Stergere efectuata!"<<endl;
         return x; // este >=0 daca s-a sters cu succes.
     }
     else
        return -1;
 }

 char* nume_pub(publicatie pub[],  int n, int id_pub){
    char *res = new char[50];
    for(int i = 0; i < n; i++){
        if(pub[i].id_pub == id_pub){
            strcpy(res, pub[i].titlu);
        }
    }
    return res;
}

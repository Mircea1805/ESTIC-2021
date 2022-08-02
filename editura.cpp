#include "editura.h"
#include <iostream>
#include <cstring>
using namespace std;

    int adauga_ed(editura edit[],  int &n){
        //se va testa in prealabil daca mai pot adauga, in caz contrar returneaza -1
     //id-ul este si numarul de ordine
        cout<<"A D A U G A R E    E D I T U R A"<<endl;
        edit[n].id_editura=n;
     //citeste titlul
        cout<<"Titlul editurii: ";cin.getline(edit[n].nume,50);
     // va mai adauga si editura, pt demonstratie se initializeaza cu 0
        cout << "Adresa editurii: ";cin.getline(edit[n].adresa,100);
        cout << "Persoana contact: ";cin.getline(edit[n].pers_ct, 32);
        cout << "Numar telefon: ";cin.getline(edit[n].telefon,20);
        cout<<"Adaugare efectuata!"<<endl;
        n++;
        return n;
        }

    int cauta_ed (editura edit[],  int n){
        char titlu[50];
        cout<<"Cauta dupa titlu editura: ";cin.getline(titlu,50);
        for ( int i=0;i<n;i++) //returneaza primul indice pe care il gaseste
        if (strcmp(edit[i].nume, titlu)==0) return i;
        return -1;
    }

    char* nume_ed(editura edit[],  int n, int id_edit){
        char *res = new char[50];
        for(int i = 0; i < n; i++){
            if(edit[i].id_editura == id_edit){
                strcpy(res, edit[i].nume);
            }
        }
        return res;
    }

void sterge_ed(editura edit[], int &n){
    int id_ed;
    cout << "S T E R G E R E    E D I T U R A\n";
    id_ed = cauta_ed(edit, n);
    if(id_ed > 0){
        for(int i = id_ed; i < n; i++){
            edit[i] = edit[i + 1];
        }
        n--;
    }else{
        cout << "Editura nu a fost gasita\n";
    }
}

void modifica_ed(editura edit[], int n){
    int id_ed;
    cout << "M O D I F I C A R E   E D I T U R A\n";
    id_ed = cauta_ed(edit, n);
    if(id_ed >= 0){
        cout << "Denumirea: "; cin.getline(edit[id_ed].nume, 50);
        cout << "Adresa: "; cin.getline(edit[id_ed].adresa, 100);
        cout << "Persoana de contact: "; cin.getline(edit[id_ed].pers_ct, 32);
        cout << "Numar de telefon: "; cin.getline(edit[id_ed].telefon, 20);
    }
}

void tipar_ed (editura edit[], int n) //tipareste o publicatie
{
    for(int i = 0; i < n; i++){
    cout<<"Nume:                "<<edit[i].nume<<endl;
    cout<<"Adresa:              "<< edit[i].adresa <<endl;
    cout<<"Persoana de contact: " << edit[i].pers_ct << endl;
    cout<<"Telefon:             " << edit[i].telefon << endl;
    cout<<"------------------------------------"<<endl;
    }
}

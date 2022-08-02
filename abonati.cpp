#include "abonati.h"
#include "publicatie.h"
#include <iostream>
#include <cstring>
using namespace std;

void adauga_ab(abonat ab[], int &n){
    cout << "A D A U G A R E    A B O N A T\n";
    cout << "Nume abonat: "; cin.getline(ab[n].nume, 32);
    cout << "Adresa abonat: "; cin.getline(ab[n].adresa, 50);
    cout << "Telefon: "; cin.getline(ab[n].telefon, 20);
    n++;
}

int cauta_ab(abonat ab[], int n){
    char nume[32];
    cout << "C A U T A R E    A B O N A T\n";
    cout << "Introduceti numele abonatului cautat: "; cin.getline(nume, 32);
    for(int i = 0; i < n; i++)
        if(strcmp(ab[i].nume, nume) == 0)
            return i;
    return -1;
}

void sterge_ab(abonat ab[], int &n){
    int id_ab;
    cout << "S T E R G E R E    A B O N A T\n";
    id_ab = cauta_ab(ab, n);
    if(id_ab > 0){
        for(int i = id_ab; i < n; i++){
            ab[i] = ab[i + 1];
        }
        n--;
    }else{
        cout << "Abonatul nu a fost gasit\n";
    }
}

void modifica_ab(abonat ab[], int n){
    int id_ab;
    cout << "M O D I F I C A R E   A B O N A T\n";
    id_ab = cauta_ab(ab,n);
    if(id_ab >= 0){
        cout << "Nume abonat: "; cin.getline(ab[id_ab].nume, 32);
        cout << "Adresa abonat: "; cin.getline(ab[id_ab].adresa, 50);
        cout << "Telefon: "; cin.getline(ab[id_ab].telefon, 20);
    }
}

void add_pub_to_ab(abonat ab[], publicatie pub[], int na, int np){
    int id_ab, id_pub;
    cout << "A D A U G A R E   P U B L I C A T I E   L A   A B O N A T\n";
    id_ab = cauta_ab(ab, na);
    if(id_ab < 0){
        cout << "Abonatul cautat nu a fost gasit\n";
        return;
    }
    id_pub = cauta_pub(pub, np);
    if(id_pub < 0){
        cout << "Publicatia cautata nu a fost gasita\n";
        return;
    }
    ab[id_ab].id_publicatii[ab[id_ab].nr_publicatii] = id_pub;
    ab[id_ab].nr_publicatii++;
}

void tipar_ab(abonat ab[], publicatie pub[], int na, int np){
    for(int i = 0; i < na; i++){
        cout<<"Nume:       "<<ab[i].nume<<endl;
        cout<<"Adresa:     " << ab[i].adresa << endl;
        cout<<"Telefon:    " << ab[i].telefon << endl;
        cout<<"Abonamente: "; for(int j = 0; j < ab[i].nr_publicatii; j++) cout << nume_pub(pub, np, ab[i].id_publicatii[j]) << "; ";
        cout << endl;
        cout<<"------------------------------------"<<endl;
    }
}

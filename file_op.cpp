#include "editura.h"
#include "publicatie.h"
#include "abonati.h"
#include <fstream>
using namespace std;

void read_file(char filename[256], editura edit[], publicatie pub[], abonat ab[], int &ne, int &np, int &na){
    ifstream fin(filename);
    fin >> ne;
    fin.get();
    for(int i = 0; i < ne; i++){
        fin >> edit[i].id_editura;
        fin.get();
        fin.getline(edit[i].nume, 32);
        fin.getline(edit[i].adresa,100);
        fin.getline(edit[i].pers_ct, 32);
        fin.getline(edit[i].telefon,20);
    }
    fin >> np;
    fin.get();
    for(int i = 0; i < np; i++){
        fin >> pub[i].id_pub >> pub[i].id_editura >> pub[i].frecv >> pub[i].pret;
        fin.get();
        fin.getline(pub[i].titlu, 50);
    }
    fin >> na;
    fin.get();
    for(int i = 0; i < na; i++){
        fin >> ab[i].nr_publicatii;
        if(ab[i].nr_publicatii > 0)
        for(int j = 0; j < ab[i].nr_publicatii; j++){
            fin >> ab[i].id_publicatii[j];
        }
        fin.get();
        fin.getline(ab[i].nume, 32);
        fin.getline(ab[i].adresa, 100);
        fin.getline(ab[i].telefon, 20);
    }
    fin.close();
}

void write_file(char filename[256], editura edit[], publicatie pub[], abonat ab[], int ne, int np, int na){
    ofstream fout("temp");
    fout << ne << endl;
    for(int i = 0; i < ne; i++){
        fout << edit[i].id_editura << endl;
        fout << edit[i].nume << endl;
        fout << edit[i].adresa << endl;
        fout << edit[i].pers_ct << endl;
        fout << edit[i].telefon << endl;
    }
    fout << np << endl;
    for(int i = 0; i < np; i++){
        fout << pub[i].id_pub << ' ' <<pub[i].id_editura << ' ' << pub[i].frecv << ' ' << pub[i].pret << endl;
        fout << pub[i].titlu <<endl;
    }
    fout << na << endl;
    for(int i = 0; i < na; i++){
        fout << ab[i].nr_publicatii;
        for(int j = 0; j < ab[i].nr_publicatii; j++){
            fout << ' ' << ab[i].id_publicatii[j];
        }
        fout << endl;
        fout << ab[i].nume << endl;
        fout << ab[i].adresa << endl;
        fout << ab[i].telefon << endl;
    }
    fout.close();
    remove(filename);
    rename("temp", filename);
}

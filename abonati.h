#ifndef ABONATI_H_INCLUDED
#define ABONATI_H_INCLUDED

#include "publicatie.h"

struct abonat
{
    char nume[32];
    char adresa[100];
    char telefon[20];
    int id_publicatii[1000];
    int nr_publicatii;
};

void adauga_ab(abonat ab[], int &n);
int cauta_ab(abonat ab[], int n);
void sterge_ab(abonat ab[], int &n);
void modifica_ab(abonat ab[], int n);
void add_pub_to_ab(abonat ab[], publicatie pub[], int na, int np);
void tipar_ab(abonat ab[], publicatie pub[], int na, int np);

#endif // ABONATI_H_INCLUDED

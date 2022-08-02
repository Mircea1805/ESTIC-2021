#ifndef EDITURA_H_INCLUDED
#define EDITURA_H_INCLUDED
struct editura
{
     int id_editura;
     char nume[50];
     char adresa[100];
     char pers_ct[32];
     char telefon[20];
     // plus alte campuri
};


/* C R U D */

    int adauga_ed(editura edit[],  int &n);
    int cauta_ed (editura edit[],  int n);
    void sterge_ed(editura edit[], int &n);
    void modifica_ed(editura edit[], int n);
    char* nume_ed(editura [],  int , int );
    void tipar_ed (editura edit[], int n);

// etc.

#endif // EDITURA_H_INCLUDED

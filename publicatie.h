#ifndef PUBLICATIE_H_INCLUDED
#define PUBLICATIE_H_INCLUDED

struct publicatie
{
     int id_pub, id_editura;
     char titlu[50];
     int frecv;
     int pret;
};

/* CR U D */
//GUI
void tipar_pub (publicatie pub[], int n); //tipareste o publicatie
int adauga_pub (publicatie pub[],  int &n);
int cauta_pub (publicatie pub[],  int n);
int modifica_pub (publicatie pub[],  int n);
int sterge_pub (publicatie pub[],  int &n);
char* nume_pub(publicatie pub[],  int n, int id_pub);

#endif // PUBLICATIE_H_INCLUDED

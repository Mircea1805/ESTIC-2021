#include <iostream>
#include "editura.h"
#include "publicatie.h"
#include "abonati.h"
#include "file_op.h"

using namespace std;

 editura ed[10];
 publicatie pub[100];
 abonat ab[100];
 char file[256];
 int nE = 0, nP = 0, nA = 0;

 void tipar_abonamente(editura edit[], publicatie pub[], abonat ab[], int ne, int np, int na){
    cout << "E D I T U R I\n";
    for(int i = 0; i < ne; i++){
        cout << i + 1 << ". " << edit[i].nume << ", " << edit[i].adresa << ", " << edit[i].telefon << endl;
    }
    cout << "\nP U B L I C A T I I\n";
    for(int i = 0; i < np; i++){
        cout << i + 1 << ". " << pub[i].titlu << ", " << pub[i].pret << " RON\n";
    }
    cout << "\nA B O N A T I\n";
    for(int i = 0; i < na; i++){
        cout << i + 1 << ". " << ab[i].nume << ", " << ab[i].telefon << ", abonat la " << ab[i].nr_publicatii << " publicatii\n";
    }
    cout << endl;
 }

int main()
{
    int opt = 0;
    do{
        cout << "1. Citire din fisier\nO P T I U N I   E D I T U R I:\n2. Afisare edituri\n3. Adauga editura\n4. Sterge editura\n5. Modifica o editura existenta\n\nO P T I U N I   P U B L I C A T I E:\n6. Afisare publicatii\n7. Adauga o publicatie\n8. Sterge publicatie\n9. Modifica o publicatie existenta\n\nO P T I U N I   A B O N A T I:\n10. Afisare abonati\n11. Adaugare abonat\n12. Stergere abonat\n13. Modificare un abonat existent\n14. Adaugare publicatie la abonat\n\n15. Afisare abonamente\n\n16. Iesire din program\n";
        cout << "Optiune: ";
        cin >> opt;
        cin.get();
        switch(opt){
        case 1:
            cout << "Introduceti numele fisierului: "; cin.getline(file, 256);
            read_file(file, ed, pub, ab, nE, nP, nA);
            break;
        case 2:
            tipar_ed(ed, nE);
            break;
        case 3:
            adauga_ed(ed, nE);
            break;
        case 4:
            sterge_ed(ed, nE);
            break;
        case 5:
            modifica_ed(ed, nE);
            break;
        case 6:
            tipar_pub(pub, nP);
            break;
        case 7:
            adauga_pub(pub, nP);
            break;
        case 8:
            sterge_pub(pub, nP);
            break;
        case 9:
            modifica_pub(pub, nP);
            break;
        case 10:
            tipar_ab(ab, pub, nA, nP);
            break;
        case 11:
            adauga_ab(ab, nA);
            break;
        case 12:
            sterge_ab(ab, nA);
            break;
        case 13:
            modifica_ab(ab, nA);
            break;
        case 14:
            add_pub_to_ab(ab, pub, nA, nP);
            break;
        case 15:
            tipar_abonamente(ed, pub, ab, nE, nP, nA);
            break;
        case 16:
            cout << "Introduceti numele fisierului: "; cin.getline(file, 256);
            write_file(file, ed, pub, ab, nE, nP, nA);
            break;
        default:
            cout << "Optiune invalida, incearca din nou!";
        }
        cout << "Apasati Enter pentru a continua:";
        cin.ignore();
        system("cls");
    }while(opt != 16);
    return 0;
}

#ifndef FILE_OP_H_INCLUDED
#define FILE_OP_H_INCLUDED

#include "editura.h"
#include "publicatie.h"
#include "abonati.h"

void read_file(char filename[256], editura edit[], publicatie pub[], abonat ab[], int &ne, int &np, int &na);
void write_file(char filename[256], editura edit[], publicatie pub[], abonat ab[], int ne, int np, int na);

#endif // FILE_OP_H_INCLUDED

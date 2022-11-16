#ifndef ARCHIVAR_H
#define ARCHIVAR_H
#include <string>
#include <iostream>
#include <ctime>
#include "structs.h"
using namespace std;

void TengoQueArchivar(Paciente *&array, int i, int N);
void archivar(Paciente *&archivados, int j, Paciente *&array, int i);
void activo(Paciente *&activos, int l, Paciente *&array, int i);
void notfound(Paciente *&notFound, int q, Paciente *&array, int i);

#endif
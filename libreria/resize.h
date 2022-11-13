#ifndef RESIZE_H
#define RESIZE_H
#include <string>
#include <iostream>
#include "structs.h"
using namespace std;

void resize(Paciente *&array, int &N, int cantidad_aumentar); 
void resizeCont(Contacto *&array, int &N, int cantidad_aumentar); 
void resizeCons(Consultas *&array, int &N, int cantidad_aumentar); 

#endif

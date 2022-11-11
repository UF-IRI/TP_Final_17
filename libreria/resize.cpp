#include "resize.h"


void resize(Paciente*& array, int* N, int cantidad_aumentar)
{
    *N = *N + cantidad_aumentar;
	int i = 0;
	Paciente *aux = new Paciente[*N];
	while (i < *N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
		
}
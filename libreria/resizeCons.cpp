#include "resize.h"

void resizeCons(Consultas *&array, int &N, int cantidad_aumentar) 
{
    N = N + cantidad_aumentar;
	int i = 0;
	Consultas *aux = new Consultas[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
		
}
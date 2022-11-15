#include "resize.h"

void resizeMed(Medico *&array, int &N, int cantidad_aumentar) 
{
    N = N + cantidad_aumentar;
	int i = 0;
	Medico *aux = new Medico[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
		
}
#include "resize.h"

void resizeCont(Contacto *&array, int &N, int cantidad_aumentar) 
{
    N = N + cantidad_aumentar;
	int i = 0;
	Contacto *aux = new Contacto[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
		
}
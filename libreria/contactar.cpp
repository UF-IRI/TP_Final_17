#include "contactar.h"

int Contactar()
{
    int aux;
    //cout << "Cual fue la respuesta del paciente?" << endl; //la respuesta la hace un random
    aux = rand()% (4-1) + 1;
   //cout << "Respuesta del paciente:" << aux << endl;
    return aux;
}
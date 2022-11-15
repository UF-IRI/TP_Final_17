#include "copiarPacCont.h"

 void copiarPacCont(Paciente *&array, int i, Contacto *&ArrContacto, int j)
 {
    array[i].contacto.telefono = ArrContacto[j].telefono;
    array[i].contacto.celular = ArrContacto[j].celular;
    array[i].contacto.direccion = ArrContacto[j].direccion;
    array[i].contacto.mail = ArrContacto[j].mail;
    return;

 }
  
                                
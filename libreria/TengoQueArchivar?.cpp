#include "archivar.h"

void TengoQueArchivar(Paciente *&array, int i, int N){
    
    time_t now;
    time(&now);
    int diferencia;

    for(i=0; i<N; i++){
       diferencia = difftime(now,array[i].UltimaConsulta.fecha_turno); //calculo de los años
       
       if(array[i].estado == "fallecido" || diferencia > 10){ //si esta muerto o pasaron mas de 10 años
            array[i].archivado = "ARCHIVADO";
       }

       else if (array[i].estado == "internado" || array[i].UltimaConsulta.fecha_turno > now){ //si esta internado o tiene un turno a futuro
            array[i].archivado = "ACTIVO";
       }

       else
             array[i].archivado = "CONTACTAR";

    }


}
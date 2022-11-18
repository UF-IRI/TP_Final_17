#include "archivar.h"

void TengoQueArchivar(Paciente *&array, int i, int N){
    
    time_t now;
    time(&now);
    int diferencia;

    double fecha;
    fecha = array[i].UltimaConsulta.fecha_turno.tm_year * 10000 + array[i].UltimaConsulta.fecha_turno.tm_mon *100 + array[i].UltimaConsulta.fecha_turno.tm_mday;



    for(i=0; i<N; i++){
       diferencia = difftime(now,fecha); //calculo de los años
       
       if(array[i].estado == "fallecido" || diferencia >= 10){ //si esta muerto o pasaron mas de 10 años
            array[i].archivado = "ARCHIVADO";
       }

       else if (array[i].estado == "internado" || fecha >= now){ //si esta internado o tiene un turno a futuro
            array[i].archivado = "ACTIVO";
       }

       else
             array[i].archivado = "CONTACTAR";

    }
    
    return;


}
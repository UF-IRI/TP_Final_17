#include "copiarPacCons.h"

void copiarPacCons(Paciente*& array, int i, Consultas*& ArrConsultas, int j)
{
    time_t max;
    max = 00 / 00 / 0000;
    if (ArrConsultas[j].fecha_turno > max)
    {
      array[i].UltimaConsulta.fecha_solicitado = ArrConsultas[j].fecha_solicitado;
      array[i].UltimaConsulta.fecha_turno = ArrConsultas[j].fecha_turno;
      array[i].UltimaConsulta.presento = ArrConsultas[j].presento;
      array[i].UltimaConsulta.medico = ArrConsultas[j].medico;
    }
    
    return;

}


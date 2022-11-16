#include "copiarPacCons.h"

void copiarPacCons(Paciente*& array, int i, Consultas*& ArrConsultas, int j)
{
    time_t max;
    max = 01/01/0001;
    if (ArrConsultas[j].fecha_turno > max)
    {
      array[i].UltimaConsulta.fecha_solicitado = ArrConsultas[j].fecha_solicitado;
      array[i].UltimaConsulta.fecha_turno = ArrConsultas[j].fecha_turno;
      array[i].UltimaConsulta.presento = ArrConsultas[j].presento;
      array[i].UltimaConsulta.medico.nombre = ArrConsultas[j].medico.nombre;
      array[i].UltimaConsulta.medico.apellido = ArrConsultas[j].medico.apellido;
      array[i].UltimaConsulta.medico.activo = ArrConsultas[j].medico.activo;
      array[i].UltimaConsulta.medico.especialidad = ArrConsultas[j].medico.especialidad;
      array[i].UltimaConsulta.medico.matricula = ArrConsultas[j].medico.matricula;
      array[i].UltimaConsulta.medico.telefono = ArrConsultas[j].medico.telefono;

      max = ArrConsultas[j].fecha_turno;

    }
    
    return;

}


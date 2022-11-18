#include "copiarPacCons.h"

void copiarPacCons(Paciente*& array, int i, Consultas*& ArrConsultas, int j, double max)
{
    double aux = array[i].UltimaConsulta.fecha_turno.tm_year * 10000 + array[i].UltimaConsulta.fecha_turno.tm_mon *100 + array[i].UltimaConsulta.fecha_turno.tm_mday;
    if (aux > max)
    {
      array[i].UltimaConsulta.fecha_solicitado.tm_mday = ArrConsultas[j].fecha_solicitado.tm_mday;
      array[i].UltimaConsulta.fecha_solicitado.tm_mon = ArrConsultas[j].fecha_solicitado.tm_mon;
      array[i].UltimaConsulta.fecha_solicitado.tm_year = ArrConsultas[j].fecha_solicitado.tm_year;
      array[i].UltimaConsulta.fecha_turno.tm_mday = ArrConsultas[j].fecha_turno.tm_mday;
      array[i].UltimaConsulta.fecha_turno.tm_mon = ArrConsultas[j].fecha_turno.tm_mon;
      array[i].UltimaConsulta.fecha_turno.tm_year = ArrConsultas[j].fecha_turno.tm_year;
      array[i].UltimaConsulta.presento = ArrConsultas[j].presento;      
      array[i].UltimaConsulta.medico.nombre = ArrConsultas[j].medico.nombre;
      array[i].UltimaConsulta.medico.apellido = ArrConsultas[j].medico.apellido;
      array[i].UltimaConsulta.medico.activo = ArrConsultas[j].medico.activo;
      array[i].UltimaConsulta.medico.especialidad = ArrConsultas[j].medico.especialidad;
      array[i].UltimaConsulta.medico.matricula = ArrConsultas[j].medico.matricula;
      array[i].UltimaConsulta.medico.telefono = ArrConsultas[j].medico.telefono;

      max = aux;

    }
    
    return;

}


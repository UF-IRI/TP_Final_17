#include "archivar.h"

void archivar(Paciente *&archivados, int j, Paciente *&array, int i){
    archivados[j].DNI = array[i].DNI;
    archivados[j].nombre = array[i].nombre;
    archivados[j].apellido = array[i].apellido;
    archivados[j].sexo = array[i].sexo;
    archivados[j].natalicio = array[i].natalicio;
    archivados[j].estado = array[i].estado;
    archivados[j].id_os = array[i].id_os;
    archivados[j].contacto.telefono = array[i].contacto.telefono;
    archivados[j].contacto.celular = array[i].contacto.celular;
    archivados[j].contacto.direccion = array[i].contacto.direccion;
    archivados[j].contacto.mail = array[i].contacto.mail;
    archivados[j].UltimaConsulta.fecha_solicitado.tm_mday = array[i].UltimaConsulta.fecha_solicitado.tm_mday;
    archivados[j].UltimaConsulta.fecha_solicitado.tm_mon = array[i].UltimaConsulta.fecha_solicitado.tm_mon;
    archivados[j].UltimaConsulta.fecha_solicitado.tm_year = array[i].UltimaConsulta.fecha_solicitado.tm_year;
    archivados[j].UltimaConsulta.fecha_turno.tm_mday = array[i].UltimaConsulta.fecha_turno.tm_mday;
    archivados[j].UltimaConsulta.fecha_turno.tm_mon = array[i].UltimaConsulta.fecha_turno.tm_mon;
    archivados[j].UltimaConsulta.fecha_turno.tm_year = array[i].UltimaConsulta.fecha_turno.tm_year;
    archivados[j].UltimaConsulta.presento = array[i].UltimaConsulta.presento;
    archivados[j].UltimaConsulta.medico.matricula = array[i].UltimaConsulta.medico.matricula;
    archivados[j].UltimaConsulta.medico.nombre = array[i].UltimaConsulta.medico.nombre;
    archivados[j].UltimaConsulta.medico.apellido = array[i].UltimaConsulta.medico.apellido;
    archivados[j].UltimaConsulta.medico.telefono = array[i].UltimaConsulta.medico.telefono;
    archivados[j].UltimaConsulta.medico.especialidad = array[i].UltimaConsulta.medico.especialidad;
    archivados[j].UltimaConsulta.medico.activo = array[i].UltimaConsulta.medico.activo;
    archivados[j].archivado = array[i].archivado;
}
#include "archivar.h"

void notfound(Paciente *&notFound, int q, Paciente *&array, int i){
    notFound[q].DNI = array[i].DNI;
    notFound[q].nombre = array[i].nombre;
    notFound[q].apellido = array[i].apellido;
    notFound[q].sexo = array[i].sexo;
    notFound[q].natalicio = array[i].natalicio;
    notFound[q].estado = array[i].estado;
    notFound[q].id_os = array[i].id_os;
    notFound[q].contacto.telefono = array[i].contacto.telefono;
    notFound[q].contacto.celular = array[i].contacto.celular;
    notFound[q].contacto.direccion = array[i].contacto.direccion;
    notFound[q].contacto.mail = array[i].contacto.mail;
    notFound[q].UltimaConsulta.fecha_solicitado.tm_mday = array[i].UltimaConsulta.fecha_solicitado.tm_mday;
    notFound[q].UltimaConsulta.fecha_solicitado.tm_mon = array[i].UltimaConsulta.fecha_solicitado.tm_mon;
    notFound[q].UltimaConsulta.fecha_solicitado.tm_year = array[i].UltimaConsulta.fecha_solicitado.tm_year;
    notFound[q].UltimaConsulta.fecha_turno.tm_mday = array[i].UltimaConsulta.fecha_turno.tm_mday;
    notFound[q].UltimaConsulta.fecha_turno.tm_mon = array[i].UltimaConsulta.fecha_turno.tm_mon;
    notFound[q].UltimaConsulta.fecha_turno.tm_year = array[i].UltimaConsulta.fecha_turno.tm_year;
    notFound[q].UltimaConsulta.presento = array[i].UltimaConsulta.presento;
    notFound[q].UltimaConsulta.medico.matricula = array[i].UltimaConsulta.medico.matricula;
    notFound[q].UltimaConsulta.medico.nombre = array[i].UltimaConsulta.medico.nombre;
    notFound[q].UltimaConsulta.medico.apellido = array[i].UltimaConsulta.medico.apellido;
    notFound[q].UltimaConsulta.medico.telefono = array[i].UltimaConsulta.medico.telefono;
    notFound[q].UltimaConsulta.medico.especialidad = array[i].UltimaConsulta.medico.especialidad;
    notFound[q].UltimaConsulta.medico.activo = array[i].UltimaConsulta.medico.activo;
    notFound[q].archivado = array[i].archivado;

}
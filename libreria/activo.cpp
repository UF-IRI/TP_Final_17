#include "archivar.h"

void activo(Paciente *&activos, int l, Paciente *&array, int i){
    activos[l].DNI = array[i].DNI;
    activos[l].nombre = array[i].nombre;
    activos[l].apellido = array[i].apellido;
    activos[l].sexo = array[i].sexo;
    activos[l].natalicio = array[i].natalicio;
    activos[l].estado = array[i].estado;
    activos[l].id_os = array[i].id_os;
    activos[l].contacto.telefono = array[i].contacto.telefono;
    activos[l].contacto.celular = array[i].contacto.celular;
    activos[l].contacto.direccion = array[i].contacto.direccion;
    activos[l].contacto.mail = array[i].contacto.mail;
    activos[l].UltimaConsulta.fecha_solicitado = array[i].UltimaConsulta.fecha_solicitado;
    activos[l].UltimaConsulta.fecha_turno = array[i].UltimaConsulta.fecha_turno;
    activos[l].UltimaConsulta.presento = array[i].UltimaConsulta.presento;
    activos[l].UltimaConsulta.medico.matricula = array[i].UltimaConsulta.medico.matricula;
    activos[l].UltimaConsulta.medico.nombre = array[i].UltimaConsulta.medico.nombre;
    activos[l].UltimaConsulta.medico.apellido = array[i].UltimaConsulta.medico.apellido;
    activos[l].UltimaConsulta.medico.telefono = array[i].UltimaConsulta.medico.telefono;
    activos[l].UltimaConsulta.medico.especialidad = array[i].UltimaConsulta.medico.especialidad;
    activos[l].UltimaConsulta.medico.activo = array[i].UltimaConsulta.medico.activo;
    activos[l].archivado = array[i].archivado;

}
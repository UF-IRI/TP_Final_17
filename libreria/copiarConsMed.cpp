#include "copiarConsMed.h"

void copiarConsMed(Consultas*& ArrConsultas, int i, Medico*& ArrMed, int j)
{
	ArrConsultas[i].medico.activo = ArrMed[j].activo;
	ArrConsultas[i].medico.apellido = ArrMed[j].apellido;
	ArrConsultas[i].medico.especialidad = ArrMed[j].especialidad;
	ArrConsultas[i].medico.matricula = ArrMed[j].matricula;
	ArrConsultas[i].medico.nombre = ArrMed[j].nombre;
	ArrConsultas[i].medico.telefono = ArrMed[j].telefono;
	return;
}
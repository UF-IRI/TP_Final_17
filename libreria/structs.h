#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <ctime>
using namespace std;

typedef struct { 
    string id_obs; // el que es un numero
    string obra_social; // el que es palabra
} ObraSocial;

typedef struct{
    string matricula;
    string nombre;
    string apellido;
    string telefono;
    string especialidad;
    bool activo;
} Medico;

typedef struct {
    string DNI;
    time_t fecha_solicitado;
    time_t fecha_turno;
    bool presento;
    Medico medico; //conectado a traves de matricula 
} Consultas;

typedef struct{
    string DNI;
    string telefono;
    string celular;
    string direccion;
    string mail;
} Contacto;

typedef struct {
    string DNI;
    string nombre;
    string apellido;
    string sexo;
    time_t natalicio;
    string estado;
    string id_os;
    Contacto contacto;
    Consultas UltimaConsulta; 
    string archivado;
} Paciente;

#endif
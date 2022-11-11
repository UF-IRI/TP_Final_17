#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <ctime>
using namespace std;

typedef struct {
   int dia;
   int mes;
   int anio;
} Fecha;

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
    Fecha fecha_solicitado;
    time_t fecha_turno;
    bool presento;
    Medico medico; //conectado a traves de matricula 
} Consultas;

typedef struct{
    int DNI;
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
    string natalicio;
    string estado;
    string id_os;  //ver si poner solo el string o toda la estructura esta, ¿¿hace falta leer el numero??, no aporta info
    Contacto contacto;
    Consultas UltimaConsulta; //ver como hacer para incluir todas --> Un array??
    string archivado;
} Paciente;

#endif
#include <iostream>
#include <string>
using namespace std;

struct Fecha {
   int dia;
   int mes;
   int anio;
} typedef Fecha;

struct ObraSocial { 
    string id_od;
    string obra_social;
} typedef ObraSocial;

struct ObraSocial { 
    string id_obs; // el que es un numero
    string obra_social; // el que es palabra
} typedef ObraSocial;

struct Medico {
    string matricula;
    string nombre;
    string apellido;
    string telefono;
    string especialidad;
    bool activo;
} typedef Medico;

struct Consultas {
    string DNI;
    Fecha fecha_solicitado;
    Fecha fecha_turno;
    bool presento;
    string matricula_med;
} typedef Consultas;

struct Contacto{
    int DNI;
    string telefono;
    string celular;
    string direccion;
    string mail;
} typedef Contacto;

struct Paciente {
    string DNI;
    string nombre;
    string apellido;
    string sexo;
    Fecha natalicio;
    string estado;
    ObraSocial id_os;  //ver si poner string o la estructura esta, ¿¿hace falta leer el numero??
} typedef Paciente;



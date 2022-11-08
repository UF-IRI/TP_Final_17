#include "iri.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    fstream cons,cont,med,obs,pac;
   
    cons.open("IRI_Consultas.csv", ios::in);
     if (!(cons.is_open()))
            return -1;

    cont.open("IRI_Contactos.csv", ios::in);
     if (!(cont.is_open()))
            return -1;

    med.open("IRI_Medicos.csv", ios::in);
     if (!(med.is_open()))
            return -1;

    obs.open("IRI_ObraSocial.csv", ios::in);
     if (!(obs.is_open()))
            return -1;

    pac.open("Pacientes.csv", ios::in);
     if (!(pac.is_open()))
            return -1;

    //toda la vaina de leerlos 

    cons.close();
    cont.close();
    med.close();
    obs.close();
    pac.close();

    //seguimos con el codigo
    return EXIT_SUCCESS;
}
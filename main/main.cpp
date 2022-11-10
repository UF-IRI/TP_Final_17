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

   
    int N = 20;
    int i = 0;

     Paciente *array = new Paciente[N]; //tener en cuenta que hay que hacer resize
    
    string dummy;
    char coma;
    pac << dummy << coma << dummy << coma << dummy << coma << dummy << coma << dummy << coma
    << dummy << coma << dummy; //leo el header de Pacientes.csv

    while(pac){
        pac << *array[i].DNI << coma << *array[i].nombre << coma << *array[i].apellido << coma 
        << *array[i].sexo << coma << *array[i].natalicio << coma << *array[i].estado << coma << *array[i].id_os.obra_social;
        i++;
    }  //lee todo el archivo de paciente y lo guarda en el array dinamico


    string aux, aux2, aux3, aux4;
    obs << dummy << coma << dummy; //leo el header de IRI_ObraSocial.csv
    
    while(obs){
        obs << dummy << coma << aux; 
        if(*array[i].id_os.obra_social == dummy) //si son la misma obra social
        {
                *array[i].id_os.id_obs=aux;
        }
        i++;
    } //lee todo el archivo de obra social y lo guarda en el array dinamico
    

    cont << dummy << coma << dummy << coma << dummy << coma << dummy << coma << dummy; //leo el header de IRI_Contactos.csv

    while(cont){
        cont << dummy << coma << aux << aux2 << coma << aux3 << coma << aux4; 
        if(*array[i].DNI == dummy) //si son la misma obra social
        {
                *array[i].contacto.telefono = aux;
                *array[i].contacto.celular = aux2;
                *array[i].contacto.direccion = aux3;
                *array[i].contacto.mail = aux4;
        }
        i++;
    } //lee todo el archivo de contactos y lo guarda en el array dinamico
    
   //falta medico y ultima consulta, hay que ver lo de las fechas como leerlas y ver si es necesario leer 
   //todas las consultas (hacemos array) o solo la ultima (convertimos todo a numero y buscamos el maximo)

    cons.close();
    cont.close();
    med.close();
    obs.close();
    pac.close();

    //seguimos con el codigo
    return EXIT_SUCCESS;
}
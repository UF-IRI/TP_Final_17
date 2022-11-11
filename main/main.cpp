#include "iri.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "resize.h"
#include "contactar.h"
using namespace std;

//FALTA: 
        //Funcion update --> solo obra social
        //Funcion Archivar!! --> agregar etiqueta
        //Terminar de leer los archivos de obra social, consultas y medicos
        //Excepciones (no hay contacto, etc.)!
        //Que anden las structs :/ (esto saca todos los errores que aparecen)
        //Mover a las listas nuevas; Archivo, Vuelve/Activo, Contactar devuelta, Faltan datos, con mem dinamica!!, son archivos CSV
        //Algoritmo BUSQUEDA
        //Unit-Test
        //Borrar todas las mem dinamicas!!! N, j, k, l, array, 

//Variables mem estatica: i, aux, aux2, aux3, aux4, dummy, coma, 

int main() {
    fstream cons,cont,med,pac;
   
    cons.open(BASE_PATH+"IRI_Consultas.csv", ios::in);
     if (!(cons.is_open()))
            return -1;

    cont.open(BASE_PATH+"IRI_Contactos.csv", ios::in);
     if (!(cont.is_open()))
            return -1;

    med.open(BASE_PATH+"IRI_Medicos.csv", ios::in);
     if (!(med.is_open()))
            return -1;

    pac.open(BASE_PATH+"Pacientes.csv", ios::in);
     if (!(pac.is_open()))
            return -1;

   
    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;
    
    Paciente *array = new Paciente[N]; //tener en cuenta que hay que hacer resize
    
    string dummy;
    char coma;
    pac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma
    >> dummy >> coma >> dummy; //leo el header de Pacientes.csv

    while(pac){
        if(i==N-1){
                resize(array, &N, cantidad_aumentar); 
        }
        
        pac >> array[i].DNI >> coma >> array[i].nombre >> coma >> array[i].apellido >> coma 
        >> array[i].sexo >> coma >> array[i].natalicio >> coma >> array[i].estado >> coma >> array[i].id_os;
        i++;
    }  //lee todo el archivo de paciente y lo guarda en el array dinamico
    
    Contacto *ArrContacto = new Contacto[N];
    string aux, aux2, aux3, aux4;

    cont >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Contactos.csv

    while(cont){
        cont >> ArrContacto[i].DNI >> coma >> ArrContacto[i].telefono >> coma >> ArrContacto[i].celular >> coma >> ArrContacto[i].direccion >> coma >> ArrContacto[i].mail;
        i++;
        }
        //lee todo el archivo de contactos y lo guarda en el array dinamico
    
   //falta medico y ultima consulta, hay que ver lo de las fechas como leerlas y ver si es necesario leer 
   //todas las consultas (hacemos array) o solo la ultima (convertimos todo a numero y buscamos el maximo)

    cons.close();
    cont.close();
    med.close();
    pac.close();

    for(i=0; i<N; i++){
       
       //hacer el calculo de los 10 años

        if(array[i].estado == "fallecido"){//|| //dif tiempo > 10
        
               i=3; //archivar (el i=3 esta de decoracion para que no aparezca un error)
        }

        else if(array[i].estado == "internado"){ // || tiene turno a futuro
        
            i=3;    //mover a activo y retornar (idem)
        }

        else{ //los que tenemos que contactar
                int j; //para las listas nuevas
                int k;
                int l;

                int answer = Contactar();
                switch(answer){
                        case 1:  //muerto
                                //update, movemos al archivo
                                break;

                        case 2: //no quiere volver
                                //update, movemos al archivo
                                break;
                        
                        case 3: //quiere volver
                                //update, movemos al activo
                                break;
                        
                        case 4: //not found
                                //movemos a no encontrados
                                break;

                        default:
                                cout<<"ERROR"<<endl;
                                break;
                }
        }
    } //busqueda

    //cerrar y borrar todo!

    return EXIT_SUCCESS;
}
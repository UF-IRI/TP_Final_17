#include <string>
#include <fstream>
#include <ctime>
#include "resize.h"
#include "contactar.h"
#include "iri.cpp"

using namespace std;

//FALTA: 
        //Funcion update --> solo obra social
        //Funcion Archivar!! --> agregar etiqueta
        //Terminar de leer los archivos de consultas y medicos y armar la lista gral!
        //Excepciones (no hay contacto, etc.)!
        //Borrar variablem mem dinamica: array, ArrContacto, ArrConsultas, 

//Variables mem estatica: i, aux, aux2, aux3, aux4, dummy, coma, 

int main() {
    fstream cons,cont,med,pac;

    cons.open(BASE_PATH+"\\data_files\\input\\IRI_Consultas.csv", ios::in);
     if (!(cons.is_open()))
            return -1;

    cont.open(BASE_PATH+"\\data_files\\input\\IRI_Contactos.csv", ios::in);
     if (!(cont.is_open()))
            return -1;

    med.open(BASE_PATH+"\\data_files\\input\\IRI_Medicos.csv", ios::in);
     if (!(med.is_open()))
            return -1;

    pac.open(BASE_PATH+"\\data_files\\input\\Pacientes.csv", ios::in);
     if (!(pac.is_open()))
            return -1;

    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;
    string dummy;
    string coma;
    

    Paciente *array = new Paciente[N];
    pac >> dummy >> coma >> dummy; //leo el header de Pacientes.csv

    while(pac){
        if(i==N-1)
                resize(array, N, cantidad_aumentar); 
        pac >> array[i].DNI >> coma >> array[i].nombre >> coma >> array[i].apellido >> coma 
        >> array[i].sexo >> coma >> array[i].natalicio >> coma >> array[i].estado >> coma >> array[i].id_os;
    }

    Contacto *ArrContacto = new Contacto[N];
    cont >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Contactos.csv

    i=0;
    while(cont){
        if(i==N-1)
                resizeCont(ArrContacto, N, cantidad_aumentar); 
        cont >> ArrContacto[i].DNI >> coma >> ArrContacto[i].telefono >> coma >> ArrContacto[i].celular >> coma >> ArrContacto[i].direccion >> coma >> ArrContacto[i].mail;
        i++;
    }

    Consultas *ArrConsultas = new Consultas[N];
    cons >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Consultas.csv

    i=0;
    while(cons){
         if(i==N-1)
                resizeCons(ArrConsultas, N, cantidad_aumentar); 
        cons >> ArrConsultas[i].DNI >> coma >> ArrConsultas[i].fecha_solicitado >> coma >> ArrConsultas[i].fecha_turno >> coma >> ArrConsultas[i].presento >> coma >> ArrConsultas[i].medico.matricula;
        i++;
    }
    
    Medico *ArrMed = new Medico[N];
    med >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Medicos.csv

    i=0;
    while(med){//falta resize
        if(i==N-1)
                resizeMed(ArrMed, N, cantidad_aumentar); 
        med >> ArrMed[i].matricula >> coma >> ArrMed[i].nombre >> coma >> ArrMed[i].apellido >> coma >> ArrMed[i].telefono >> coma >> ArrMed[i].especialidad >> coma >>  ArrMed[i].activo;
        i++;
    }

    cons.close();
    cont.close();
    med.close();
    pac.close();


    
    //armamos el array con todos los datos






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
                        case 1: //muerto
                        break;

                        case 2: //not back
                        break;

                        case 3: //quiere volver
                                //update, movemos al activo
                        break;

                        case 4: //not found
                        break;

                        default:
                        break;
                }
        }
    }




        
}

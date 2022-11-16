#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <regex>
#include "iri.cpp"
#include "resize.h"
#include "contactar.h"
#include "copiarPacCont.h"
#include "copiarPacCons.h"
#include "copiarConsMed.h"
#include "archivar.h"

using namespace std;

//FALTA: 
        //Funcion update --> solo obra social
        //Excepciones (no hay contacto, etc.)!
        //UNIT-TEST de: las funciones archivar.h, funciones copiar, contactar
        //PODER ABRIR LOS ARCHIVOS
        //Borrar variablem mem dinamica: array, archivados, activos, notFound

//Variables mem estatica: i, N, dummy, coma, j, k , l, m, p, q, cantidad_aumentar, 

int main() {

    fstream cons,cont,med,pac;
    
    cons.open(BASE_PATH+"data_files\\input\\IRI_Consultas.csv", ios::in);
     if (!(cons.is_open())){
      cout<<"no me pude abrir"<<endl;
            return -1;
     }

    cout<<"hola";
     
    cont.open(BASE_PATH+"data_files/input/IRI_Contactos.csv", ios::in);
     if (!(cont.is_open()))
            return -1;

    med.open(BASE_PATH+"TP_FINAL_17/data_files/input/IRI_Medicos.csv", ios::in);
     if (!(med.is_open()))
            return -1;

    pac.open(BASE_PATH+"TP_FINAL_17/data_files/input/IRI_Pacientes.csv", ios::in);
     if (!(pac.is_open()))
            return -1;


    
    string dummy;
    string coma;
    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;

    Paciente *array = new Paciente[N];
    pac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de Pacientes.csv

    while(pac){
        if(i==N-1){
                resize(array, N, cantidad_aumentar); 
        }
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
    int k;
    k=N;
    int j=0;

    for (i = 0; i < N; i++) { //recorre Consulta
        for (j = 0; j < k; j++) { //recorre medicos
            if (ArrConsultas[i].medico.matricula == ArrMed[j].matricula) 
            {
                copiarConsMed(ArrConsultas, i, ArrMed, j);
            }
        }
    }


    for (i=0 ;i<N ;i++){ //recorre pacientes
        for(j=0; j<k ;j++){ //recorre las otras listas
               
                if(array[i].DNI == ArrConsultas[j].DNI){
                    copiarPacCons(array, i, ArrConsultas, j);    
                }
                
                if(array[i].DNI == ArrContacto[j].DNI){
                    copiarPacCont(array,i, ArrContacto,j);  
                }

        }
    }

    //borramos mem dinamica que ya no usamos
    delete[] ArrContacto;
    ArrContacto = NULL;

    delete[] ArrContacto;
    ArrContacto = NULL;

    delete[] ArrMed;
    ArrMed = NULL;


    //Leemos toda la lista y ponemos etiquetas de archivado, activo o contactar
    TengoQueArchivar(array, i, N);
    
    k=20; //archivo
    j=0; //archivo

    int m = 20; //activo
    int l=0; //activo

    int p = 20; //not found
    int q=0; //not found

    Paciente *archivados = new Paciente[k];
    Paciente *activos = new Paciente[m];
    Paciente *notFound = new Paciente[p];

    for(i=0; i<N; i++){
        if(array[i].archivado == "ARCHIVADO" ){
            if(i==k-1)
                resize(archivados, k, cantidad_aumentar); 
            archivar(archivados, j, array, i);
            j++; 
        }
        

        else if(array[i].estado == "ACTIVO"){ 
            if(i==m-1)
                resize(activos, m, cantidad_aumentar); 
            activo(activos, l, array, i);
            l++; 
        }

        else{ //los que tenemos que contactar
                int answer = Contactar();
                
                switch(answer){
                        case 1: //muerto
                            if(i==k-1)
                                resize(archivados, k, cantidad_aumentar); 
                            archivar(archivados, j, array, i);
                            j++; 
                            break;

                        case 2: //not back
                            if(i==k-1)
                                resize(archivados, k, cantidad_aumentar); 
                            archivar(archivados, j, array, i);
                            j++; 
                            break;

                        case 3: //quiere volver
                            if(i==m-1)
                                resize(activos, m, cantidad_aumentar); 
                            activo(activos, l, array, i);
                            l++; 
                            break;

                        case 4: //not found
                            if(i==p-1)
                                resize(notFound, p, cantidad_aumentar); 
                            notfound(notFound, q, array, i);
                            q++;
                            break;

                        default:
                            cout<<"ERROR"<<endl;
                            break;
                }
        }
    }

    //borramos mem dinamica que ya no usamos
    delete[] array;
    array = NULL;


    //imprimir los archivos y borrar mems dinamica!

    fstream arch,act,nf; //archivados, activos, not found
    coma = ",";

    arch.open(BASE_PATH+"data_files/output/IRI_Archivados.csv", ios::out);
     if (!(arch.is_open()))
            return -1;
    
    // imprimir el header
    //hacer un for que imprima toda la lista

    arch.close();


    act.open(BASE_PATH+"data_files/output/IRI_Activos.csv", ios::out);
     if (!(act.is_open()))
            return -1;
    
    // imprimir el header
    //hacer un for que imprima toda la lista

    act.close();


    nf.open(BASE_PATH+"data_files/output/IRI_NotFound.csv", ios::out);
     if (!(nf.is_open()))
            return -1;
    
    // imprimir el header
    //hacer un for que imprima toda la lista

    nf.close();

        
}


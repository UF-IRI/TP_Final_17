#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "resize.h"
#include "contactar.h"
#include "copiarPacCont.h"
#include "copiarPacCons.h"
#include "copiarConsMed.h"
#include "iri.cpp"
#include "archivar.h"
#include "randomObS.h"

using namespace std;


int main() {

    fstream cons,cont,med,pac;
    
    cons.open("Consultas.csv", ios::in);
     if (!(cons.is_open())){
      cout<<"no me pude abrir"<<endl;
            return -1;
     }
     
    cont.open("Contactos.csv", ios::in);
     if (!(cont.is_open()))
            return -1;


    med.open("Medicos.csv", ios::in);
     if (!(med.is_open()))
            return -1;


    pac.open("Pacientes.csv", ios::in);
     if (!(pac.is_open()))
            return -1;
 

    string dummy;
    string coma;
    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;

    Paciente *array = new Paciente[N];
    if(array==nullptr)
        return -1;

    pac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de Pacientes.csv

    while(pac){
        if(i==N-1){
                resize(array, N, cantidad_aumentar); 
        }
        pac >> array[i].DNI >> coma >> array[i].nombre >> coma >> array[i].apellido >> coma 
        >> array[i].sexo >> coma >> array[i].natalicio >> coma >> array[i].estado >> coma >> array[i].id_os;
    }


    Contacto *ArrContacto = new Contacto[N];
    if(ArrContacto==nullptr)
        return -1;
    cont >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Contactos.csv

    i=0;
    while(cont){
        if(i==N-1)
                resizeCont(ArrContacto, N, cantidad_aumentar); 
        cont >> ArrContacto[i].DNI >> coma >> ArrContacto[i].telefono >> coma >> ArrContacto[i].celular >> coma >> ArrContacto[i].direccion >> coma >> ArrContacto[i].mail;
        i++;
    }

    Consultas *ArrConsultas = new Consultas[N];
    if(ArrConsultas==nullptr)
        return -1;

    cons >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Consultas.csv

    i=0;
    while(cons){
         if(i==N-1)
                resizeCons(ArrConsultas, N, cantidad_aumentar); 
        cons >> ArrConsultas[i].DNI >> coma >> ArrConsultas[i].fecha_solicitado.tm_mday >> coma >> ArrConsultas[i].fecha_solicitado.tm_mon >> coma >> ArrConsultas[i].fecha_solicitado.tm_year >> coma >> ArrConsultas[i].fecha_turno.tm_mday >> coma >> ArrConsultas[i].fecha_turno.tm_mon >> coma >> ArrConsultas[i].fecha_turno.tm_year >> coma >> ArrConsultas[i].presento >> coma >> ArrConsultas[i].medico.matricula;
        i++;
    }
    
    Medico *ArrMed = new Medico[N];
    if(ArrMed==nullptr)
        return -1;
    med >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Medicos.csv

    i=0;
    while(med){
        if(i==N-1)
                resizeMed(ArrMed, N, cantidad_aumentar); 
        med >> ArrMed[i].matricula >> coma >> ArrMed[i].nombre >> coma >> ArrMed[i].apellido >> coma >> ArrMed[i].telefono >> coma >> ArrMed[i].especialidad >> coma >> ArrMed[i].activo;
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

    bool ConsMed[N]; //flag que indica que se cargo el dato
    for (i = 0; i < N; i++) {
        ConsMed[i]=false;
    }

    for (i = 0; i < N; i++) { //recorre Consulta
        for (j = 0; j < k; j++) { //recorre medicos
            if (ArrConsultas[i].medico.matricula == ArrMed[j].matricula) 
            {
                copiarConsMed(ArrConsultas, i, ArrMed, j);
                ConsMed[i]=true;
            }
        }
    }

    
    bool PacCons[N]; //flag que indica que se cargo el dato
    for (i = 0; i < N; i++) {
        PacCons[i]=false;
    }

    bool PacCont[N]; //flag que indica que se cargo el dato
    for (i = 0; i < N; i++) {
        PacCont[i]=false;
    }

    double max = 0;

    for (i=0 ;i<N ;i++){ //recorre pacientes
        for(j=0; j<k ;j++){ //recorre las otras listas
               
                if(array[i].DNI == ArrConsultas[j].DNI){
                    copiarPacCons(array, i, ArrConsultas, j, max);
                    PacCons[i]=true;   
                }
                
               if(array[i].DNI == ArrContacto[j].DNI){
                    copiarPacCont(array,i, ArrContacto,j); 
                    PacCont[i]=true; 
                }
        }
    }

    //borramos mem dinamica que ya no usamos
    delete[] ArrContacto;
    ArrContacto = NULL;

    delete[] ArrConsultas;
    ArrConsultas = NULL;

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
    if(archivados==nullptr)
        return -1;

    Paciente *activos = new Paciente[m];
    if(activos==nullptr)
        return -1;

    Paciente *notFound = new Paciente[p];
    if(notFound==nullptr)
        return -1;

    string aux_os;
    for(i=0; i<N; i++){
        if(array[i].archivado == "ARCHIVADO" && PacCons[i] == true && PacCont[i] == true && ConsMed[i] == true){
            if(i==k-1)
                resize(archivados, k, cantidad_aumentar); 
            archivar(archivados, j, array, i);
            j++; 
        }

        else if(array[i].estado == "ACTIVO" && PacCons[i] == true && PacCont[i] == true && ConsMed[i] == true){ 
            if(i==m-1)
                resize(activos, m, cantidad_aumentar); 
        
            bool respuesta = randomObS();
            if (respuesta == true){
                cout<<"ingrese su nueva obra social: ";
                cin>>aux_os;
                array[i].id_os = aux_os;
            }

            activo(activos, l, array, i);
            l++; 

        }

        else if (array[i].estado == "CONTACTAR" && PacCons[i] == true && PacCont[i] == true && ConsMed[i] == true){ //los que tenemos que contactar
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


    //imprimir los archivos

    fstream arch,act,nf; //archivados, activos, not found
    coma = ",";

    arch.open(BASE_PATH+"data_files/output/IRI_Archivados.csv", ios::app);
     if (!(arch.is_open()))
            return -1;
    
    arch << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado" << coma << "Obra_Social";
   
   j=0;
    while(j<k){
         arch << archivados[j].DNI << coma << archivados[j].nombre << coma << archivados[j].apellido << coma << archivados[j].sexo << coma << archivados[j].natalicio << coma << archivados[j].estado << coma << archivados[j].id_os << endl;
        j++;    
    }

    arch.close();
    delete[] archivados;
    archivados = NULL;


    act.open(BASE_PATH+"data_files/output/IRI_Activos.csv", ios::app);
     if (!(act.is_open()))
            return -1;
    
    arch << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado" << coma << "Obra_Social";
    l=0;
    while(l<m){
       act << activos[l].DNI << coma << activos[l].nombre << coma << activos[l].apellido << coma << activos[l].sexo << coma << activos[l].natalicio << coma << activos[l].estado << coma << activos[l].id_os << endl;
       l++;  
    }

    act.close();
    delete[] activos;
    activos = NULL;

    nf.open(BASE_PATH+"data_files/output/IRI_NotFound.csv", ios::app);
     if (!(nf.is_open()))
            return -1;
    
    arch << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado" << coma << "Obra_Social";
    q=0;
    while(q<p){
       nf << notFound[q].DNI << coma << notFound[q].nombre << coma << notFound[q].apellido << coma << notFound[q].sexo << coma << notFound[q].natalicio << coma << notFound[q].estado << coma << notFound[q].id_os << endl;
       q++;  
    }

    nf.close();
    delete[] notFound;
    notFound = NULL;

}


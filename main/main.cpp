#include "iri.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

//FALTA: 
        //Funcion update --> preguntar como
        //Funcion Archivar!!
        //Terminar de leer los archivos de obra social, consultas y medicos
        //Excepciones (no hay contacto, etc.)!
        //Que anden las structs :/ (esto saca todos los errores que aparecen)
        //Mover a las listas nuevas; Archivo, Vuelve/Activo, Contactar devuelta, Faltan datos, con mem dinamica!!, son archivos CSV
        //Algoritmo BUSQUEDA
        //Unit-Test
        //Borrar todas las mem dinamicas!!! N, j, k, l, array, 

//Variables mem estatica: i, aux, aux2, aux3, aux4, dummy, coma, 

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

   
    int *N = new int;
    *N=20;
    int i = 0;
    int cantidad_aumentar = 5;
    
    Paciente *array = new Paciente[N]; //tener en cuenta que hay que hacer resize
    
    string dummy;
    char coma;
    pac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma
    >> dummy >> coma >> dummy; //leo el header de Pacientes.csv

    while(pac){
        if(i==*N-1){
                resize(Paciente *&array, *N, cantidad_aumentar); 
        }
        
        pac >> *array[i].DNI >> coma >> *array[i].nombre >> coma >> *array[i].apellido >> coma 
        >> *array[i].sexo >> coma >> *array[i].natalicio >> coma >> *array[i].estado >> coma >> *array[i].id_os.obra_social;
        i++;
    }  //lee todo el archivo de paciente y lo guarda en el array dinamico


    string aux, aux2, aux3, aux4;
    obs >> dummy >> coma >> dummy; //leo el header de IRI_ObraSocial.csv
    
    while(obs){
        obs >> dummy >> coma >> aux; 
        if(*array[i].id_os.id_obs == dummy) //si son la misma obra social (adaptado a que en la lista de pac tiene el numero, no el string)
        {
                *array[i].id_os.obra_social=aux;
        }
        i++;
    } //lee todo el archivo de obra social y lo guarda en el array dinamico
    

    cont >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; //leo el header de IRI_Contactos.csv

    while(cont){
        cont >> dummy >> coma >> aux >> aux2 >> coma >> aux3 >> coma >> aux4; 
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

    for(i=0; i<*N; i++){
       
       //hacer el calculo de los 10 años

        if(*array[i].estado == "fallecido"){//|| //dif tiempo > 10
        
               i=3; //archivar (el i=3 esta de decoracion para que no aparezca un error)
        }

        else if(*array[i].estado == "internado"){ // || tiene turno a futuro
        
            i=3;    //mover a activo y retornar (idem)
        }

        else{ //los que tenemos que contactar
                int *j = new int; //para las listas nuevas
                int *k = new int;
                int *l = new int;

                bool respuesta = false;
                string aux_os;

                int answer = Contactar();
                switch(answer){
                        case 1:  //muerto
                                //update, movemos al archivo
                                break;

                        case 2: //no quiere volver
                                //update, movemos al archivo
                                break;
                        
                        case 3:         
                                cout<<"necesita hacer un cambio en los datos de su obra social?: ";
                                cin>>respuesta;
                                if (respuesta == true)
                                {
                                cout<<"ingrese su nueva obra social: ";
                                cin>>aux_os;
                                Paciente.id_os[i] = aux_os;
                                }
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
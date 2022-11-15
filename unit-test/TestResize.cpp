#include "gmock/gmock.h"
#include "resize.h"

namespace Casos_Base {
	TEST(Casos_Base, ResizePacientes) {
		//declaro 2 arrays el de aca y el que testeo 
     
		Paciente array[3];

        array[0].DNI = "878091772";
        array[0].nombre = "Dagmar";
        array[0].apellido = "Benedict";
        array[0].sexo = "F";
        array[0].natalicio = 1/2/1959;
        array[0].estado = "fallecido";
        array[0].id_os = "Italiano";

        array[1].DNI = "873726724";
        array[1].nombre = "Freeman";
        array[1].apellido = "Willbond";
        array[1].sexo = "M";
        array[1].natalicio = 9/22/2010;
        array[1].estado = "internado";
        array[1].id_os = "Espanyol";

        array[2].DNI = "269125060";
        array[2].nombre = "Laurene";
        array[2].apellido = "Rumsey";
        array[2].sexo = "F";
        array[2].natalicio = 2/27/1951;
        array[2].estado = "n/c";
        array[2].id_os = "OSDE";

        int N = 0;
        Paciente* test= new Paciente[N];
        
        resize(test, N, 2);
        
        test[0].DNI = "878091772";
        test[0].nombre = "Dagmar";
        test[0].apellido = "Benedict";
        test[0].sexo = "F";
        test[0].natalicio = 1/2/1959;
        test[0].estado = "fallecido";
        test[0].id_os = "Italiano";

        test[1].DNI = "873726724";
        test[1].nombre = "Freeman";
        test[1].apellido = "Willbond";
        test[1].sexo = "M";
        test[1].natalicio = 9/22/2010;
        test[1].estado = "internado";
        test[1].id_os = "Espanyol";

        test[2].DNI = "269125060";
        test[2].nombre = "Laurene";
        test[2].apellido = "Rumsey";
        test[2].sexo = "F";
        test[2].natalicio = 2/27/1951;
        test[2].estado = "n/c";
        test[2].id_os = "OSDE";   

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].nombre, test[i].nombre);    
            EXPECT_EQ(array[i].apellido, test[i].apellido);    
            EXPECT_EQ(array[i].sexo, test[i].sexo);    
            EXPECT_EQ(array[i].natalicio, test[i].natalicio);    
            EXPECT_EQ(array[i].estado, test[i].estado);    
            EXPECT_EQ(array[i].id_os, test[i].id_os);    
        }
		
	}

	TEST(Casos_Base, ResizeContactos) {
     
		Contacto array[3];

        array[0].DNI = "967597385";
        array[0].telefono = "+41 203 339 0504";
        array[0].celular = "+57 722 907 7201";
        array[0].direccion = "Pine View";
        array[0].mail = "strillow0@is.gd";

        array[1].DNI = "398310454";
        array[1].telefono = "+86 913 129 4605";
        array[1].celular = "+62 268 398 6125";
        array[1].direccion = "Lakewood Gardens";
        array[1].mail = "hsubhan1@marketwatch.com";

        array[2].DNI = "747423510";
        array[2].telefono = "+1 696 710 1121";
        array[2].celular = "+1 619 549 4324";
        array[2].direccion = "Thackeray";
        array[2].mail = "mbeaty2@ucoz.ru";

        int N = 0;
        Contacto* test= new Contacto[N];
        
        resizeCont(test, N, 2);
       
        test[0].DNI = "967597385";
        test[0].telefono = "+41 203 339 0504";
        test[0].celular = "+57 722 907 7201";
        test[0].direccion = "Pine View";
        test[0].mail = "strillow0@is.gd";

        test[1].DNI = "398310454";
        test[1].telefono = "+86 913 129 4605";
        test[1].celular = "+62 268 398 6125";
        test[1].direccion = "Lakewood Gardens";
        test[1].mail = "hsubhan1@marketwatch.com";

        test[2].DNI = "747423510";
        test[2].telefono = "+1 696 710 1121";
        test[2].celular = "+1 619 549 4324";
        test[2].direccion = "Thackeray";
        test[2].mail = "mbeaty2@ucoz.ru";

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].DNI, test[i].DNI);    
            EXPECT_EQ(array[i].telefono, test[i].telefono);    
            EXPECT_EQ(array[i].celular, test[i].celular);    
            EXPECT_EQ(array[i].direccion, test[i].direccion);    
            EXPECT_EQ(array[i].mail, test[i].mail);        
        }

	}

	TEST(Casos_Base, ResizeConsultas) {
       
        Consultas array[3];

        array[0].DNI = "432584544";
        array[0].fecha_solicitado = 01/11/2001;
        array[0].fecha_turno = 19/12/2001;
        array[0].presento = true;
        array[0].medico.matricula = "00-334-0838";

        array[1].DNI = "867584849";
        array[1].fecha_solicitado = 26/01/2009;
        array[1].fecha_turno = 20/02/2009;
        array[1].presento = true;
        array[1].medico.matricula = "23-279-3287";
       
        array[2].DNI = "692767686";
        array[2].fecha_solicitado = 16/06/1993;
        array[2].fecha_turno = 14/07/1993;
        array[2].presento = false;
        array[2].medico.matricula = "12-340-2259";

        int N = 0;
        Consultas* test= new Consultas[N];
        
        resizeCons(test, N, 2);

        test[0].DNI = "432584544";
        test[0].fecha_solicitado = 01/11/2001;
        test[0].fecha_turno = 19/12/2001;
        test[0].presento = true;
        test[0].medico.matricula = "00-334-0838";

        test[1].DNI = "867584849";
        test[1].fecha_solicitado = 26/01/2009;
        test[1].fecha_turno = 20/02/2009;
        test[1].presento = true;
        test[1].medico.matricula = "23-279-3287";
       
        test[2].DNI = "692767686";
        test[2].fecha_solicitado = 16/06/1993;
        test[2].fecha_turno = 14/07/1993;
        test[2].presento = false;
        test[2].medico.matricula = "12-340-2259";

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].DNI, test[i].DNI);    
            EXPECT_EQ(array[i].fecha_solicitado, test[i].fecha_solicitado);    
            EXPECT_EQ(array[i].fecha_turno, test[i].fecha_turno);    
            EXPECT_EQ(array[i].presento, test[i].presento);    
            EXPECT_EQ(array[i].medico.matricula, test[i].medico.matricula);        
        }

	
	}

    TEST(Casos_Base, ResizeMedicos) {
       
        Medico array[3];

        array[0].matricula = "04-723-0907";
        array[0].nombre = "Araldo";
        array[0].apellido = "Grafom";
        array[0].telefono = "827-190-3137";
        array[0].especialidad = "farmacologia";
        array[0].activo = true;

        array[1].matricula = "50-314-2346";
        array[1].nombre = "Trevar";
        array[1].apellido = "Cess";
        array[1].telefono = "600-230-3473";
        array[1].especialidad = "oncologia";
        array[1].activo = true;
        
        array[2].matricula = "61-294-6573";
        array[2].nombre = "Patin";
        array[2].apellido = "Itzchaky";
        array[2].telefono = "113-697-7977";
        array[2].especialidad = "reumatologia";
        array[2].activo = false;


        int N = 0;
        Medico *test= new Medico[N];
        
        resizeMed(test, N, 2);

        test[0].matricula = "04-723-0907";
        test[0].nombre = "Araldo";
        test[0].apellido = "Grafom";
        test[0].telefono = "827-190-3137";
        test[0].especialidad = "farmacologia";
        test[0].activo = true;

        test[1].matricula = "50-314-2346";
        test[1].nombre = "Trevar";
        test[1].apellido = "Cess";
        test[1].telefono = "600-230-3473";
        test[1].especialidad = "oncologia";
        test[1].activo = true;
        
        test[2].matricula = "61-294-6573";
        test[2].nombre = "Patin";
        test[2].apellido = "Itzchaky";
        test[2].telefono = "113-697-7977";
        test[2].especialidad = "reumatologia";
        test[2].activo = false;

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].matricula, test[i].matricula);    
            EXPECT_EQ(array[i].nombre, test[i].nombre);    
            EXPECT_EQ(array[i].apellido, test[i].apellido); 
            EXPECT_EQ(array[i].telefono, test[i].telefono);    
            EXPECT_EQ(array[i].especialidad, test[i].especialidad);    
            EXPECT_EQ(array[i].activo, test[i].activo);        
        }
	
	}
}


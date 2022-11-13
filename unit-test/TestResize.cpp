#include "gmock/gmock.h"
#include "resize.h"

namespace Casos_Base {
	TEST(Casos_Base, FuncionResize) {
		//declaro 2 arrays el de aca y el que testeo 
     
		Paciente array[3];

        array[0].DNI = "878091772";
        array[0].nombre = "Dagmar";
        array[0].apellido = "Benedict";
        array[0].sexo = "F";
        array[0].natalicio = "1/2/1959";
        array[0].estado = "fallecido";
        array[0].id_os = "Italiano";

        array[1].DNI = "873726724";
        array[1].nombre = "Freeman";
        array[1].apellido = "Willbond";
        array[1].sexo = "M";
        array[1].natalicio = "9/22/2010";
        array[1].estado = "internado";
        array[1].id_os = "Espanyol";

        array[2].DNI = "269125060";
        array[2].nombre = "Laurene";
        array[2].apellido = "Rumsey";
        array[2].sexo = "F";
        array[2].natalicio = "2/27/1951";
        array[2].estado = "n/c";
        array[2].id_os = "OSDE";

        int N = 0;
        Paciente* test= new Paciente[N];
        
        resize(test, N, 2);
        
        test[0].DNI = "878091772";
        test[0].nombre = "Dagmar";
        test[0].apellido = "Benedict";
        test[0].sexo = "F";
        test[0].natalicio = "1/2/1959";
        test[0].estado = "fallecido";
        test[0].id_os = "Italiano";

        test[1].DNI = "873726724";
        test[1].nombre = "Freeman";
        test[1].apellido = "Willbond";
        test[1].sexo = "M";
        test[1].natalicio = "9/22/2010";
        test[1].estado = "internado";
        test[1].id_os = "Espanyol";

        test[2].DNI = "269125060";
        test[2].nombre = "Laurene";
        test[2].apellido = "Rumsey";
        test[2].sexo = "F";
        test[2].natalicio = "2/27/1951";
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

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
}
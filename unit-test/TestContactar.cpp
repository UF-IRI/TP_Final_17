#include "gmock/gmock.h"
#include "contactar.h"

namespace foobar {
	TEST(TestContactar, expected) {
        
        int aux = Contactar();
        EXPECT_LE(aux ,4);
        EXPECT_GE(aux,1);

	}


    TEST(TestContactar, borde) {
        
        int aux = Contactar();
        EXPECT_NE(aux,5);
        EXPECT_NE(aux,0);
        EXPECT_NE(aux,6);
        EXPECT_NE(aux,00);

	}
   
}
//es un random que devuelve un numero entre 1 y 4


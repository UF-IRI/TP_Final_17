#include "gmock/gmock.h"
#include "randomObS.h"

namespace foobar {
	TEST(TestObS, expected) {
        int aux = randomObS();
        EXPECT_LE(aux,1);
        EXPECT_GE(aux,0);
        
	}


    TEST(TestObS, borde) {
        
        int aux = randomObS();
        EXPECT_NE(aux,2);
        EXPECT_NE(aux,-1);
        EXPECT_NE(aux,3);

	}
   
}
//es un random que devuelve un numero entre 1 y 4
#include<iostream>
#include<string>
#include "emp.h"
#include "gtest/gtest.h"

using namespace std;

extern int fac(int);

TEST( FactTest ,  Positive ) {
	ASSERT_EQ( 720 , fac(6) ) << "The value of factorial" ;
}

class emptest : public ::testing::Test {
    protected:
        emp *e = nullptr;

        virtual void SetUp() {      
            e = new emp( "Agrawal", "Rajesh", 52 );
        }

        virtual void TearDown() { delete e; }
};

TEST_F( emptest, default ) {
    ASSERT_EQ( "Rajesh", e->getFirstName() );
    ASSERT_EQ( "Agrawal", e->getLastName() );
    ASSERT_EQ( 52, e->getAge() );
}


int main(int argc, char* argv[] ) {
	testing::InitGoogleTest(&argc, argv );
	return RUN_ALL_TESTS();
	//std::cout << "The factorial of 6 " << fac(6) << std::endl;
}



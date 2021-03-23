#include "bq.h"
#include "gtest/gtest.h"

class bqTest : public ::testing::Test {
    protected:
        void SetUp() override {
            std::shared_ptr<std::string> sptr ( new std::string( "Raj" ) );
            _bq1.push( 5 );
        }

        void TearDown() override {}

    BoundedQ<int, 10> _bq1;
    BoundedQ<int, 10> _bq2;

};

TEST_F( bqTest,  size ) {
    EXPECT_EQ( 1, _bq1.size() );
}

int myInt( int );

TEST( RetTest, default ) {
    EXPECT_EQ( 12, myInt(2 ) );
}

int main(int argc, char* argv[] ) {
    ::testing::InitGoogleTest(&argc, argv );
    return RUN_ALL_TESTS();
}

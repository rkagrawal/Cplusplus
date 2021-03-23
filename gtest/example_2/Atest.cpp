#include <iostream>
#include <memory>
#include "A.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::InvokeWithoutArgs;
using ::testing::NiceMock;


class MockB : public B {

  public:
    MockB() {}

    MOCK_METHOD0(getC, C*() );
};

class MockA : public A {

   public:
    MockA( B& b ) : A(b) {}

    MOCK_METHOD0(getB, MockB&() );
};

class Atest: public ::testing::Test {

    public:
        Atest() {}

    protected:
        std::shared_ptr<MockA> mya;

    virtual void SetUp() override {
       C * tc = new C(-20);

       MockB *b = new MockB();

       ON_CALL(*b, getC())
       .WillByDefault( Return ( tc ) );

        EXPECT_CALL(*b, getC())
        .Times(AtLeast(1));

       std::cout << "RKA--> " << b->getC()->getInt() << std::endl;

       std::shared_ptr<MockA> mya = std::make_shared<MockA>(*b);

       ON_CALL(*mya, getB() )
       .WillByDefault( ReturnRef( *b ) );

        EXPECT_CALL(*mya, getB())
        .Times(AtLeast(1));


        auto& tempB = mya->getB();

        std::cout << "RKA--> " << tempB.getC()->getInt() << std::endl;

        auto& tempB2 = mya->getB();
        std::cout << "RKA--> " << tempB2.getC()->getInt() << std::endl;
    }

};

TEST_F(Atest, default) {
    //std::cout << b.myC()->getInt() << std::endl;

}


int main(int argc, char* argv[] ) {
    testing::InitGoogleTest(&argc, argv );
    int retVal = RUN_ALL_TESTS();
    return retVal;
}


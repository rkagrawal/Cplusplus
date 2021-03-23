INC=${HOME}/googletest/googletest/include
LIB=${HOME}/googletest/build/lib

g++ -std=gnu++14 -I $INC -c emp.cpp
g++ -std=gnu++14 -I $INC -c fac.cpp
g++ -std=gnu++14 -I $INC -c emptest.cpp
g++ -std=gnu++14 -I $INC -o emptest.out emptest.o emp.o fac.o -L$LIB  -lgtest -lgtest_main -lgmock_main


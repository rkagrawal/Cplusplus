INC=${HOME}/googletest/googletest/include
LIB=${HOME}/googletest/build/lib

g++ -std=c++11 -I $INC -o Atest.out Atest.cpp -L$LIB  -lgtest -lgmock_main -lgmock -lpthread

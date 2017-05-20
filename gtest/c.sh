INC=/Users/Rajesh/googletest-release-1.8.0/googletest/include
LIB=/Users/Rajesh/googletest-release-1.8.0/bld/googlemock/gtest

clang++ -std=c++14 -I $INC -c emp.cpp
clang++ -std=c++14 -I $INC -c fac.cpp
clang++ -std=c++14 -I $INC -c emptest.cpp
clang++ -std=c++14 -I $INC -o emptest.out emptest.o emp.o fac.o -L$LIB -lgtest -lgtest_main


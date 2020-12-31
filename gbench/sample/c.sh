INC=/home/Raj/benchmark/include
LIB=/home/Raj/benchmark/build/src

g++ -std=c++11 -I${INC} -o main.out main.cpp -L${LIB} -lbenchmark -lpthread




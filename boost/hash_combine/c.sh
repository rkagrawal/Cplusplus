#INC=/usr/local/Cellar/boost/1.64.0_1/include
INC=/usr/include/boost
# Do not need -I $INC below as /usr/local/include/boost links to /usr/local/Cellar/boost
g++ -std=c++17 -I ${INC} -g -o main.out main.cpp

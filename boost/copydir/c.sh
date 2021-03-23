INC=/usr/include/boost
# Do not need -I $INC below as /usr/local/include/boost links to /usr/local/Cellar/boost
g++ -std=c++14 -I ${INC} -g -o main.out main.cpp


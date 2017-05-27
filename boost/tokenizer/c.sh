INC=/usr/local/Cellar/boost/1.64.0_1/include
# Do not need -I $INC below as /usr/local/include/boost links to /usr/local/Cellar/boost
clang++ -std=c++14 -g -o main.out main.cpp

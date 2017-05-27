INC=/Users/Rajesh/date-time
OBJ=/Users/Rajesh/date-time

clang++ -std=c++14 -g -o chrono.out chrono.cpp

clang++ -std=c++14 -I$INC -g -o date.out date.cpp

clang++ -std=c++14 -I$INC -g -o timezone.out timezone.cpp ${OBJ}/tz.o -lcurl


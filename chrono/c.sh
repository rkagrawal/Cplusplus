#INC=/Users/Rajesh/date-time
#OBJ=/Users/Rajesh/date-time

g++ -std=c++14 -g -o chrono.out chrono.cpp
g++ -std=c++14 -g -o gmtime.out gmtime.cpp

#g++ -std=c++14 -I$INC -g -o date.out date.cpp
#g++ -std=c++14 -I$INC -g -o timezone.out timezone.cpp ${OBJ}/tz.o -lcurl


#g++ -std=c++17 -I$INC -g -o date.out date.cpp
#g++ -std=c++17 -I$INC -g -o timezone.out timezone.cpp -lcurl

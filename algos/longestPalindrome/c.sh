clang++ -std=c++14 -c isPalindrome.cpp

INC=/Users/Rajesh/googletest-release-1.8.0/googletest/include
LIB=/Users/Rajesh/googletest-release-1.8.0/bld/googlemock/gtest

clang++ -std=c++14 -g -c isPalindrome.cpp
clang++ -std=c++14 -g -c longestPalindrome.cpp
clang++ -std=c++14 -I $INC -g -c palindrometest.cpp
clang++ -std=c++14 -I $INC -g -o palindrometest.out palindrometest.o isPalindrome.o \
                                    longestPalindrome.o  \
                                    -L$LIB -lgtest -lgtest_main

#clang++ -std=c++14 -g -o longestPalindrome.out longestPalindrome.o isPalindrome.o



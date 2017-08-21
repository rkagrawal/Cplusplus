#include<iostream>
#include<string>
#include "gtest/gtest.h"

using namespace std;

extern bool isPalindrome(const string& );
extern bool isPalindrome(const string&, int, int );
extern int  longestPalindrome( const string& );

TEST( PalinTest ,  Positive ) {
        ASSERT_EQ( true , isPalindrome( "" ) ) << "null string palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "a" ) ) << "single character palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "aa" ) ) << "two same character palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "aba" ) ) << "3 charater string palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "abcdcba" ) ) << "multi string palindrome test " ;
        ASSERT_EQ( true , isPalindrome( "xyyx" ) ) << "even length palindrome test ";
}

TEST( PalinTest ,  Negative ) {
        ASSERT_EQ( false , isPalindrome( "ab" ) ) << "2 different character palindrome test" ;
        ASSERT_EQ( false , isPalindrome( "abxdyba" ) ) << "multi string palindrome test " ;
        ASSERT_EQ( false , isPalindrome( "xyz" ) ) << "even length palindrome test ";
}

TEST( PalinTest2 ,  Positive ) {
        ASSERT_EQ( true , isPalindrome( "",0,0 ) ) << "null string palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "a", 0,0) ) << "single character palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "aa",0,1 ) ) << "two same character palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "aba",0,2 ) ) << "3 charater string palindrome test" ;
        ASSERT_EQ( true , isPalindrome( "abcdcba",0,6 ) ) << "multi string palindrome test " ;
        ASSERT_EQ( true , isPalindrome( "xyyx",0,3 ) ) << "even length palindrome test ";

        ASSERT_EQ( true , isPalindrome( "xyyx",1,2 ) ) << "even length palindrome test ";
}

TEST( PalinTest2 ,  Negative ) {
        ASSERT_EQ( false , isPalindrome( "ab",0,1 )) << "2 different character palindrome test" ;
        ASSERT_EQ( false , isPalindrome( "abxdyba",0,6 )) << "multi string palindrome test " ;
        ASSERT_EQ( false , isPalindrome( "xyz",0,2 ) ) << "even length palindrome test ";
        ASSERT_EQ( false , isPalindrome( "xyyx",2,5 ) ) << "even length palindrome test ";
}

TEST( LONGESTPALINDROMETEST, TEST ) {
    ASSERT_EQ( 0, longestPalindrome( "" )) << "Null string" ;
    ASSERT_EQ( 1, longestPalindrome( "a" )) << "one char ";
    ASSERT_EQ( 2, longestPalindrome( "aa" )) << "2 same characters" ;
    ASSERT_EQ( 1, longestPalindrome( "ab" )) << "2 different characters" ;
    ASSERT_EQ( 1, longestPalindrome( "abc" ))<< "3 different characters" ;
    ASSERT_EQ( 3, longestPalindrome( "aba" ))<< "3 palindrome characters" ;
    ASSERT_EQ( 3, longestPalindrome( "aabad" ))<< "2 palindroms of lengths 2(beginning) and 3 " ;
    ASSERT_EQ( 3, longestPalindrome( "dabaa" ))<< "2 palindroms of lengths 3 and 2(end) "  ;
    ASSERT_EQ( 5, longestPalindrome( "aabaa" )) << "palindrom of length 5 " ;
    ASSERT_EQ( 5, longestPalindrome( "aaaabaa" ))<< "2 palindroms of length 4(begin) and 5" ;
    ASSERT_EQ( 5, longestPalindrome( "aaaaabaa" ))<< "2 palindroms of length 5 each";
    ASSERT_EQ( 6, longestPalindrome( "aaaaaabaa" ))<< "2 palindroms of length 6( begin) and 5";
    ASSERT_EQ( 7, longestPalindrome( "aaaaaabaaa" ))<< "2 palindroms of length 6 and 7(end)";
    ASSERT_EQ( 7, longestPalindrome( "zaaaaaabaaaxyz" ))<< "2 palindroms of length 6 and 7";
    ASSERT_EQ( 1, longestPalindrome( "abcdefghijklmnopqrstuvwxyz" ))<< "fullabc";
    ASSERT_EQ( 2, longestPalindrome( "abcdefghijklmnopqrsstuvwxyz" ))<< "fullabc with len 2 palindrome";
    ASSERT_EQ( 3, longestPalindrome( "abcdefghijklmnonpqrsstuvwxyz" ))<< "fullabc with len 3 palindrome";
    ASSERT_EQ( 23, longestPalindrome( "abcdefghijklmnonpnonmlkjihgfqrsstuvwxyz" ))<< "fullabc with len 3 palindrome";
    ASSERT_EQ( 22, longestPalindrome( "abcdefghijklmnonnonmlkjihgfqrsstuvwxyz" ))<< "fullabc with len 3 palindrome";
    ASSERT_EQ( 5, longestPalindrome( "Uneven" ))<< "fullabc with len 3 palindrome";
}

int main(int argc, char* argv[] ) {
    testing::InitGoogleTest(&argc, argv );
    return RUN_ALL_TESTS();
}




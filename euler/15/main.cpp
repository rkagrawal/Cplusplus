#include<iostream>
#include<vector>
#include<sstream>
#include<map>

#define SIZE 18

std::vector<std::vector<long>> hasPath(SIZE, std::vector<long>(SIZE, -1));
std::map<std::string, unsigned long> mapPath;


 long findAllPaths( int i, int j, std::vector<std::vector<long>>& hasPath ) {

    if ( i== 0 && j== 0)
        return 1;

    if ( i < 0 || j < 0 )
        return 0;


    //std::cout << "Finding path for i:"<< i << " j:" << j << std::endl;
    if (hasPath[i][j] != -1 )  return hasPath[i][j];

    hasPath[i][j] = findAllPaths(i, j-1, hasPath) + findAllPaths(i-1, j, hasPath );
    return hasPath[i][j];
}


unsigned long findAllPaths2( int i, int j, std::map<std::string, unsigned long>& mapPath ) {

    std::stringstream sstr ;
    sstr << i<< "," << j ;

    //std::cout << "The string is " << sstr.str() << std::endl;
    if ( mapPath.find( sstr.str() ) != mapPath.end() ) return mapPath[ sstr.str() ];

    if ( i== 0 && j== 0)
        return 1;

    if ( i < 0 || j < 0 )
        return 0;


    unsigned long num = findAllPaths2(i-1, j, mapPath) + findAllPaths2(i, j-1, mapPath );
    mapPath.insert( std::make_pair( sstr.str(), num ) );
    return  num;
}


int main() {

	std::cout << "The total number of ways is " << findAllPaths( SIZE-1, SIZE-1, hasPath ) << std::endl;
	std::cout << "The total number of ways is " << findAllPaths2( SIZE-1, SIZE-1, mapPath ) << std::endl;

}



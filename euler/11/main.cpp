#include<iostream>
#include<array>
#include<vector>
#include<cmath>
#include<chrono>

std::array< std::array<int, 20>, 20 > matrix = {
	{ 	{8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8},
		{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0},
		{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65},
		{52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91},
		{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
		{24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50},
		{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
		{67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
		{24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
		{21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95},
		{78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92},
		{16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57},
		{86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58},
		{19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40},
		{4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66},
		{88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69},
		{4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
		{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16},
		{20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54},
		{1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48}
	}
};


enum direction {
	north=0,
    northeast,
    east,
    southeast,
    south,
    southwest,
    west,
    northwest
};


std::vector<std::vector< std::vector<int> > > calcprd( 20, std::vector<std::vector<int>>(20, std::vector<int>(8,-1)));


int maxindirection( int i, int j, int level, direction d ) {
	if( i >= 20 ||  j>= 20 || i < 0 || j <0 ) return 0;

	if( level == 1 ) return matrix[i][j];

	int curnum = matrix[i][j];

 	switch( d ) {
		case direction::east:
			++j;
			break;
		case direction::west:
			--j;
			break;
		case direction::southeast:
			++i; ++j;
			break;
		case direction::south:
			++i;
			break;
		case direction::southwest:
			++i; --j;
			break;
		case direction::northwest:
			--i; --j;
			break;
		case direction::north:
			--i; j;
			break;
		case direction::northeast:
			--i; ++j;
			break;
	}

	return curnum * maxindirection(i,j,--level, d );
}



int findmax( int i, int j, int level ) {

	if( i > 20 ||  j> 20 || i < 0 || j <0 ) return 0;

	int curval = matrix[i][j];
	return 
		std::max (
		  	curval * maxindirection( i, j+1, level-1, direction::east ),
		  	std::max( 
		  		curval * maxindirection( i, j-1, --level-1, direction::west ),
		  		std::max( 
		  			curval * maxindirection( i+1, j+1, level-1, direction::southeast ),
		  			std::max(
		  				curval * maxindirection( i+1, j, level-1 , direction::south),
		  				std::max( 
		  					curval * maxindirection( i+1, j-1, level-1, direction::southwest ),
							std::max( 
		  						curval * maxindirection( i-1, j-1, level-1, direction::northwest),
								std::max( 
		  							curval * maxindirection( i-1, j, level-1 , direction::north),
		  							curval * maxindirection( i-1, j+1, level-1,direction::northeast) 
								)
							)
						)
					)
				)
			)
		);
}

int findmax_efficient( int i, int j, int level ) {

	if( i > 20 ||  j> 20 || i < 0 || j <0 ) return 0;

	int curval = matrix[i][j];

	int eastmax;
	if (  calcprd[i][j][direction::east] == -1 ) {
		eastmax = curval * maxindirection( i, j+1, level-1, direction::east );
		calcprd[i][j][direction::east] = eastmax; 
        if( i+3 < 20 ) calcprd[i+3][j][direction::west] = eastmax;
	} else {
		eastmax = calcprd[i][j][direction::east];
	}

    int westmax;
	if( calcprd[i][j][direction::west] == -1  ) {
		westmax = curval * maxindirection( i, j-1, level-1, direction::west );		
		calcprd[i][j][direction::west] = westmax ;
		if( i-3 >= 0 ) calcprd[i-3][j][direction::west] = westmax;
	} else {
		westmax = calcprd[i][j][direction::west];
	}
		
    int southeastmax;
	if(  calcprd[i][j][direction::southeast] == -1  ) {
		southeastmax = curval * maxindirection( i+1, j+1, level-1, direction::southeast );
		calcprd[i][j][direction::southeast] = southeastmax;
		if( i-3 >= 0 && j-3 >= 0 ) calcprd[i-3][j-3][direction::northwest] = southeastmax;
	} else {
		southeastmax =  calcprd[i][j][direction::southeast];
	}

    int southmax;
	if(  calcprd[i][j][direction::south] == -1  ) {
		southmax = curval * maxindirection( i+1, j, level-1 , direction::south);
		calcprd[i][j][direction::south] = southmax;
		if( i-3 >= 0) calcprd[i-3][j][direction::north] = southmax;
	} else {
		southmax = calcprd[i][j][direction::south];
	}

    int southwestmax;
	if ( calcprd[i][j][direction::southwest] == -1 ) {
	 	southwestmax = curval * maxindirection( i+1, j-1, level-1, direction::southwest );
		calcprd[i][j][direction::southwest] = southwestmax;
		if( i-3 >= 0 && j+3 < 20 ) calcprd[i-3][j+3][direction::northeast] = southwestmax;
	} else {
		southwestmax = calcprd[i][j][direction::southwest];
	}

    int northwestmax;
	if ( calcprd[i][j][direction::northwest] == -1 ) {
		northwestmax = curval * maxindirection( i-1, j-1, level-1, direction::northwest);
		calcprd[i][j][direction::northwest] = northwestmax;
		if( i+3 < 20 && j+3 < 20 ) calcprd[i+3][j+3][direction::southeast] = northwestmax;
	} else {
		northwestmax = calcprd[i][j][direction::northwest];
	}

    int northmax;
	if ( calcprd[i][j][direction::north] == -1 ) {
		 northmax = curval * maxindirection( i-1, j, level-1 , direction::north);
		calcprd[i][j][direction::north] = northmax;
		if( i+3 < 20 ) calcprd[i+3][j][direction::south] = northmax;
	} else {
		northmax = calcprd[i][j][direction::north];
	}

    int northeastmax;
	if ( calcprd[i][j][direction::northeast]  == -1 ) {
		 northeastmax = curval * maxindirection( i-1, j+1, level-1,direction::northeast);
		 calcprd[i][j][direction::northeast] = northeastmax;
		 if( i+3 < 20 && j-3 >= 0 ) calcprd[i+3][j-3][direction::southwest] = northeastmax;
	} else {
		northeastmax =  calcprd[i][j][direction::northeast];
	}

	/*
	std::cout << "i:" << i << " j:" << j << " eastmax : " << eastmax 
			  << " southeastmax:" << southeastmax << " southmax:" << southmax 
			  << " southwestmax:" << southwestmax << " westmax:" << westmax 
			  << " northwestmax:" << northwestmax << " northmax:" << northmax 
              << " northeastmax:" << northeastmax << std::endl;
	*/

	return std::max( eastmax,
					std::max( southeastmax,
						std::max( southmax,
							std::max( southwestmax,
								std::max( westmax,
									std::max( northwestmax,
										std::max( northmax, northeastmax )
									)
								)
							)
						)
					)
			);
}

int main() {

	for (int i=0; i<20; ++i) {
		for(int j=0;j<20;j++ ) {
			std::cout << matrix[i][j] << ' ' ;
		}
		std::cout << std::endl;
	}


	std::chrono::system_clock::time_point tp1 = std::chrono::system_clock::now();

	int m = 0;
	for (int i=0; i<20; ++i) {
		for(int j=0;j<20;j++ ) {
			//int p = findmax( i,j,4 );
			int p = findmax_efficient( i,j,4 );
			if ( m < p ) {
				std::cout << "The curr max is at " << i << "," << j << std::endl;
				m = p;
			}
		}
	}

	std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::now();

	std::cout << "The max product is " << m << " found in " << std::chrono::duration_cast<std::chrono::microseconds>(tp2-tp1).count() << " microseconds" << std::endl;

}

#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<chrono>

std::unordered_map<unsigned long,int> countArray;

int pathCount(unsigned long num_ ) {

    //std::cout << num_ << std::endl;
    if( num_ == 1 ) {
        countArray[num_] = 1;
        return countArray[num_];
    }
    else {
        unsigned long en;
        if (num_ % 2 == 0 )
            en = num_ / 2;
         else
            en=3*num_ + 1;

        if( countArray.find(en) == countArray.end() )
            countArray[en] = pathCount(en);

        return 1+countArray[en];
    }
}

int main( int arg, const char* argv[] ) {
    int num = std::atoi( argv[1]);

	std::chrono::system_clock::time_point tp1 = std::chrono::system_clock::now();

    int max=1;
    unsigned long maxat = 1;
    for ( unsigned long i = num; i >= 1; --i ) {
        int pc = pathCount(i);
        if( max < pc ) {
           max = pc;
           maxat = i;
        }
    }

    std::cout << "The max pathCount is " << max << " for num " << maxat << std::endl;
	std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::now();
    std::cout << "time taken is " << std::chrono::duration_cast<std::chrono::microseconds>( tp2-tp1).count() << std::endl;
    std::cout << "time taken is " << std::chrono::duration_cast<std::chrono::milliseconds>( tp2-tp1).count() << std::endl;
}

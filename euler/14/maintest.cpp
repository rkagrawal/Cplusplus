#include<iostream>
#include<unordered_map>
#include<cstdlib>

std::unordered_map<unsigned long,int> countArray;

int pathCount(unsigned long num_ ) {

    std::cout << num_ << std::endl;
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

	int pc = pathCount(num);

    std::cout << "The pathCount is " << pc << " for num " << num << std::endl;
}

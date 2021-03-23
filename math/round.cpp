#include<iostream>
#include<cmath>

enum RoundingDirection { NORMAL, UP, DOWN};

namespace MY {
inline int round(
		double x_, 
		double unitSize_ = 1, 
		RoundingDirection roundingDirection_ = NORMAL) 
	{ 
		double change = 0;
		switch(roundingDirection_)
		{
		case NORMAL:
			change = unitSize_ / 2;
			break;
		case UP:
			change = unitSize_;
			break;
		case DOWN:
			change = 0;
			break;
		}

		return int(floor((x_ + change) / unitSize_)); 
	}

}

int main() {

	std::cout << "Round normal of 86.3 unit sz: 1  is " << MY::round(86.3 , 1, RoundingDirection::NORMAL) << std::endl;
	std::cout << "Round normal of 86.3 unit sz:0.25  is " << MY::round(86.3 , .25, RoundingDirection::NORMAL) << std::endl;

	std::cout << "Round UP of 86.3 unit sz: 1  is " << MY::round(86.3 , 1, RoundingDirection::UP) << std::endl;
	std::cout << "Round UP of 86.3 unit sz:0.25  is " << MY::round(86.3 , .25, RoundingDirection::UP) << std::endl;

	std::cout << "Round DOWN of 86.3 unit sz: 1  is " << MY::round(86.3 , 1, RoundingDirection::DOWN) << std::endl;
	std::cout << "Round DOWN of 86.3 unit sz:0.25  is " << MY::round(86.3 , .25, RoundingDirection::DOWN) << std::endl;

	std::cout << "Round UP of 0.03 unit sz: 0.01  is " << MY::round(double(0.03) , double(0.01), RoundingDirection::UP) << std::endl;
}

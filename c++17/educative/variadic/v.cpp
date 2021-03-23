#include<iostream>
#include <tuple>

 struct Point  { 
    double x; 
    double y; 
	Point(int x_, int y_) : x(x_), y(y_){
		std::cout << "I am Point " << x << " " << y << "\n";;
	}
};


class UserEntry {
public:
    UserEntry(std::string name_) : name( std::move( name_) ){ 
		std::cout << "I am UserEntry \n";;
	}
    
    void Load() { 
        // simulate loading from db...
        name="John"; 
        age=45;
        cacheEntry = 10;
    }
    
    std::string GetName() const { return name; }
    unsigned GetAge() const { return age; }
    
private:
    std::string name;
    unsigned age { 0 };
    size_t cacheEntry { 0 };
};

template<typename ...Ts> class XYZ : Ts... {
	public:
		XYZ(Ts... parents): Ts(parents)...  {
			std::cout << "I am XYZ\n";
		}
};

int main() {

	XYZ<Point, UserEntry> xyz( {2, 3}, std::string("rajesh"));
	XYZ<UserEntry, Point> xyz2{std::string("Shivam"),  {3,4} };
	
}

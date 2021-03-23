#include<iostream>

class A {

	private:
		static int count ;
		int instid;

	public:
		A(int id) : instid(id) {
			++A::count;
		}
		int getId() const { return instid;}

		static int getInstanceCount(){ return count ; }

		int getCount() const { return count; }
};

std::ostream& operator<<( std::ostream& a, const A& mya ) {
	a << "instId:" << mya.getId() << " Total instances via static call:" << A::getInstanceCount()
	  << " total instance via non static call: " << mya.getCount() << std::endl;
	return a;
}


int A::count= 0;

int main() {
	A ma(1);
	A na(6);
	std::cout << ma << std::endl;
	std::cout << na << std::endl;
}


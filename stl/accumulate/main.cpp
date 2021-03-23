#include <iostream>
#include <map>
#include <numeric>

struct TQ {
	TQ( int x ) : totalQty(x) {}
	int totalQty ;

	int getTotalQty() { return totalQty; }
};


int main() {

	std::map< int, TQ > m { {1, 30},
		{2, -39},
		{3, 5} };


   int t = std::accumulate( m.begin(), m.end(), 0,
						[]( int totQty, std::pair<int, TQ> p ) {
							totQty += abs(p.second.getTotalQty());
							return totQty;
						});

	std::cout << "The total qty is " << t << std::endl;
}

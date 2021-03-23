#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string_view>


/* using string_view does not work in this case as the target keeps changing */

int canConstruct( std::string_view& target, const std::vector<std::string_view>& v, std::map<std::string_view, int>& m ) {

	if( m.find( target ) != m.end() ) m[target] ;
	if( target.size() == 0 ) return 1;

	int totalCount = 0;
	for( const auto& s : v ) {
		const int len = s.size();
		std::cout << "Checking : " << target <<  " and " << s  << std::endl;
		if(  s == target.substr(0,len) ) {
			target.remove_prefix(len);
			//std::cout << "   Checking : " << target <<  " and " << s << std::endl;
			if( canConstruct(target, v, m ) == 1 ) {
				totalCount += 1;
			}
		}
	}
	
	m[target] = totalCount;
	return m[target];
}


int main() {

	//std::string_view target { "potatoe", 7 };
	//std::string_view target2 { "potatoexyz", 10 };
	//std::vector<std::string_view> v = { "pot", "e", "at", "oe", "x", "y", "z" };

	std::string_view target2 { "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", 31 };
	std::vector<std::string_view> v = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" };
	
	std::map<std::string_view, int> m;

    std::cout << "Can construct target from vector of strings is " << canConstruct( target2, v, m ) << std::endl;

}

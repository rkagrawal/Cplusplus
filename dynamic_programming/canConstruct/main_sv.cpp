#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string_view>


// below with string_view has an issue that the target changes after iteration..

bool canConstruct( std::string_view& target, const std::vector<std::string_view>& v, std::map<std::string_view, bool>& m ) {

	if( m.find( target ) != m.end() ) return m[target];
	if( target.size() == 0 ) return true;

	for( const auto& s : v ) {
		const int len = s.size();
		std::cout << "Checking : " << target <<  " and " << s  << std::endl;
		if(  s == target.substr(0,len) ) {
			target.remove_prefix(len);
			std::cout << "   Checking : " << target <<  " and " << s << std::endl;
			if ( canConstruct( target, v, m ) == true )
			{
				m[target] = true;
				return true;
			}
		}
			
	}
	m[target] = false;
	return false;
}


int main() {

	//std::string_view target { "potatoe", 7 };
	//std::string_view target2 { "potatoexyz", 10 };
	//std::vector<std::string_view> v = { "pot", "e", "at", "oe", "x", "y", "z" };

	std::string_view target2 { "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 32 };
	std::vector<std::string_view> v = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" };
	
	std::map<std::string_view, bool> m;

    std::cout << "Can construct target from vector of strings is " << canConstruct( target2, v, m ) << std::endl;

}

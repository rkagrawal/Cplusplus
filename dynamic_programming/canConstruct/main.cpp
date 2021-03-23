#include<iostream>
#include<vector>
#include<map>
#include<string>



bool canConstruct( std::string& target, const std::vector<std::string>& v, std::map<std::string, bool>& m ) {

	if( m.find( target ) != m.end() ) return m[target];
	if( target.size() == 0 ) return true;

	for( const auto& s : v ) {
		const int len = s.size();
		std::cout << "Checking : " << target <<  " and " << s  << std::endl;
		if(  s == target.substr(0,len) ) {
			std::string newtarget = target.substr(len);
			if ( canConstruct( newtarget, v, m ) == true )
			{
				std::cout << "SUCCESSFUL\n";
				m[target] = true;
				return true;
			}
		}
			
	}
	std::cout << "Setting target " << target << " false\n"; 
	m[target] = false;
	return false;
}


int main() {

	//std::string target2 { "potatoe", 7 };
	//std::string target2 { "potatoexyz", 10 };
	//std::vector<std::string> v = { "pot", "e", "at", "oe", "x", "y", "z" };

	//std::string target2 { "skateboard", 10 };
	//std::vector<std::string> v = { "bo", "rd", "ate", "k", "ska", "sk", "boar"};

	std::string target2 { "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 32 };
	std::vector<std::string> v = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" };
	
	std::map<std::string, bool> m;

    std::cout << "Can construct target from vector of strings is " << canConstruct( target2, v, m ) << std::endl;

}

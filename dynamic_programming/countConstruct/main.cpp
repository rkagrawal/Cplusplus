#include<iostream>
#include<vector>
#include<map>
#include<string>



int countConstruct( std::string& target, const std::vector<std::string>& v, std::map<std::string, int>& m ) {

	if( m.find( target ) != m.end() ) return m[target];
	if( target.size() == 0 )  { return 1; }

	int total=0;
	for( const auto& s : v ) {
		const int len = s.size();
		//std::cout << "Checking : " << target <<  " and " << s  << std::endl;
		
		if(  s == target.substr(0,len) ) {
			std::string newtarget = target.substr(len);
			int count = countConstruct( newtarget, v, m ) ;
		    total += count;	
		}
	}

	m[target] = total;
	std::cout << "Returning count " << m[target] << " for target " << target << std::endl;
	return m[target];
}


int main() {

	//std::string target2 { "potatoe", 7 };
	//std::string target2 { "potatoexyz", 10 };
	//std::vector<std::string> v = { "pot", "e", "at", "oe", "x", "y", "z" };

	//std::string target2 { "skateboard", 10 };
	//std::vector<std::string> v = { "bo", "rd", "ate", "k", "ska", "sk", "boar"};

	//std::string target2 { "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 32 };
	//std::vector<std::string> v = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" };

	//std::string target2 { "enterapotentpot", 15 };
	//std::vector<std::string> v = { "a", "p", "ent", "enter", "ot", "o", "t" };

	//std::string target2 { "raj", 3 };
	//std::vector<std::string> v = { "r", "a", "j", "ra" };
	
	std::string target2 { "purple", 6 };
	std::vector<std::string> v = { "purp", "p", "ur", "le", "purpl" };

	std::map<std::string, int> m;

    std::cout << "Can construct target from vector of strings is " << countConstruct( target2, v, m ) << std::endl;

}

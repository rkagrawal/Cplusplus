#include<iostream>
#include<vector>
#include<map>
#include<string>


using V = std::vector<std::vector<std::string>>;

V countConstruct( std::string& target, const std::vector<std::string>& v, std::map<std::string, V>& m ) {

	if( m.find( target ) != m.end() ) return m[target];
	if( target.size() == 0 )  { 
		return V{1, std::vector<std::string>{}};
	}

	V abc;
	for( const auto& s : v ) {
		const int len = s.size();
		//std::cout << "Checking : " << target <<  " and " << s  << std::endl;
		
		if(  s == target.substr(0,len) ) {
			std::string newtarget = target.substr(len);
			V myvec = countConstruct( newtarget, v, m ) ;
			for( auto myv : myvec ) {
				myv.push_back( s );
				std::cout << "Pushed " << newtarget << std::endl;
				abc.push_back( std::move( myv ));
			}
			
		}
	}

	m[target] = std::move(abc);
	return m[target];
}


int main() {

	//std::string target2 { "potatoe", 7 };
	//std::string target2 { "potatoexyz", 10 };
	//std::vector<std::string> v = { "pot", "e", "at", "oe", "x", "y", "z" };

	//std::string target2 { "skateboard", 10 };
	//std::vector<std::string> v = { "bo", "rd", "ate", "k", "ska", "sk", "boar"};

	std::string target2 { "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 32 };
	std::vector<std::string> v = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" };

	//std::string target2 { "enterapotentpot", 15 };
	//std::vector<std::string> v = { "a", "p", "ent", "enter", "ot", "o", "t" };

	//std::string target2 { "raj", 3 };
	//std::vector<std::string> v = { "r", "a", "j", "ra" };
	
	//std::string target2 { "purple", 6 };
	//std::vector<std::string> v = { "purp", "p", "ur", "le", "purpl" };

	std::map<std::string, V> m;

    //std::cout << "Can construct target from vector of strings is " << countConstruct( target2, v, m ) << std::endl;

	V r = countConstruct( target2, v, m );
	for ( auto& mv : r ) {
		std::cout << "[";
		for (  auto& e : mv )  {
			std::cout << e << ",";
		}
		std::cout << "]\n";
	}	
}

#include<stack>
#include<string>
#include<iostream>
#include<algorithm>

int main(int argc, const char* argv[] ) {

	/* "3[a2[c]]" */
	if( argc != 2 ) return 0;

	std::string s = argv[1];
	std::stack<char> mystack;

	int i=0;
	int nestlevel = 0;

	std::string prevNestedStr;
	std::string finalStr="";
	while( i < s.size() )  {
		if (nestlevel == 0 && !std::isdigit( s[i]) ) {
			finalStr += s[i];
			i++;
			continue;
		}

		if ( s[i] == ']' ) {
			// pop from stack and print number of times...
			char c = mystack.top();	
			std::string tempStr;
			while ( c != '[' ) {
				std::cout << "popped: " << c <<std::endl;
				mystack.pop();
				tempStr += c;	
				c = mystack.top();
			}
			mystack.pop(); // number;;
			int d = mystack.top() - '0';
			std::cout << "popped d: " << d <<std::endl;
			mystack.pop();
			--nestlevel;
			std::cout << "tempStr: " << tempStr << std::endl;

			std::reverse( tempStr.begin(), tempStr.end() );
			
			tempStr += prevNestedStr;
			std::string tempStr2= "";

			for (int k = 0; k<d; k++ ) {
				tempStr2 += tempStr;
			}

			if( nestlevel <= 0 ) {
				finalStr += tempStr2;
				prevNestedStr = "";
			} else  {
				prevNestedStr = tempStr2;
			}

			std::cout << " final: " << finalStr << " inter final prevNestedStr:" << prevNestedStr << std::endl;
			i++; continue;
			
		} else if ( std::isdigit( s[i] ) ) {
			nestlevel += 1;
		} 

		mystack.push( s[i] );
		i++;
	}

	std::cout << "The final str is " << finalStr << std::endl;
}

/* https://adamdrake.com/an-unreasonably-deep-dive-into-project-euler-problem-2.html */
#include <iostream>

int main() {
   int f=0;
   int s=1;
 
   int counter = 2; 
   unsigned long sum=0;
   while ( sum < 4000000 ) {  
	if (s %2 == 0 ) sum += s;	
	int n = f+s;  f=s;s=n;
   }

   std::cout << "the sum of even number fib series is " << sum <<std::endl;
}


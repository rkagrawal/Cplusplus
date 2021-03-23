#include<iostream> 
using namespace std; 
  
class dog 
{ 
public: 
    dog()  
    { 
        cout<< "Constructor called" <<endl; 
        bark() ; 
    } 
  
    virtual ~dog() 
    {  
		cout << "Inside  dog destructor\n";
        bark();  
    } 
  
    virtual void bark() 
    {  
        cout<< "dog Virtual method called" <<endl;  
    } 
  
    void seeCat()  
    {  
        bark();  
    } 
}; 
  
class Yellowdog : public dog 
{ 
public: 
        Yellowdog()  
        { 
            cout<< "Derived class Constructor called" <<endl;  
			bark();
        } 
        void bark()  
        { 
            cout<< "yello dog : Derived class Virtual method called" <<endl;  
        } 

		~Yellowdog() {
			cout << "Inside yellow dog destructor\n";
			bark();
		}
}; 
  
int main() 
{ 
    dog *d = new Yellowdog; 
	std::cout << "Now destroying ---------------\n";
	delete d;
} 

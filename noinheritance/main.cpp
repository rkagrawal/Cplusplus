//
//  main.cpp
//  NoInheritance
//
//  Created by Rajesh Agrawal on 3/26/17.
//  Copyright © 2017 Rajesh Agrawal. All rights reserved.
//  This is from Sean Parent's talk on Inheritance is the root of all evils
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template< typename T >
void draw2( const T& d , ostream& o ) {
    o << d << endl;
};


class object_t {
public:
    template< typename T>
    object_t( T d ) : self( new model_t<T>( d ) ) {}
    object_t( const object_t& o) : self( o.self->copy() ){}
    
    void draw( ostream& o ) const {
        self->draw(o);
    }
    
private:
    
    struct concept_t {
        virtual ~concept_t() = default;
        virtual void draw( ostream& o) = 0;
        virtual concept_t *copy() = 0;
    };
    
    template< typename T>
    struct model_t :  public concept_t {
        model_t( T d): mydata_( move( d ) ) {};
        void draw( ostream& o ) {
            draw2( mydata_, o ) ;
        }
        
        concept_t* copy() { return new model_t( *this ) ; }
        
        T  mydata_;
    };
    
    unique_ptr<concept_t> self;
};

void draw( const object_t& obj, ostream& o ) {
    obj.draw(o);
}

void draw( const vector<object_t> & v, ostream& o ) {
    for(auto& p : v)
        draw( p, o);
}

int main(int argc, const char * argv[]) {
    vector<object_t> document;
    
    document.emplace_back( 5 );
    document.emplace_back( "Rajesh" );
    draw(document, cout);
    return 0;
};

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<array>
#include<list>
#include<set>

using namespace std;

void test_vector_iterator() {
    vector<string> v = { "rajesh", "suresh", "mahesh", "dinesh", "ganesh", "dipesh", "pravesh" };
    sort( begin(v), end(v) );

    cout << "\n VECTOR ITERATOR TEST\n";
    for( auto& s : v ) cout << s << ",";
    cout << endl;

    auto it1 = find( begin(v), end(v), "mahesh" );
    cout << "Mahesh is found at a distance of " << abs( distance( v.begin(), it1 ) ) << endl;
    cout << "Mahesh is found at index of " << it1 - v.begin() << endl;

    advance(it1, 2 );
    cout << "Two position from Mahesh is " << *it1 << endl;

    cout << "The distance of rajesh from end is " << v.end() - it1 << endl;

    auto it2 = v.end();
    advance( it2, -5 );
    cout << "Five spots from end is " << *it2 << " at index " << it2 - v.begin() << endl;
    
}

void test_set_iterator() {
    set<string> s = { "rajesh", "suresh", "mahesh", "dinesh", "ganesh", "dipesh", "pravesh" };


    cout << "\n SET ITERATOR TEST\n";

    for( auto& e : s ) cout << e << ",";
    cout << endl;

    auto it1 = find( begin(s), end(s), "mahesh" );
    cout << "Mahesh is found at a distance of " << abs( distance( s.begin(), it1 ) ) << endl;
    cout << "Index does not make sense in set  so.. no test " << endl;  

    advance(it1, 2 );
    cout << "Two position from Mahesh is " << *it1 << endl;

    cout << "The distance of rajesh from end is " << distance( it1,s.end() ) << endl;
    cout << "The distance of rajesh and suresh  " << distance( s.find("rajesh"), s.find("suresh") ) << endl;
    /* the below causes segmentatin fault 
     *  as it looks like advance needs start iterator to be earlier in the 
     * set
    cout << "The distance of suresh and rajesh  " << distance( s.find("suresh"), s.find("rajesh") ) << endl;
    */

    auto it2 = s.end();
    advance( it2, -5 );
    cout << "Five spots from end is " << *it2 << endl;
    cout << "Prev from " << *it2 << "is " << *prev( it2, 1 ) << endl;
}


void test_list_iterator() {
    list<string> l = { "rajesh", "suresh", "mahesh", "dinesh", "ganesh", "dipesh", "pravesh" };


    cout << "\n LIST ITERATOR TEST\n";
    cout << "Before sorting \n";
    for( auto& e : l ) cout << e << ",";
    cout << endl;

    l.sort();
    cout << "Before sorting \n";
    for( auto& e : l ) cout << e << ",";
    cout << endl;


    auto it1 = find( begin(l), end(l), "mahesh" );
    cout << "Mahesh is found at a distance of " << abs( distance( l.begin(), it1 ) ) << endl;
    cout << "Index does not make sense in set  so.. no test " << endl;  

    advance(it1, 2 );
    cout << "Two position from Mahesh is " << *it1 << endl;

    cout << "The distance of rajesh from end is " << distance( it1,l.end() ) << endl;
    cout << "The distance of rajesh and suresh  " << distance( find(begin(l),end(l),"rajesh"), 
                                                               find(begin(l),end(l),"suresh") ) << endl;

    cout << "The distance of suresh and rajesh  " << distance( find(begin(l),end(l),"suresh"), 
                                                               find(begin(l),end(l),"rajesh") ) << endl;

    auto it2 = l.end();
    advance( it2, -5 );
    cout << "Five spots from end is " << *it2 << endl;
    cout << "Prev from " << *it2 << "is " << *prev( it2, 1 ) << endl;

    cout << "using next with 1 on it1 which is 2 positions from mahesh is " << *next(it1,1) << endl; 
}


void test_map_iterator() {
    map<string, string> m = { {"rajesh", "us"}, {"suresh","in"}, {"mahesh","in"}, {"dinesh","us"}, 
                               {"ganesh","us"}, {"dipesh","in"}, {"pravesh","in"} };


    cout << "\n MAP ITERATOR TEST\n";

    for( auto& e : m ) cout << e.first << "->" << e.second << " ,";
    cout << endl;


    auto it1 = m.find( "mahesh" );
    cout << "Mahesh is found at a distance of " << abs( distance( m.begin(), it1 ) ) << endl;
    cout << "Index does not make sense in set  so.. no test " << endl;  

    advance(it1, 2 );
    cout << "Two position from Mahesh is " << it1->first << ":" << it1->second << endl;

    cout << "The distance of rajesh from end is " << distance( it1,m.end() ) << endl;
    cout << "The distance of rajesh and suresh  " << distance( m.find("rajesh"), 
                                                               m.find("suresh") ) << endl;

//    cout << "The distance of suresh and rajesh  " << distance( m.find("suresh"), 
//                                                               m.find("rajesh") ) << endl;
    auto it2 = m.end();
    advance( it2, -5 );
//    it2 = prev( it2, -5 );
 //   if (it2 != m.end() )
        cout << "Five spots from end is " << it2->first << ":" << it2->second << endl;
    auto it3 = prev(it2,2);
    cout << "Prev by 2 from " << it2->first <<":"<<it2->second  << "is " << it3->first << ":" << it3->second
         << endl;
    auto it4 = next(it1,1);
    cout << "using next with 1 on it1 which is 2 positions from mahesh is " 
         << it4->first << ":" << it4->second << endl;
}

int main(int argc, const char* argv[] ) {
    test_vector_iterator();
    test_set_iterator();
    test_list_iterator();
    test_map_iterator();
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void build( vector<int>& tree, vector<int>& arr, int nodeidx, int low, int high ) {
    if ( low == high ) {
        cout << "saving " << arr[ low ] << " at tree index " << nodeidx << endl;;
        tree[nodeidx] = arr[low];
        return;
    }

    int mid = low + ( high-low)/2;
    cout << "mid:" << mid << "low:"<< low << "high:" << high << endl;
    build( tree, arr, 2*nodeidx, low, mid );
    build( tree, arr, 2*nodeidx+1, mid+1, high );

    cout << "saving "<<tree[2*nodeidx] <<"+"<< tree[2*nodeidx + 1 ] << " at nodeidx " << nodeidx << endl;
    tree[nodeidx] = tree[2*nodeidx] + tree[2*nodeidx + 1 ];
}

int query( vector<int>& tree, int nodeidx, int low, int high, int rangestart, int rangeend  ) {

    if ( rangestart>high ||  rangeend < low) return 0;
    if ( rangestart<= low && rangeend >= high ) {
       cout << "returning...sum->rangest:"<<rangestart<<"low:"<<low<<"rangeend:"<<rangeend<<"high:"<<high<<endl;
       return tree[nodeidx];
    } else {
       cout << "continuing...->rangest:"<<rangestart<<"low:"<<low<<"rangeend:"<<rangeend<<"high:"<<high<<endl;
    }


    int mid = low + ( high-low)/2;
    int p1 = query( tree, 2*nodeidx, low, mid, rangestart, rangeend );
    int p2 = query( tree, 2*nodeidx+1, mid+1, high, rangestart, rangeend );
    return (p1+p2);
}

int main(int argc, const char* argv[] ) {

   //vector<int> v = { 0,1,2,3,4,5,6,7,8}; 
   vector<int> v = { 18, 17, 13, 19, 15, 11, 20, 12, 33, 25 };
   vector<int> t(4*v.size(),0) ;
   build( t, v, 1, 0, v.size()-1 );

   copy( begin( t), end(t), ostream_iterator<int>( cout, "," ) );
   cout << endl;
   cout <<"The sum of range 2,8 is " << query( t, 1, 0,v.size()-1, 2,8) << endl;
   cout <<"The sum of range 3,7 is " << query( t, 1, 0,v.size()-1, 3,7) << endl;
}

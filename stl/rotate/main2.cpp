//
//  main.cpp
//  rotate
//
//  Created by Rajesh Agrawal on 3/23/17.
//  Copyright © 2017 Rajesh Agrawal. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    
    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
    
    std::cout << "before sort:      ";
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
    
    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i) {
        
        std::cout << "v[i] is " << *i << std::endl;
        auto p = std::upper_bound( v.begin(), i, *i );
        std::cout << "Upper bound is " << *p << std::endl;
        std::rotate(p, i, i+1);
        std::cout << "after rotate:      ";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';
    }
    
    std::cout << "after sort:       ";
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
    
    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 1, v.end());
    
    std::cout << "simple rotate left  : ";
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
    
    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    
    std::cout << "simple rotate right : ";
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
    
}


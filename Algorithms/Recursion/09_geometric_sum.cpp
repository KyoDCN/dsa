#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double geometric_sum(int n) {
    if(n == 0) return 1;

    return (1.0/pow(2,n)) + geometric_sum(n-1); 
}

int main() {
    int input = 5;
    cout << "Geometric Sums of " << input << " is " << geometric_sum(input);
    return 0;
}
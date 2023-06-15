#include<iostream>

using namespace std;

int multiply(int m, int n) {
    if(n == 0) return 0;

    return m + multiply(m, n-1);
}

int main() {
    int m = 6;
    int n = 7;

    cout << m << " x " << n << " = " << multiply(m,n);
    return 0;
}
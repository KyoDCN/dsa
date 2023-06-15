#include<iostream>

using namespace std;

int power(int a, int n) {
    if(n == 0) return 1;

    return a * power(a, n-1);
}

int main() {
    int input = 3;
    int e = 3;

    cout << input << "^" << e << " is " << power(input, e);
    return 0;
}
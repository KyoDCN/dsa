#include<iostream>

using namespace std;

int factorial(int n) {
    if(n == 0) return 1;

    return n * factorial(n-1);
}

int main() {
    int input = 5;
    cout << "factorial of " << input << " is " << factorial(input);

    return 0;
}
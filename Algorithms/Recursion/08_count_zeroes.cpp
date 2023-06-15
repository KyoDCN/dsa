#include<iostream>

using namespace std;

int count_zeroes(int n) {
    if(n == 0) return 0;

    return (n % 10 == 0 ? 1 : 0) + count_zeroes(n / 10);
}

int main() {
    int input = 10001010;

    cout << "The number of zeroes in the input is " << count_zeroes(input);

    return 0;
}
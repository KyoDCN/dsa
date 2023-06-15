#include<iostream>

using namespace std;

int count_digits(int n) {
    if(n < 10) return 1;

    return 1 + count_digits(n / 10);
}

int main() {
    int input = 12345;
    cout << "Number of digits in " << input << " is " << count_digits(input);
    return 0;
}
#include<iostream>

using namespace std;

int sum_of_digits(int n) {
    if(n < 10) return n;

    // 1234 *5*
    int digit = n % 10;

    // *1234* 5
    return digit + sum_of_digits(n / 10);
}

int main() {
    int input = 12345;
    cout << "Sum of digits for " << input << " is " << sum_of_digits(input);
    return 0;
}
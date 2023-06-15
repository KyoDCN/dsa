#include<iostream>
#include<vector>

using namespace std;

int fibonacci(int n, vector<unsigned long long>& m) {
    if(n == 0 || n == 1) return n;

    if(m[n] > 1) {
        return m[n];
    } else {
        m[n] = fibonacci(n-1, m) + fibonacci(n-2, m);
        return m[n];
    } 
}

int main() {
    int input = 73;
    vector<unsigned long long> m(input+1, 0);

    cout << "Fibonacci number with " << input << " sequence is " << fibonacci(input, m);

    return 0;
}
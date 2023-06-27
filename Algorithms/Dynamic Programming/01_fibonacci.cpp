#include<iostream>
#include<vector>

using namespace std;

int fib(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;

    return fib(n-1) + fib(n-2);
}

int fib_dp(int n) {
    int a[n]{0,1};

    for(int i=2; i<n; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n-1];
}

int fib_dp2(int n) {
    int a[]{0,1};

    int i = 2;
    while(i <= n) {
        a[i % 2] = a[0] + a[1]; 
        i++;
    }

    return a[i % 2];
}

int main() {
    int n = 13;
    cout << fib_dp(n);
    cout << endl;
    cout << fib(n);
    cout << endl;
    cout << fib_dp2(n);
    return 0;
}
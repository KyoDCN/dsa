#include<iostream>

using namespace std;

/*
    How many different ways to reach top of the stairs with
    a combination of one step and two steps?
*/

int stairclimb(int n) {
    if(n == 0 || n == 1) return 1;

    return stairclimb(n-1) + stairclimb(n-2);
}

int stairclimb_dp(int n) {
    int a[n+1];

    for(int i=0; i<=n; i++) {
        if(i == 0 || i == 1) {
            a[i] = 1;
            continue;
        }

        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}

int stairclimb_dp2(int n) {
    int a[2];

    int i = 0;
    while(i <= n) {
        if(i == 0 || i == 1)
            a[i] = 1;
        else
            a[i % 2] = a[0] + a[1];
        i++;
    }

    return a[(i-1) % 2];
}

int main() {
    cout << stairclimb(20);
    cout << endl;
    cout << stairclimb_dp(20);
    cout << endl;
    cout << stairclimb_dp2(20);
    return 0;
}
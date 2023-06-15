#include<iostream>
#include<vector>

using namespace std;

// Number of ways to reach top of the staircase
// Can take 1 step, 2 steps, or 3 steps

int staircase(int n, vector<int>& m) {
    if(n == 0) return 1;
    if(n < 0) return 0;

    if(m[n] > 0) {
        return m[n];
    } else {
        m[n] = staircase(n-1, m) + staircase(n-2, m) + staircase(n-3, m);
        return m[n];
    }
}

int staircase(int n) {
    vector<int> m(n+1);

    for(int i=0; i<=n; i++) {
        if(i == 0) {
            m[i] = 1;
        } else {
            // n = f(n-1) + f(n-2) + f(n-3);
            m[i] = m[i-1] + (i>=2 ? m[i-2] : 0) + (i>=3 ? m[i-3] : 0);
        }
    }

    return m[n];
}

int main() {
    int input = 50;
    vector<int> m(input+1, 0);
    cout << staircase(input, m);
    cout << endl;
    cout << staircase(input);
    return 0;
}
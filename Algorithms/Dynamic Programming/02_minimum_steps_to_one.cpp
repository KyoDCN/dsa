#include<iostream>

using namespace std;

int min_steps(int n) {
    if(n == 1) return 0;

    int min_steps_int{0};

    min_steps_int = min_steps(n-1);

    if(n % 2 == 0) {
        int steps = min_steps(n/2);
        min_steps_int = min(min_steps_int, steps);
    }

    if(n % 3 == 0) {
        int steps = min_steps(n/3);
        min_steps_int = min(min_steps_int, steps);
    }

    return min_steps_int + 1;
}

int min_steps_dp(int n, int a[]) {
    if(n == 1) return 0;

    int min_steps_value{0};

    if(a[n-1] == -1)
        a[n-1] = min_steps_dp(n-1, a);

    min_steps_value = a[n-1];
        
    if(n % 2 == 0) {
        if(a[n/2] == -1)
            a[n/2] = min_steps_dp(n/2, a);

        min_steps_value = min(min_steps_value, a[n/2]);
    }

    if(n % 3 == 0) {
        if(a[n/3] == -1)
            a[n/3] = min_steps_dp(n/3, a);

        min_steps_value = min(min_steps_value, a[n/3]);
    }

    a[n] = min_steps_value + 1;

    return a[n];
}
int min_steps_dp(int n) {
    int a[n+1];
    for(int& i : a) {
        i = -1;
    }

    return min_steps_dp(n, a);
}

int min_steps_dp_bottomup(int n) {
    int a[n+1];
    for(auto& i : a) {
        i = INT_MAX;
    }

    for(int i=0; i<=n; i++) {
        if(i == 0 || i == 1) {
            a[i] = 0;
            continue;
        }
        
        a[i] = min(a[i], a[i-1]);

        if(i % 3 == 0)
            a[i] = min(a[i], a[i/3]);
        
        if(i % 2 == 0)
            a[i] = min(a[i], a[i/2]);

        a[i] += 1;
    }

    return a[n];
}

int main() {
    int n = 100000;
    // cout << min_steps(n);
    // cout << endl;
    // cout << min_steps_dp(n);
    // cout << endl;
    cout << min_steps_dp_bottomup(n);
    return 0;
}
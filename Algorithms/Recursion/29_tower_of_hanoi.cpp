#include<iostream>
#include<vector>

using namespace std;

// Recursion with disk movement steps
int tower_of_hanoi(int n, char s, char d, char h) {
    if(n == 0) return 0;

    int output{0};

    // A to B (Source to Helper)
    output += tower_of_hanoi(n-1, s, h, d);

    cout << "Disk " << n << " from " << s << " to " << d << endl;
    
    // B to C (Helper to Destination)
    output += tower_of_hanoi(n-1, h, d, s);
    
    // A to C (Source to Destination)
    return output + 1;
}

// Naive Recursion
int tower_of_hanoi(int n) {
    if(n == 0) return 0;
    return tower_of_hanoi(n-1) + tower_of_hanoi(n-1) + 1;
}

// Dynamic Programming implementation
int tower_of_hanoi_dp(int n) {
    vector<int> m(n+1);

    for(int i=0; i<=n; i++) {
        if(i == 0) {
            m[i] = 0;
        } else {
            m[i] = m[i-1] + m[i-1] + 1;
        }
    }
    
    return m[n];
}

int main() {
    int n = 15;
    cout << tower_of_hanoi(n, 'A', 'C', 'B');
    cout << endl;
    cout << tower_of_hanoi(n);
    cout << endl;
    cout << tower_of_hanoi_dp(n);
    return 0;
}
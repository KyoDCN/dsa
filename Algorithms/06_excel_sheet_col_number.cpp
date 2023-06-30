#include<iostream>

using namespace std;

int alpha_to_integer(string s) {
    return s[s.size()-1] - 'A' + 1;
}

long long prefix_to_integer(string title) {
    int result{0};
    int n = title.size()-1;

    for(int i=1; i<=n; i++) {
        long long power{1};
        for(int j=0; j<i; j++) {
            power *= 26;
        }
        result += power;
    }

    return result;
}

int main() {
    string title = "AA";
    
    cout << prefix_to_integer(title) + alpha_to_integer(title);
    return 0;
}
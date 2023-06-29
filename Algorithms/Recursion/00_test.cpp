#include<iostream>

using namespace std;

void permutation(string s, int i) {
    if(s[i] == '\0') {
        cout << s << endl;
        return;
    };
    
    for(int j=i; s[j] != '\0'; j++) {
        swap(s[i], s[j]);
        permutation(s, i+1);
    }
}

int main() {
    string s{"abcd"};

    permutation(s, 0);
    return 0;
}
#include<iostream>

using namespace std;

void print(string& s, int i) {
    if(s[i] == '\0') return;

    cout << s[i];

    print(s, i+1);
}

void reverse_print(string& s, int i) {
    if(i == -1) return;

    cout << s[i];

    reverse_print(s, i-1);
}

void reverse_print2(string& s, int i) {
    if(s[i] == '\0') return;

    reverse_print2(s, i+1);

    cout << s[i];
}

int main() {
    string s = "There is no spoon";

    print(s,0);
    cout << endl;
    reverse_print(s,s.length()-1);
    cout << endl;
    reverse_print2(s,0);
}
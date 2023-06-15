#include<iostream>

using namespace std;

int stoi(string s, int output) {
    if(s.empty()) {
        return output;
    }

    int digit = s[0] - '0';
    output = (output*10) + digit;
    
    return stoi(s.substr(1), output);
}

int stoi(char a[], int output) {
    if(a[0] == '\0') {
        return output;
    }

    int digit = a[0] - '0';
    output = (output*10) + digit;

    return stoi(a+1, output);
}

int main() {
    char s[]{"1234"};
    int output;
    cout << stoi(s, output);

    return 0;
}
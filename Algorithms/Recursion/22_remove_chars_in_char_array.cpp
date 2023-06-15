#include<iostream>

using namespace std;

void left_shift(char a[]) {
    if(a[0] == '\0') return;

    a[0] = a[1];

    left_shift(a+1);
}

void remove_char(char c, char a[]) {
    if(a[0] == '\0') return;

    if(a[0] == c) {
        left_shift(a);
        remove_char(c, a);
    } else {
        remove_char(c, a+1);
    }
}

int main() {
    char a[]{"There is no spoon"};

    cout << a << endl;
    
    remove_char('o', a);

    cout << a << endl;
}
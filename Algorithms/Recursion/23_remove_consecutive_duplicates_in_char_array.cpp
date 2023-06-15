#include<iostream>

using namespace std;

void left_shift(char a[]) {
    if(a[0] == '\0') return;

    a[0] = a[1];

    left_shift(a+1);
}

void remove_duplicates(char a[]) {
    if(a[0] == '\0') return;

    if(a[0] == a[1]) {
        left_shift(a);
        remove_duplicates(a);
    } else {
        remove_duplicates(a+1);
    }
}

int main() {
    char a[]{"Good bacoon is mooooooo"};
    remove_duplicates(a);
    cout << a;
    return 0;
}
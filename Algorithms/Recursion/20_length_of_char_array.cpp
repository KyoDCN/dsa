#include<iostream>

using namespace std;

int length(char a[]) {
    if(a[0] == '\0') return 0;

    return 1 + length(a+1);
}

int main() {
    char a[]{"there is no spoon"};
    cout << "Length of \"" << a << "\" is " << length(a);
    
    return 0;
}
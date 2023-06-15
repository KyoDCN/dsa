#include<iostream>

using namespace std;

int main() {
    char a[]{"abcd"};

    for(int i=0; a[i] != '\0'; i++) {
        for(int j=0; j<=i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
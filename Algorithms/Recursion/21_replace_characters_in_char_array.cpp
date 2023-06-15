#include<iostream>

using namespace std;

void replace(char c, char r, char a[]) {
    if(a[0] == '\0') return;

    if(a[0] == c) {
        a[0] = r;
    }

    replace(c, r, a+1);
}

int main() {
    char c[]{"There is no spoon"};
    char key = 'e';
    char r = 'x';

    cout << "\"" << c << "\" has " << key << " replaced with " << r << endl;
    replace(key,r,c);
    cout << c;

    return 0;
}
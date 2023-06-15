#include<iostream>

using namespace std;

void swap_custom(int& i1, int& i2) {
    int temp = i1;
    i1 = i2;
    i2 = temp;
}

int main() {
    int a[] {1,2,3,4,5};

    swap_custom(a[1], a[4]);

    for(int x : a) {
        cout << x << " ";
    }

    return 0;
}
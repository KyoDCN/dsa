#include<iostream>

using namespace std;

int main() {
    int a[]{1,2,3,4,5};
    int s = 0;
    int e = 4;
    
    while(s < e) {
        swap(a[s], a[e]);
        s++;
        e--;
    }

    for(int x : a) {
        cout << x << " ";
    }
}
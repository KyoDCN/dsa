#include<iostream>

using namespace std;

int main() {
    int a[]{1,2,3,4,5};

    int sum;
    for(int x : a) {
        sum += x;
    }

    cout << sum;
}
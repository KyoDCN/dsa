#include<iostream>

using namespace std;

int main() {
    int a[]{6,2,10,4,3,9,1};

    int largest{INT_MIN};
    for(int x : a) {
        largest = max(largest, x);
    }

    cout << largest;
    return 0;
}
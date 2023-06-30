#include<iostream>

using namespace std;

void fizzbuzz(int n, int i) {
    if(i > n) return;

    if(i % 3 > 0 && i % 5 > 0) {
        cout << i << " ";
    } else {
        string fizzbuzz{""};
        if(i % 3 == 0) fizzbuzz += "fizz";
        if(i % 5 == 0) fizzbuzz += "buzz";
        cout << fizzbuzz << " ";
    }

    fizzbuzz(n, i+1);
}

int main() {
    fizzbuzz(50, 1);
}
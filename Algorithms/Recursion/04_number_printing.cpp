#include<iostream>

using namespace std;

void number_print(int n) {
    if(n == 0) return;

    number_print(n-1);

    cout << n << " ";
}

int main() {
    number_print(10);
    return 0;
}
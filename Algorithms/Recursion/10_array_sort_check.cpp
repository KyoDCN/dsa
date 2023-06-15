#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int> a, int i) {
    if(i == 0) return true;

    if(a[i] < a[i-1]) return false;

    return isSorted(a, i-1);
}

int main() {
    vector<int> a{1,2,3,7,4,5,6};
    cout << boolalpha << isSorted(a, a.size()-1);

    return 0;
}
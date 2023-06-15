#include<iostream>
#include<vector>

using namespace std;

int findFirst(int key, int i, vector<int> a) {
    if(i == a.size()) return -1;

    if(key == a[i]) return i;

    return findFirst(key, i+1, a);
}

int main() {
    vector<int> a{1,2,3,4,5,4,6,4,7,8,9,10};
    int key = 4;

    cout << "First index of key " << key << " is " << findFirst(key, 0, a);

    return 0;
}
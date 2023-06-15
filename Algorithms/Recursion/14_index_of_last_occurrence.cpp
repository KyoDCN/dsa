#include<iostream>
#include<vector>

using namespace std;

int findLast(int key, int i, vector<int> a) {
    if(i == -1) return -1;

    if(key == a[i]) return i;

    return findLast(key, i-1, a);
}

int main() {
    vector<int> a{1,2,3,4,5,4,6,4,7,8,9,10};
    int key = 4;

    cout << "Last index of key " << key << " is " << findLast(key, a.size()-1, a);

    return 0;
}
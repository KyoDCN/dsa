#include<iostream>
#include<vector>

using namespace std;

int binary_search(int key, vector<int> a, int s, int e, int i, bool isFirst) {
    if(s > e) return i;

    int m = ((e-s)/2)+s; // Mid Index

    if(a[m] == key) {
        i = m;
        if(isFirst) {
            // First Occurrence
            return binary_search(key, a, s, m-1, i, isFirst);
        } else {
            // Last Occurrence
            return binary_search(key, a, m+1, e, i, isFirst);
        }
    } else if (key < a[m]) {
        return binary_search(key, a, s, m-1, i, isFirst);
    } else {
        return binary_search(key, a, m+1, e, i, isFirst);
    }
}

int main() {
    vector<int> a{1,2,2,3,3,3,4,4,4,4,5,5,5,5};
    cout << binary_search(3, a, 0, a.size()-1, -1, false);

    return 0;
}
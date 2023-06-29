#include<iostream>
#include<vector>

using namespace std;

/*
    Binary Search that deals with rotated array.
    This is useful where we do deletions and insertions of O(1),
    where deletion and insertion is simply moving indexers instead of
    physically altering the value in the array
*/

int binary_search(int key, vector<int> a, int s, int e) {
    if(s > e) return -1;

    int m = ((e-s)/2)+s;

    if(key == a[m]) return m;

    if(a[s] <= a[m]) { // Check if start index is less than mid index
        if(a[s] <= key && key <= a[m]) { // Check if Key is between start and mid
            return binary_search(key, a, s, m-1);
        } else { // Mid to End is rotated around
            return binary_search(key, a, m+1, e);
        }
    } else if (a[m] <= a[e]) { // Check if end index is greater than mid index
        if(a[m] <= key && key <= a[e]) { //  Check if key is between mid and end
            return binary_search(key, a, m+1, e);
        } else { // Start to mid is rotated around
            return binary_search(key, a, s, m-1);
        }
    }

    return m;
}

int main() {
    vector<int> a{6,7,8,9,10,1,2,3,4,5};
    for(auto x : a) {
        cout << "index of " << x << " is: " << binary_search(x, a, 0, a.size()-1) << endl;
    }
    //int key = 3;
    //cout << "index of " << key << " is: " << binary_search(key, a, 0, a.size()-1);

    return 0;
}
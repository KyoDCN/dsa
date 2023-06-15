#include<iostream>
#include<vector>

using namespace std;

int binary_search(int key, vector<int> a, int s, int e) {
    if(s > e) return -1;

    int m = ((e-s)/2)+s;

    if(key == a[m]) return m;

    if(a[s] <= a[m]) { // Check if start is less than mid
        if(a[s] <= key && key <= a[m]) { // Check if Key is between start and mid
            return binary_search(key, a, s, m-1);
        } else {
            return binary_search(key, a, m+1, e);
        }
    } else if (a[m] <= a[e]) { // Check if mid is less than end
        if(a[m] <= key && key <= a[e]) { //  Check if key is between mid and end
            return binary_search(key, a, m+1, e);
        } else {
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
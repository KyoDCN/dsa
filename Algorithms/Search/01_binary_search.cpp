#include<iostream>
#include<vector>

using namespace std;

int binary_search(int key, vector<int> a) {
    int s=0;
    int e=a.size()-1;
    int mid_index;

    while(s <= e) {
        mid_index = ((e-s)/2)+s;

        if(a[mid_index] == key) {
            return mid_index;
        } else if (key < a[mid_index]) {
            e = mid_index-1;
        } else if (key > a[mid_index]) {
            s = mid_index+1;
        }
    }

    return -1;
}

int main() {
    vector<int> a{1,2,3,4,5,6,7,8,9,10}; 
    int key = 7;
    cout << "index of " << key << " is: " << binary_search(key, a);

    return 0;
}
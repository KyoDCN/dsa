#include<iostream>
#include<vector>

using namespace std;

/*
    BINARY SEARCH WITH DUPLICATE VALUES

    Basically, even if we find the match, we keep going until the start and end index cross.
    We then return the ith index value if the first or last occurrence. If not found, it simply
    returns a default value of -1.
*/

int binary_search(int key, int start_index, int end_index, vector<int> a, int i, bool isFirst) {
    if(start_index > end_index) return i;

    int mid_index = ((end_index-start_index)/2)+start_index; // Mid Index

    if(a[mid_index] == key) {
        i = mid_index;
        if(isFirst) {
            // First Occurrence
            return binary_search(key, start_index, mid_index-1, a, i, isFirst);
        } else {
            // Last Occurrence
            return binary_search(key, mid_index+1, end_index, a, i, isFirst);
        }
    } else if (key < a[mid_index]) {
        // start_index <-> mid_index - 1
        return binary_search(key, start_index, mid_index-1, a, i, isFirst);
    } else if (key > a[mid_index]) {
        // mid_index + 1 <-> end_index
        return binary_search(key, mid_index+1, end_index, a, i, isFirst);
    }
}

int main() {
    vector<int> a{1,2,2,3,3,3,4,4,4,4,5,5,5,5};
    cout << binary_search(3, 0, a.size()-1, a, -1, false);

    return 0;
}
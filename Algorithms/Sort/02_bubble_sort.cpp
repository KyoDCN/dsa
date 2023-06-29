#include<iostream>
#include<vector>

using namespace std;

/*
    BUBBLE SORT

    Swap a[i] and a[i+1], and repeat the cycle from index 0 until everything is sorted.
    The while loop will break once no more swap is performed.
*/

void bubble_sort(vector<int>& a) {
    bool sorted{false};
    
    while(sorted == false) {
        sorted = true;

        for(int i=0; i<a.size()-1; i++) {
            if(a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                sorted = false;
            }
        }
    }
}

int main() {
    vector<int> a{5,1,9,2,8,3,7,4,6};

    bubble_sort(a);

    for(auto x : a) {
        cout << x << " ";
    }

    return 0;
}
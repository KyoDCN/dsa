#include<iostream>
#include<vector>

using namespace std;

/*
    Moore's Vote

    Determines the majority element of an array using a +/- voting system. 
    More space efficient than using a separate data structure to store 
    character occurrence count.
    
    This will only work, however, if the element comprises more than 50%
    of elements in the entire array.
*/

int moore_vote(vector<int> a) {
    int element = a[0];
    int i = 1;
    int vote = 1;

    while(i < a.size()) {
        // Checks to see if current value == current element
        if(a[i] == element) {
            vote++;
        } else {
            vote--;
        }

        // If vote == 0, set element to new value
        if(vote == 0) {
            element = a[i];
            vote = 1;
        }

        i++;
    }

    // Check to see if the element makes up more than 50% of total
    int count_check{0};
    for(int e : a) {
        if(e == element) {
            count_check++;
            if(count_check > (a.size()/2)) {
                return element;
            }
        }
    }

    return -1;
}

int main() {
    return 0;
}
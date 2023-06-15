#include<iostream>
#include<vector>

using namespace std;

int sum_of_array(vector<int> a, int i) {
    if(i == 0) return a[0];

    return a[i] + sum_of_array(a, i-1);
}

int sum_of_array2(int a[], int i) {
    if(i == 0) return 0;

    return a[0] + sum_of_array2(a+1, i-1);
}

int main() {
    vector<int> a{1,2,3,4,5};
    int b[]{1,2,3,4,5};

    cout << "Total sum of the array is " << sum_of_array(a, a.size()-1);
    cout << "\n";
    cout << "Total sum of the array is " << sum_of_array2(b, 5);

    return 0;
}
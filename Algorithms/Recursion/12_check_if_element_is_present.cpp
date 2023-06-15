#include<iostream>
#include<vector>

using namespace std;

bool isExist(int key, int i, const vector<int>& a) {
    if(i == -1) return false;

    if(key == a[i]) return true;
    
    return isExist(key, i-1, a);
}

int main() {
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    int input = 3;

    cout << "The key value " << input << " exists: " << boolalpha << isExist(input, a.size()-1, a);

    return 0;
}
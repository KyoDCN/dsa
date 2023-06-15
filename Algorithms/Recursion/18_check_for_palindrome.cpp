#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string input, int s, int e) {
    if(s > e) return true;

    if(input[s] != input[e]) return false;

    return isPalindrome(input, s+1, e-1);
}

int main() {
    string s = "abbaxnabba";
    cout << s << " is a palindrome? " << boolalpha << isPalindrome(s, 0, s.length()-1);
    return 0;
}
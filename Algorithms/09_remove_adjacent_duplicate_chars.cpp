#include<iostream>
#include<stack>

using namespace std;

string remove_adj_dup(string a) {
    stack<char> s;

    for(auto x : a) {
        if(!s.empty() && tolower(x) == tolower(s.top())) {
            s.pop();
        } else {
            s.push(x);
        }
    }
        
    string ans;
    while(!s.empty()) {
        ans = s.top() + ans;
        s.pop();
    }

    return ans;
}

// Time and space efficient version - O(N) time and O(1) space
string remove_adj_dup_v2(string a) {
    string result(a.size(), ' ');

    size_t stack_ptr{0};
    result[stack_ptr] = a[0];

    for(size_t i=1; i<a.size(); i++) {
        if(tolower(a[i]) == tolower(result[stack_ptr])) {
            stack_ptr--; // Pseudo stack pop
        } else {
            stack_ptr++; // Pseudo stack push
            result[stack_ptr] = a[i];
        }
    }

    // Return the string with only the portion we need
    return result.substr(0, stack_ptr+1);
}

int main() {
    cout << remove_adj_dup_v2("Mississippi");

    return 0;
}
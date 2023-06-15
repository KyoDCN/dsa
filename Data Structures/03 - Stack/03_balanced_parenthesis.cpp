#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool isBalanced(vector<string> a) {
    stack<string> s;

    for(auto x : a) {
        if(x == "{" || x == "(" || x == "[") {
            s.push(x);
        } else {
            if(s.empty()) return false; 
            // We can't compare if stack is empty, so auto false
            // This implies that the there were no preceding opening brackets pushed to the stack.

            if(x == "}") {
                if(s.top() != "{") return false;
                s.pop();
            } else if(x == ")") {
                if(s.top() != "(") return false;
                s.pop();
            } else if(x == ")") {
                if(s.top() != "(") return false;
                s.pop();
            }
        }
    }

    return s.empty() ? true : false;
}

int main() {
    vector<string> a{")","(",")","(","(",")"};
    cout << boolalpha << isBalanced(a);
    return 0;
}
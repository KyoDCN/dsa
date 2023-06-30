#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

bool isOperator(string o) {
    return o == "+" || o == "-" || o == "*" || o == "/";
}

int evaluate(int operand1, int operand2, string operator_c) {
    if(operator_c == "+") {
        return operand2 + operand1;
    }
    if(operator_c == "-") {
        return operand2 - operand1;
    }
    if(operator_c == "*") {
        return operand2 * operand1;
    }
    if(operator_c == "/") {
        return operand2 / operand1;
    }
}

int reverse_polish_notation(vector<string> a) {
    stack<int> s;

    for(int i=0; i<a.size(); i++) {
        if(isOperator(a[i])) {
            int operand1 = s.top();
            s.pop();

            int operand2 = s.top();
            s.pop();

            s.push(evaluate(operand1, operand2, a[i]));
        } else {
            s.push(atoi(a[i].c_str()));
        }
    }

    if(s.size() > 1) return -1;

    return s.top();
}

int main() {
    vector<string> a{"2","2","+","2","*","2","3","/","-"};
    cout << reverse_polish_notation(a);
    return 0;
}
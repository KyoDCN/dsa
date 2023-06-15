#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<string> input{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
vector<string> input2{"4","13","5","/","+"};

int evaluate(vector<string> input) {
    stack<int> operands;

    for(auto x : input) {
        if(x == "+" || x == "-" || x == "*" || x == "/") {
            int operand1 = operands.top();
            operands.pop();

            int operand2 = operands.top();
            operands.pop();

            if(x == "+") {
                operands.push(operand2 + operand1);
            } else if (x == "-") {
                operands.push(operand2 - operand1);
            } else if (x == "*") {
                operands.push(operand2 * operand1);
            } else if (x == "/") {
                operands.push(operand2 / operand1);
            }
        } else {
            operands.push(atoi(x.c_str()));
        }
    }

    return operands.top();
}

int main() {
    cout << evaluate(input2) << endl;

    return 0;
}
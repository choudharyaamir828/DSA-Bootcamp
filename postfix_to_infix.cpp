#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string postfixToInfix(const string& postfix) {
    stack<string> s;

    for (char ch : postfix) {
        if (isalpha(ch)){ 
            s.push(string(1, ch));
        } 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){ 
            string right = s.top(); s.pop();
            string left = s.top(); s.pop();
            string expr = "(" + left + ch + right + ")";
            s.push(expr);
        }
    }

    // final element
    return s.top();
}

int main() {
    string postfixExpression;
    
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;
    
    string ans = postfixToInfix(postfixExpression);
    
    cout << "The ans is : " << ans << endl;
    
    return 0;
}

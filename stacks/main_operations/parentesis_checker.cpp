#include <iostream>
#include <stack>
using namespace std;

class ParenthesisChecker {
public:
    // Function to check if the given expression has balanced parentheses
    bool isBalanced(const string& expression) {
        stack<char> st;

        for (char ch : expression) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // If it's a closing bracket, check for a matching opening bracket
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) return false; // No opening bracket to match
                
                char top = st.top();
                st.pop();

                // Check if the popped bracket matches the current closing bracket
                if ((ch == ')' && top != '(') || 
                    (ch == '}' && top != '{') || 
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets are matched
        return st.empty();
    }
};

// Driver function
int main() {
    ParenthesisChecker checker;

    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (checker.isBalanced(expression))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

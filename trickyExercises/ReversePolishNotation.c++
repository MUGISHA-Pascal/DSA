#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE 100  // Define a maximum stack size

// Custom Stack Class
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
    
public:
    Stack() : top(-1) {}
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    
    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }
    
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }
    
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to apply the operator on two operands
int applyOperator(int operand1, int operand2, char op) {
    switch(op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate the RPN expression
int evaluateRPN(const char* expression) {
    Stack stack;
    int i = 0;
    
    while (expression[i] != '\0') {
        char token = expression[i];
        
        if (token == ' ' || token == '\t') {
            // Skip spaces or tabs
            i++;
            continue;
        }
        
        if (isOperator(token)) {
            // It's an operator, pop two operands and apply the operator
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = applyOperator(operand1, operand2, token);
            stack.push(result);
        } else if (token >= '0' && token <= '9') {
            // It's a number, parse it and push to the stack
            int num = 0;
            while (token >= '0' && token <= '9') {
                num = num * 10 + (token - '0');
                i++;
                token = expression[i];
            }
            stack.push(num);
            continue; // Skip the increment of i since it's already handled
        }
        
        i++;
    }
    
    // The final result should be the only element in the stack
    return stack.peek();
}

int main() {
    char expression[100];
    cout << "Enter an RPN expression: ";
    cin.getline(expression, 100);
    
    int result = evaluateRPN(expression);
    cout << "Result: " << result << endl;
    
    return 0;
}

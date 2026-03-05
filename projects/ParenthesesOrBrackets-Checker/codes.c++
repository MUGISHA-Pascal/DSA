#include <iostream>

using namespace std;

#define MAX 100

class Stack{
    private:
    char arr[MAX];
    int top;
    public:
    Stack(){top=-1}

    void push(char c){
        if(top>=MAX){
            cout<<"Stack Overflow!\n";
            return;
        }
        arr[++top]=c;
    }

    char pop(){
        if(top == -1){
            return '\0';
        }
        return arr[top--];
    }

    char peek(){
        if(top == -1)return'\0';
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isMatching(char open,char close){
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool areBracketsBalanced(string expr){
    Stack stack;
    for(char c : expr){
        if(c == '(' || c == '[' || c == '{'){
            stack.push(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if (stack.isEmpty()) return false;
            char topChar = stack.pop();
            if(!isMatching(topChar,c)) return false;
        }
    }
    return stack.isEmpty();
}

int main(){
    string expression;
    cout << "Enter an expression with brackets: ";
    getline(cin,expression);
    if(areBracketsBalanced(expression)){
        cout <<"Brackets are balanced!\n";
    }else{
        cout<<"Brackers are not balanced!\n";
    }
    return 0;
}

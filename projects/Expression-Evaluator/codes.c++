#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define MAX 100

class ValueStack{
    private:
    double arr[MAX];
    int top;
    public:
    ValueStack(){top = -1;}

    void push(double val){
        arr[++top] = val;
    }

    double pop(){
        return arr[top--];
    }

    double peek(){
        return arr[top];
    }

    bool isEmpty(){
        return top == -1
    }
};

class OperatorStack{
    private:
    char arr[MAX];
    int top;
    public:
    OperatorStack(){top=-1;}
    
    void push(char op){
        arr[++top] = op;
    }

    void pop(){
        return arr[top--];
    }

    char peek(){
        return arr[top];
    }

    bool isEmpty(){
        return top == -1
    }
};

int precedence(char op){
    if(op == '+' || op == '-')return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation(double a,double b, char op){
    switch(op){
        case '+' :return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
    return 0;
}

double evaluate(string expr){
    ValueStack values;
    OperatorStack ops;
    for(int i=0;i<expr.length(); i++){
        if(expr[i] == ' ')continue;
        if(isdigit(expr[i])){
            double num = 0;
            while(i<expr.length()&&isdigit(exp[i])){
                num = num * 10 + (expr[i] - '0');
                i++
            }
            values.push(num);
            i--;
        }else if(expr[i] == '('){
            ops.push(expr[i]);
        }else if(expr[i] == ')'){
            while (ops.peek() != '('){
                double val2=values.pop();
                double val1=values.pop();
                char op = ops.pop();
                values.push(applyOperation(val1,val2,op));
            }
            ops.push(expr[i]);
        }
        while (!ops.isEmpty()){
            double val2 = values.pop();
            double val1 = values.pop();

            values.push(applyOperation(val1,val2,op));
        }
        return values.pop();
    };
}

int main(){
    string expression;
    cout <<"Enter an expression: ";
    getline(cin,expression);
    double result = evaluate(expression);
    cout <<"Result = "<<result <<endl;
    return 0;
}
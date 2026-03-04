#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

class Stack{
    private:
    vector<double> arr;
    public:
    void push(double num){arr.push_back(num);}
    double pop(){
        if(arr.empty()) return 0;
        double val = arr.back();
        arr.pop_back();
        return val;
    }
    bool isEmpty(){return arr.empty();}
    double peek(){return arr.back();}
};

bool isNumber(const string &s){
    for(char c : s){
        if(!isdigit(c) && c!=".") return false;
    }
    return true;
}

double evaluateRPN(string expression){
    Stack stack;
    stringstream ss(expression);
    string token;
    while(ss>>token){
        if(isNumber(token)){
            stack.push(stod(token));
        }else{
            double b=stack.pop();
            double a=stack.pop();
            if(token == "+") stack.push(a+b);
            else if (token == "-") stack.push(a-b);
            else if (token == "*") stack.push(a*b);
            else if (token == "/") stack.push(a/b);
            else{
                cout<<"Unknown operator: "<<token<<endl;
                return 0;
            }
        }
    }
    return stack.pop();
}

int main(){
    string expression;
    cout<<"Stack-Based Calculator (RPN)\n";
    cout<<"Enter expression in RPN (e.g., 3 4 + 2 *):";
    getline(cin,expression);
    double result = evaluateRPN(expression);
    cout <<"Result: "<<result<<endl;
    return 0;
}
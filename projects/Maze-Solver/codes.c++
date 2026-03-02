#include <iostream>
using namespace std;

#define ROWS 5
#define COLS 5
#define MAX 100

struct Position{
    int row;
    int col;
}

class Stack {
    private:
    Position arr[MAX];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(Position p){
        arr[++top]=p;
    }
    Position pop(){
        return arr[top--];
    }
    Position peek(){
        return arr[top];
    }
};

bool isValid(int row , int col,char maze[ROWS][COLS],bool visited[ROWS][COLS]){
    return(row>=0&&row<ROWS && col>=0&&col<COLS&&maze[row][col]!='#'&&!visited[row][col]);
}

void solveMaze(char maze[ROWS][COLS]){
    bool visited[ROWS][COLS]={false};
    Stack stack;
    Position start = {0,0};
    stack.push(start);
    visited[0][0]=true;
    while(!stack.isEmpty()){
        Position current = stack.peek();
        if(maze[current.row][current.col]=='E'){
            cout<<"Exit Found!\n";
            return;
        }
        bool moved=false;
        int dRow[]={1,0,-1,0};
        int dCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow =current.row+drow[i];
            int newCol =current.col+dCol[i];
            if(isValid(newRow,newCol,maze,visited)){
                Position next={newRow,newCol};
                stack.push(next);
                visited[newRow][newCol];
                moved=true;
                break;
            }
        }
        if(!moved){
            stack.pop();
        }
    }
    cout<<"No path found.\n";
}

int main(){
      char maze[ROWS][COLS] = {
        {'S', '.', '.', '#', '.'},
        {'#', '#', '.', '#', '.'},
        {'.', '.', '.', '.', '#'},
        {'.', '#', '#', '.', '.'},
        {'.', '.', '.', '#', 'E'}
    };
    solveMaze(maze);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class NullGraph{
    private:
         int vertices;
         vector<vector<int>> adjacencyMatrix;
    public:
         NullGraph(int n){
            vertices=n;
            adjacencyMatrix.resize(n,vector<int>(n,0));
         }
         void printGraph(){
            cout<<"Adjacency Matrix of Null Graph : \n";
            for(int i = 0 ; i<vertices;i++){
                for(int j=0; j<vertices ; j++){
                    cout<< adjacencyMatrix[i][j] <<" "; 
                }
                cout<<"\n";
            }
         }
         int getVertices(){
            return vertices;
         }
};
int main(){
    NullGraph g(5);
    cout<<"Created a Null Graph with "<<g.getVertices()<<" vertices \n";
    g.printGraph();
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class CompleteGraph{
    private:
        int vertices;
        vector<vector<int>> adjacencyMatrix;
    public:
        CompleteGraph(int n){
            vertices = n;
            adjacencyMatrix.resize(n,vector<int>(n,1));
            for(int i=0;i<n;i++){
                adjacencyMatrix[i][i]=0;
            }
        }
        void printGraph(){
            cout<<"Adjacency Matrix of Complete Graph : \n";
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                    cout<<adjacencyMatrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        int getEdgeCount(){
            return (vertices * (vertices - 1))/2;
        }
        int getVertices(){
            return vertices;
        }
};
int main(){
    CompleteGraph g(5);
    cout << "Created a Complete Graph with "<<g.getVertices()<<" vertices \n";
    cout<<"Number of edges : "<<g.getEdgeCount()<<"\n";
    g.printGraph();
        return 0;
}
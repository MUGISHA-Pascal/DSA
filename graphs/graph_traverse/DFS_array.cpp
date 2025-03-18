#include <iostream>
#include <vector>
using namespace std;
void printDFS(const vector<vector<int>> &v, int sv, vector<bool> &visited) {
    cout << sv << " ";
    visited[sv] = true;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (v[sv][i] == 1 && !visited[i]) {
            printDFS(v, i, visited);
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {  // Fixed loop index
        int fv, sv;
        cin >> fv >> sv;
        if (fv >= 0 && fv < n && sv >= 0 && sv < n) {  // Added validation check
            matrix[fv][sv] = 1;
            matrix[sv][fv] = 1;
        } else {
            cout << "Invalid edge input: " << fv << " " << sv << endl;
        }
    }
    cout << "DFS: ";
    vector<bool> visited(n, false);
    printDFS(matrix, 0, visited);
    cout << endl;  // Better output formatting
    return 0;
}
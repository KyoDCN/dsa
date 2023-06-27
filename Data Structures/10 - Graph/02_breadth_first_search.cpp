#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void print_BFS(int edgeValue, vector<vector<int>>& edges, vector<bool>& visited) {
    queue<int> q;
    
    q.push(edgeValue);
    visited[edgeValue] = true;

    while(!q.empty()) {
        int current_edge_value = q.front();
        cout << current_edge_value << " ";
        q.pop();

        for(int i=0; i<edges.size(); i++) {
            if(edges[current_edge_value][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Handle disconnected nodes
void print_BFS(vector<vector<int>>& edges) {
    vector<bool> visited(edges.size(), false);

    int num_components{0};
    for(int i=0; i<edges.size(); i++) {
        if(visited[i] == false) {
            print_BFS(i, edges, visited);
            num_components++;
        }
    }
}

int main() {
    vector<vector<int>> matrix(8);
    for(int i=0; i<matrix.size(); i++) {
        matrix[i] = vector<int>(matrix.size(),0);
    }

    matrix[0][2] = 1;
    matrix[0][4] = 1;
    matrix[2][0] = 1;
    matrix[2][3] = 1;
    matrix[2][4] = 1;
    matrix[3][2] = 1;
    matrix[4][0] = 1;
    matrix[4][2] = 1;

    matrix[1][5] = 1;
    matrix[5][1] = 1;

    matrix[6][7] = 1;
    matrix[7][6] = 1;

    print_BFS(matrix);
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Topological {
    vector<vector<int>> parents;
    vector<vector<int>> children;
    int num_vertices;
    void addEdge(int src_vertex, int dest_vertex);
public:
    void createEdges(vector<vector<int>> edges, int num_vertices);
    void sort();
};

void Topological::addEdge(int src_vertex, int dest_vertex) {
    this->parents[dest_vertex].push_back(src_vertex);
    this->children[src_vertex].push_back(dest_vertex);
}

void Topological::createEdges(vector<vector<int>> edges, int num_vertices) {
    this->num_vertices = num_vertices;
    this->parents.resize(num_vertices);
    this->children.resize(num_vertices);

    for(auto edge : edges) {
        addEdge(edge[0], edge[1]);
    }
}

void Topological::sort() {
    queue<int> q;
    vector<int> in_rank(this->num_vertices, 0);

    for(int i=0; i<num_vertices; i++) {
        in_rank[i] = parents[i].size();

        if(in_rank[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        cout << current_vertex << " ";

        for(int x : children[current_vertex]) {
            if(--in_rank[x] == 0) {
                q.push(x);
            }
        }
    }
}

int main() {
    Topological t;

    vector<vector<int>> edges{
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    t.createEdges(edges, 6);
    t.sort();

    return 0;
}
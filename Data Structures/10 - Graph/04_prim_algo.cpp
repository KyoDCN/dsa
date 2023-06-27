#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef int vertex_int;
typedef int weight_int;
typedef vector<pair<vertex_int, weight_int>> adjacent_vertex;
typedef vector<int> edge;

class Prim {
    vector<adjacent_vertex> adjacent_vertices;
    int num_vertices{0};
    void addAdjacentPair(vertex_int v_src, vertex_int v_dest, weight_int v_weight);
public:
    void createAdjacentPairs(const vector<edge>& edges, int num_vertices);
    void createMST(int starting_vertex);
};

void Prim::addAdjacentPair(vertex_int v_src, vertex_int v_dest, weight_int v_weight) {
    this->adjacent_vertices[v_src].push_back(make_pair(v_dest, v_weight));
    this->adjacent_vertices[v_dest].push_back(make_pair(v_src, v_weight));
}

void Prim::createAdjacentPairs(const vector<edge>& edges, int num_vertices) {
    this->num_vertices = num_vertices;
    this->adjacent_vertices.resize(num_vertices);

    for(edge e : edges) {
        addAdjacentPair(e[0], e[1], e[2]);
    }
}

void Prim::createMST(int starting_vertex = 0) {
    auto compare = [](const pair<vertex_int, weight_int>& A, const pair<vertex_int, weight_int>& B)
    {
        return A.second > B.second;
    };

    priority_queue<pair<vertex_int, weight_int>, vector<pair<vertex_int, weight_int>>, decltype(compare)> pq(compare);

    vector<vertex_int> parent(this->num_vertices, -1);
    vector<weight_int> labeled_edge_weight(this->num_vertices, INT_MAX);
    vector<bool> visited(this->num_vertices, false);

    pq.push(make_pair(starting_vertex, 0));
    labeled_edge_weight[starting_vertex] = 0;

    while(!pq.empty()) {
        int current_vertex = pq.top().first;
        pq.pop();

        if(visited[current_vertex]) continue;

        visited[current_vertex] = true;

        for(pair<vertex_int, weight_int> p : adjacent_vertices[current_vertex]) {
            int adj_vertex = p.first;
            int adj_weight = p.second;

            if(visited[adj_vertex] == false && adj_weight < labeled_edge_weight[adj_vertex]) {
                labeled_edge_weight[adj_vertex] = adj_weight;
                pq.push(make_pair(adj_vertex, adj_weight));
                parent[adj_vertex] = current_vertex;
            }
        }
    }

    for(int i=0; i<parent.size(); i++) {
        if(i != starting_vertex)
            cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    vector<vector<int>> edges{
        {0,1,4},
        {0,7,8},
        {1,2,8},
        {1,7,11},
        {2,3,7},
        {2,8,2},
        {2,5,4},
        {3,4,9},
        {3,5,14},
        {4,5,10},
        {5,6,2},
        {6,7,1},
        {6,8,6},
        {7,8,7},
    };

    Prim p;

    p.createAdjacentPairs(edges, 9);
    p.createMST(4);

    return 0;
}
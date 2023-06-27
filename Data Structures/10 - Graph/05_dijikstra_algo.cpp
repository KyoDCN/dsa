#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Dijikstra {
    vector<vector<pair<int, int>>> adjacent_vertices;
    int num_vertices{0};
    void addAdjacentVertices(int src_vertex, int dest_vertex, int distance);
public:
    void createAdjacentVertices(vector<vector<int>>& edges, int num_vertices);
    void createMST(int starting_vertex);
};

void Dijikstra::addAdjacentVertices(int src_vertex, int dest_vertex, int distance) {
    this->adjacent_vertices[src_vertex].push_back(make_pair(dest_vertex, distance));
    this->adjacent_vertices[dest_vertex].push_back(make_pair(src_vertex, distance));
}

void Dijikstra::createAdjacentVertices(vector<vector<int>>& edges, int num_vertices) {
    this->num_vertices = num_vertices;
    this->adjacent_vertices.resize(num_vertices);

    for(auto edge : edges) {
        addAdjacentVertices(edge[0], edge[1], edge[2]);
    }
}

void Dijikstra::createMST(int starting_vertex = 0) {
    auto cmp = [](const pair<int,int>& A, const pair<int,int>& B) {
        return A.second > B.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    vector<bool> visited(num_vertices, false);
    vector<int> labeled_distances(num_vertices, INT_MAX);

    pq.push(make_pair(starting_vertex, 0));
    labeled_distances[starting_vertex] = 0;

    while(!pq.empty()) {
        int current_vertex = pq.top().first;
        pq.pop();

        if(visited[current_vertex]) continue;

        visited[current_vertex] = true;

        for(auto vertex_pair : adjacent_vertices[current_vertex]) {
            int adjacent_vertex = vertex_pair.first;
            int adjacent_distance = vertex_pair.second;

            if(visited[adjacent_vertex] == false && labeled_distances[adjacent_vertex] > adjacent_distance + labeled_distances[current_vertex]) {
                labeled_distances[adjacent_vertex] = adjacent_distance + labeled_distances[current_vertex];
                pq.push(make_pair(adjacent_vertex, labeled_distances[adjacent_vertex]));
            }
        }
    }

    for(int i=0; i<num_vertices; i++) {
        cout << starting_vertex << " <-> " << i << " : " << labeled_distances[i] << endl;
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

    Dijikstra d;

    d.createAdjacentVertices(edges, 9);
    d.createMST();

    return 0;
}
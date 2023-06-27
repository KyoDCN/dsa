#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Kruskal {
    bool compare(vector<int> a, vector<int> b);
public:
    int createMST(vector<vector<int>>& edges, int num_edges);
};

int Kruskal::createMST(vector<vector<int>>& edges, int num_vertices) {
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    };
    
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(num_vertices);
    // Make Set
    for(int i=1; i<num_vertices; i++) {
        parent[i] = i;
    }

    int totalEdgeWeight = 0;

    for(auto edge : edges) {
        int src_vertex = edge[0];
        int dest_vertex = edge[1];

        // Find representative of Set
        int rep_src = parent[src_vertex];
        int rep_dest = parent[dest_vertex];

        // If representative value not match (meaning, of different branch)
        if(rep_src != rep_dest) {
            totalEdgeWeight += edge[2];

            // UnionSet
            parent[rep_dest] = rep_src;
        }
    }

    return totalEdgeWeight;
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

    Kruskal k;
    cout << "Total Weight: " << k.createMST(edges, 9);

    return 0;
}
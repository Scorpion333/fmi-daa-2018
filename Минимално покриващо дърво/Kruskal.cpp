#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 20000;
const int MAX_M = 200000;
int n, m;

struct DisjointSet {
    int n;
    int parent[MAX_N];
    int rank[MAX_N];

    DisjointSet(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] < rank[y])
            parent[x] = y;
        else /* rank[x] >= rank[y] */
            parent[y] = x;

        if (rank[x] == rank[y])
            rank[x]++;
    }
};

struct Edge {
    int src, dest, weight;

    bool operator < (const Edge& other) {
        return weight < other.weight;
    }
} edges[MAX_M];

void read_input() {
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> w;
        edges[i] = { v1, v2, w };
    }
}

int main() {
    ios::sync_with_stdio(false);
    read_input();
    sort(edges, edges + m);

    DisjointSet ds(n);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (ds.find(edges[i].src) != ds.find(edges[i].dest)) {
            ds.unite(edges[i].src, edges[i].dest);
            sum += edges[i].weight;
        }
    }
    cout << sum << '\n';
}
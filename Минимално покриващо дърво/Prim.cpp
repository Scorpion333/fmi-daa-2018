#include<iostream>
#include<vector>
using namespace std;

const int INF = 1000000000;
const int MAX_N = 20000;
const int MAX_M = 200000;
int n, m;

struct Edge {
    int dest, weight;
};

vector<Edge> graph[MAX_N];

void read_input() {
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({ v2, w });
        graph[v2].push_back({ v1, w });
    }
}

int parent[MAX_N], weight[MAX_N];
bool in_tree[MAX_N] = { false };

int min_v_out_of_tree() {
    int min_v = 0;
    while (in_tree[min_v]) {
        min_v++;
    }
    for (int i = min_v + 1; i < n; i++) {
        if (!in_tree[i] && weight[i] < weight[min_v])
            min_v = i;
    }
    return min_v;
}

int main() {
    ios::sync_with_stdio(false);
    read_input();

    parent[0] = -1;
    weight[0] = 0;
    for (int i = 1; i < n; i++) {
        weight[i] = INF;
    }

    for (int i = 0; i < n - 1; i++) {
        int next_v = min_v_out_of_tree();
        in_tree[next_v] = true;
        for (Edge edge: graph[next_v]) {
            if (!in_tree[edge.dest] && edge.weight < weight[edge.dest]) {
                weight[edge.dest] = edge.weight;
                parent[edge.dest] = next_v;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weight[i];
    }
    cout << sum << '\n';
}
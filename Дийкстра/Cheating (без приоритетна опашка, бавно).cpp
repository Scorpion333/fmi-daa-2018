#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 10000;
const int INF = 1000000000;
int n, m, k, min_distance_to[MAX_N];
bool ready[MAX_N] = { false };

struct Edge {
    int target;
    bool distance;
};
vector<Edge> edges_from[MAX_N];

void read_input() {
    cin >> n >> m >> k;

    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        edges_from[v1].push_back({ v2, 0 });
        edges_from[v2].push_back({ v1, 0 });
    }
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2;
        edges_from[v1].push_back({ v2, 1 });
        edges_from[v2].push_back({ v1, 1 });
    }
}

int the_unready_vertex_with_smallest_min_distance() {
    int result = 0;
    while (ready[result]) {
        result++;
    }
    for (int v = result + 1; v <= n; v++) {
        if (!ready[v] && min_distance_to[v] < min_distance_to[result])
            result = v;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    read_input();

    min_distance_to[0] = 0;
    for (int i = 1; i < n; i++) {
        min_distance_to[i] = INF;
    }

    while (!ready[n - 1]) {
        int v = the_unready_vertex_with_smallest_min_distance();
        ready[v] = true;

        for (int j = 0; j < edges_from[v].size(); j++) {
            const Edge& edge = edges_from[v][j];
            if (!ready[edge.target] && min_distance_to[v] + edge.distance < min_distance_to[edge.target])
                min_distance_to[edge.target] = min_distance_to[v] + edge.distance;
        }
    }
    if (min_distance_to[n - 1] == INF) {
        cout << "-1\n";
    }
    else {
        cout << min_distance_to[n - 1] << '\n';
    }
}
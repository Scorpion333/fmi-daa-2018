#include<iostream>
using namespace std;

const int MAX_N = 500;
bool adj_matrix[MAX_N + 1][MAX_N + 1] = { false };
int n, m;

int linked_components = 0;
bool marked[MAX_N + 1] = { false };

void mark_linked_component_of(int vertex) {
    marked[vertex] = true;
    for (int other = 1; other <= n; other++) {
        if (adj_matrix[vertex][other] && !marked[other])
            mark_linked_component_of(other);
    }
}

void find_linked_components() {
    for (int vertex = 1; vertex <= n; vertex++) {
        if (!marked[vertex]) {
            linked_components++;
            mark_linked_component_of(vertex);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    int vertex1, vertex2;
    for (int i = 0; i < m; i++) {
        cin >> vertex1 >> vertex2;
        adj_matrix[vertex1][vertex2] = true;
        adj_matrix[vertex2][vertex1] = true;
    }

    find_linked_components();
    cout << linked_components << '\n';
}
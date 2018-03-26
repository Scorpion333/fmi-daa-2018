#include<iostream>
#include<queue>
using namespace std;

const int MAX = 2000;

int n, holes, knights,
    visited_knights = 0,
    max_jumps = 0;

char table[MAX][MAX] = { '\0' };    // '\0' for free, 'k' for knight, 'h' for hole, 'v' for visited

struct Cell {
    int x, y, jumps;

    void read() {
        cin >> x >> y;
    }
    void put_hole() {
        table[x][y] = 'h';
    }
    void put_knight() {
        table[x][y] = 'k';
    }

    bool is_valid() {
        return 0 <= x && x < n
            && 0 <= y && y < n;
    }
    bool is_hole() {
        return table[x][y] == 'h';
    }
    bool is_visited() {
        return table[x][y] == 'v';
    }
    bool has_knight() {
        return table[x][y] == 'k';
    }

    void visit(queue<Cell>& q) {
        if (!is_valid() || is_hole() || is_visited())
            return;

        q.push(*this);
        if (has_knight()) {
            visited_knights++;
            max_jumps = jumps;
        }
        table[x][y] = 'v';
    }

    void visit_neighbours(queue<Cell>& q) {
        jumps++;
        x -= 2; y -= 1; visit(q); x += 2; y += 1;
        x -= 2; y += 1; visit(q); x += 2; y -= 1;
        x -= 1; y -= 2; visit(q); x += 1; y += 2;
        x -= 1; y += 2; visit(q); x += 1; y -= 2;

        x += 2; y -= 1; visit(q); x -= 2; y += 1;
        x += 2; y += 1; visit(q); x -= 2; y -= 1;
        x += 1; y -= 2; visit(q); x -= 1; y += 2;
        x += 1; y += 2; visit(q); x -= 1; y -= 2;
        jumps--;
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> holes >> knights;

    Cell cell;
    for (int i = 0; i < holes; i++) {
        cell.read();
        cell.put_hole();
    }
    for (int i = 0; i < knights; i++) {
        cell.read();
        cell.put_knight();
    }
    queue<Cell> q;
    cell.read();
    cell.jumps = 0;
    cell.visit(q);

    while (!q.empty()) {
        cell = q.front();
        q.pop();
        cell.visit_neighbours(q);
    }
    cout << visited_knights << ' ' << max_jumps << '\n';
}
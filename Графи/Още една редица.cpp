#include<iostream>
#include<queue>
#include<utility>
using namespace std;

const int MOD = 1000007;
bool visited[MOD] = { false };

int reverse(int n) {
    int reversed = 0;
    while (n > 0) {
        (reversed *= 10) += n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    queue<pair<int, int>> q({ {a, 1} });
    visited[a] = true;

    int x, level, next;

    while (!q.empty()) {
        x = q.front().first;
        level = q.front().second;
        q.pop();

        if (x == b) {
            cout << level << '\n';
            return 0;
        }
        next = (x + 1) % MOD;
        if (!visited[next]) {
            q.push({ next, level + 1 });
            visited[next] = true;
        }
        next = reverse(x) % MOD;
        if (!visited[next]) {
            q.push({ next, level + 1 });
            visited[next] = true;
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 1000000;
const int MAX_M = 10;

int main() {
    ios::sync_with_stdio(false);

    int n, m, a[MAX_N], s[MAX_M];

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        bool sum_is_found = false;
        for (int j = 0; j < n; j++) {
            if (binary_search(a + j + 1, a + n, s[i] - a[j])) {
                cout << "YES\n";
                sum_is_found = true;
                break;
            }
        }
        if(!sum_is_found)
            cout << "NO\n";
    }
}
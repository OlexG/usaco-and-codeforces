#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> bfs(n), dfs(n);
    map<pair<int, int>, int> edge;
    for (int i = 0; i < n; i += 1) {
        cin >> bfs[i];
    }

    for (int i = 0; i < n; i += 1) {
        cin >> dfs[i];
    }

    if (bfs[1] != dfs[1]) {
        cout << -1 << '\n';
        return 0;
    }

    cout << 2 * (n - 1) - 1 << '\n';
    for (int i = 1; i < n; i += 1) {
        cout << dfs[i - 1] << ' ' << dfs[i] << '\n';
    }

    for (int i = 2; i < n; i += 1) {
        cout << 1 << ' ' << bfs[i] << '\n';
    }

    return 0;
}

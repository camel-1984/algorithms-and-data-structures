#include <iostream>
#include <queue>

using namespace std;

const long long INF = LLONG_MAX;

int main() {

    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, long long>>> listik(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        listik[a].emplace_back(b, w);
    }

    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(s);
    reachable[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : listik[u]) {
            int v = e.first;
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i < n; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (!reachable[u] || dist[u] == INF) continue;
            for (auto& e : listik[u]) {
                int v = e.first;
                long long w = e.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    vector<bool> infinite(n + 1, false);

    for (int u = 1; u <= n; ++u) {
        if (!reachable[u] || dist[u] == INF) continue;
        for (auto &e : listik[u]) {
            int v = e.first;
            long long w = e.second;
            if (dist[v] > dist[u] + w) {
                if (!infinite[v]) {
                    queue<int> q_inf;
                    q_inf.push(v);
                    infinite[v] = true;
                    while (!q_inf.empty()) {
                        int x = q_inf.front();
                        q_inf.pop();
                        for (auto &e2 : listik[x]) {
                            int y = e2.first;
                            if (!infinite[y]) {
                                infinite[y] = true;
                                q_inf.push(y);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (!reachable[u]) {
            cout << "*\n";
        } else if (infinite[u]) {
            cout << "-\n";
        } else {
            cout << dist[u] << "\n";
        }
    }

    return 0;
}
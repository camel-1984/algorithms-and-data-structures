#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

bool BFS(int start, int end, const vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == end) return true;
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

void BellmanFord(int n, int start, int end, const vector<vector<pair<int, int>>>& graph) {
    vector<long long> dist(n + 1, LLONG_MIN);
    dist[start] = 0;

    for (int i = 1; i < n; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (dist[u] != LLONG_MIN) {
                for (const auto& edge : graph[u]) {
                    int v = edge.first, w = edge.second;
                    if (dist[v] < dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
    }

    bool hasPositiveCycle = false;
    for (int u = 1; u <= n; ++u) {
        if (dist[u] != LLONG_MIN) {
            for (const auto& edge : graph[u]) {
                int v = edge.first, w = edge.second;
                if (dist[v] < dist[u] + w) {
                    if (BFS(v, end, graph)) {
                        hasPositiveCycle = true;
                        break;
                    }
                }
            }
        }
        if (hasPositiveCycle) break;
    }

    if (hasPositiveCycle) {
        cout << ":)";
    } else if (dist[end] == LLONG_MIN) {
        cout << ":(";
    } else {
        cout << dist[end];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    BellmanFord(n, 1, n, graph);

    return 0;
}
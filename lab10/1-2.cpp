#include <iostream>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<vector<pair<int, int>>> mst;

void Prima(int start) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    visited[start] = true;

    for (auto& edge : graph[start]) {
        pq.emplace(edge.second, start, edge.first);
    }

    while (!pq.empty()) {
        auto [weight, from, to] = pq.top();
        pq.pop();

        if (visited[to]) continue;

        visited[to] = true;
        mst[from].emplace_back(to, weight);
        mst[to].emplace_back(from, weight);

        for (auto& edge : graph[to]) {
            if (!visited[edge.first]) {
                pq.emplace(edge.second, to, edge.first);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    mst.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int b, e, w;
        cin >> b >> e >> w;
        graph[b].emplace_back(e, w);
        graph[e].emplace_back(b, w);
    }

    Prima(1);

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto& edge : mst[i]) {
            sum += edge.second;
        }
    }
    cout << sum / 2;

    return 0;
}
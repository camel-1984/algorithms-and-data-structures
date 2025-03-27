#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> edges;
    double total = 0.0;

    using Edge = tuple<double, int, int>;
    priority_queue<Edge, vector<Edge>, greater<>> pq;

    visited[1] = true;
    for (int j = 2; j <= n; ++j) {
        int dx = cities[1].first - cities[j].first;
        int dy = cities[1].second - cities[j].second;
        double dist_sq = dx * dx + dy * dy;
        pq.emplace(dist_sq, 1, j);
    }

    while (!pq.empty()) {
        auto [weight_sq, from, to] = pq.top();
        pq.pop();

        if (visited[to]) continue;
        visited[to] = true;
        total += sqrt(weight_sq);
        edges.emplace_back(from, to);

        for (int j = 1; j <= n; ++j) {
            if (!visited[j]) {
                int dx = cities[to].first - cities[j].first;
                int dy = cities[to].second - cities[j].second;
                double dist_sq = dx * dx + dy * dy;
                pq.emplace(dist_sq, to, j);
            }
        }
    }

    cout << fixed << setprecision(3) << total << '\n';
    cout << edges.size() << '\n';
    for (auto& e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}
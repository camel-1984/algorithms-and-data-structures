#include <iostream>


int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    using Edge = tuple<long long, int, int>;

    int n;
    cin >> n;

    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<long long> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    priority_queue<Edge, vector<Edge>, greater<>> pq;

    for (int i = 0; i < n; ++i) {
        pq.emplace(c[i], -1, i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = abs(cities[i].first - cities[j].first);
            long long dy = abs(cities[i].second - cities[j].second);
            long long cost = (dx + dy) * (k[i] + k[j]);
            pq.emplace(cost, i, j);
        }
    }

    vector<bool> in_mst(n, false);
    vector<int> power_stations;
    vector<pair<int, int>> connections;
    long long total_cost = 0;
    int connected = 0;

    while (connected < n && !pq.empty()) {
        auto [cost, u, v] = pq.top();
        pq.pop();

        if (u == -1) {
            if (!in_mst[v]) {
                in_mst[v] = true;
                total_cost += cost;
                power_stations.push_back(v + 1);
                connected++;
            }
        } else {
            if (in_mst[u] && in_mst[v]) continue;
            if (!in_mst[u] && !in_mst[v]) continue;

            if (!in_mst[u]) {
                in_mst[u] = true;
                total_cost += cost;
                connections.emplace_back(u + 1, v + 1);
                connected++;
            } else if (!in_mst[v]) {
                in_mst[v] = true;
                total_cost += cost;
                connections.emplace_back(u + 1, v + 1);
                connected++;
            }
        }
    }

    cout << total_cost << "\n";
    cout << power_stations.size() << "\n";
    for (int station : power_stations) {
        cout << station << " ";
    }
    cout << "\n";
    cout << connections.size() << "\n";
    for (auto& [fst, snd] : connections) {
        cout << fst << " " << snd << "\n";
    }

    return 0;
}
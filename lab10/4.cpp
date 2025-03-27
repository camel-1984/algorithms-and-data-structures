#include <iostream>
#include <iomanip>

int main() {

    using namespace std;

    int n;
    cin >> n;
    vector<pair<int, int>> cities(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<double> min_dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    min_dist[1] = 0.0;
    double total = 0.0;

    for (int step = 1; step <= n; ++step) {
        int u = -1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (u == -1 || min_dist[i] < min_dist[u])) {
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;
        total += min_dist[u];

        for (int v = 1; v <= n; ++v) {
            if (!visited[v]) {
                int dx = cities[u].first - cities[v].first;
                int dy = cities[u].second - cities[v].second;
                double dist = sqrt(dx * dx + dy * dy);
                if (dist < min_dist[v]) {
                    min_dist[v] = dist;
                }
            }
        }
    }

    cout << fixed << setprecision(6) << total << '\n';
    return 0;
}

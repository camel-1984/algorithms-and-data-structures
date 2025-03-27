#include <iostream>
#include <queue>

using namespace std;

struct Edge {
    int to;
    double rate;
    double commission;

    Edge(int t, double r, double c) : to(t), rate(r), commission(c) {}
};

double inf = 0.0000001;
vector<vector<Edge>> listik;
vector<bool> reachable;
vector<double> cash;

void BFS(int s) {
    queue<int> q;
    q.push(s);
    reachable[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& e : listik[u]) {
            int v = e.to;
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }
}

bool BellmanFord(int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int a = 1; a <= n; ++a) {
            if (!reachable[a] || cash[a] < inf) continue;
            for (const Edge& e : listik[a]) {
                if (!reachable[e.to]) continue;
                double new_sum = (cash[a] - e.commission) * e.rate;
                if (new_sum > cash[e.to]) {
                    cash[e.to] = new_sum;
                }
            }
        }
    }

    bool has_positive_cycle = false;
    for (int a = 1; a <= n; ++a) {
        if (!reachable[a] || cash[a] < inf) continue;
        for (const Edge& e : listik[a]) {
            if (!reachable[e.to]) continue;
            double new_sum = (cash[a] - e.commission) * e.rate;
            if (new_sum > cash[e.to]) {
                has_positive_cycle = true;
                break;
            }
        }
        if (has_positive_cycle) break;
    }
    return has_positive_cycle;
}

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;

    listik.resize(n + 1);
    reachable.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        listik[a].emplace_back(b, rab, cab);
        listik[b].emplace_back(a, rba, cba);
    }

    BFS(s);

    cash.assign(n + 1, 0.0);
    cash[s] = v;

    bool flag = BellmanFord(n);

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}
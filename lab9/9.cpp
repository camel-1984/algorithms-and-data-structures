#include <iostream>
#include <queue>

using namespace std;

const long long INF = LONG_LONG_MAX;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long h;
    int a, b, c;
    cin >> h >> a >> b >> c;

    long long X = h - 1;

    int d = min({a, b, c});

    vector<long long> dist(d, INF);
    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> que;
    que.emplace(0, 0);

    while (!que.empty()) {
        auto [val, r] = que.top();
        que.pop();
        if (val != dist[r])
            continue;
        for (int i : {a, b, c}) {
            int nr = (r + i) % d;
            long long nval = val + i;
            if (nval < dist[nr]) {
                dist[nr] = nval;
                que.emplace(nval, nr);
            }
        }
    }

    long long ans = 0;
    for (int r = 0; r < d; r++) {
        if (dist[r] > X)
            continue;
        long long cnt = (X - dist[r]) / d + 1;
        ans += cnt;
    }

    cout << ans << "\n";
    return 0;
}
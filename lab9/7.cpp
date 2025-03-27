#include <iostream>

using namespace std;

const int INF = INT_MAX;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> e(n, 0);
    for (int i = 0; i < n; ++i) {
        int max_dist = 0;
        for (int j = 0; j < n; ++j)
            if (dist[i][j] > max_dist)
                max_dist = dist[i][j];
        e[i] = max_dist;
    }

    int diameter = 0, radius = INF;
    for (int val : e) {
        if (val > diameter) diameter = val;
        if (val < radius) radius = val;
    }

    cout << diameter << "\n" << radius;

    return 0;
}
#include <iostream>

using namespace std;

struct Edge {
    int a, b, w;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;

    for (int v = 2; v <= N; ++v) {
        edges.push_back({1, v, v - 2});
    }

    vector<Edge> additional;
    for (int d = 1; d <= N - 2; ++d) {
        for (int i = 2; i + d <= N; ++i) {
            int j = i + d;
            additional.push_back({i, j, d - 1});
        }
    }

    int remaining = M - (N - 1);
    for (int i = 0; i < remaining && i < additional.size(); ++i) {
        edges.push_back(additional[i]);
    }

    for (const Edge& e : edges) {
        cout << e.a << " " << e.b << " " << e.w << "\n";
    }

    return 0;
}
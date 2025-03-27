#include <iostream>
#include <vector>

void FillList(std::vector<std::vector<int>>& list, int M) {
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
}

bool DFS(int v, int parent, const std::vector<std::vector<int>>& list, std::vector<bool>& visited) {
    visited[v] = true;
    for (int u : list[v]) {
        if (!visited[u]) {
            if (DFS(u, v, list, visited)) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> list(n + 1);
    FillList(list, m);

    std::vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (DFS(i, -1, list, visited)) {
                std::cout << "YES\n";
                return 0;
            }
        }
    }

    std::cout << "NO\n";
    return 0;
}

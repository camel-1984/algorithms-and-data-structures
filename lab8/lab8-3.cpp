#include <iostream>
#include <vector>
#include <algorithm>

void FillList(std::vector<std::vector<int>>& list, const int& M) {
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
    }
}

void DFS(int v, const std::vector<std::vector<int>>& list, std::vector<bool>& visited, std::vector<int>& order) {
    visited[v] = true;
    for (int i : list[v]) {
        if (!visited[i]) {
            DFS(i, list, visited, order);
        }
    }
    order.push_back(v);
}

void ReverseList(const std::vector<std::vector<int>>& list, std::vector<std::vector<int>>& rev_list) {
    for (int i = 1; i < list.size(); i++) {
        for (int j : list[i]) {
            rev_list[j].push_back(i);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> list(n + 1);
    FillList(list, m);

    std::vector<std::vector<int>> rev_list(n + 1);
    ReverseList(list, rev_list);

    std::vector<bool> visited(n + 1);
    std::vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, rev_list, visited, order);
        }
    }
    std::reverse(order.begin(), order.end());

    visited.assign(n + 1, false);
    std::vector<std::vector<int>> kss_list;

    for (int v : order) {
        if (!visited[v]) {
            std::vector<int> component;
            DFS(v, list, visited, component);
            kss_list.push_back(component);
        }
    }

    return 0;
}


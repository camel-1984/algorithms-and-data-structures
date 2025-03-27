#include <iostream>
#include <set>

using namespace std;

void FillList(vector<vector<int>>& list, int m) {
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
    }
}

void DFS(int v, const vector<vector<int>>& list, vector<bool>& visited, vector<int>& order) {
    visited[v] = true;
    for (int i : list[v]) {
        if (!visited[i]) {
            DFS(i, list, visited, order);
        }
    }
    order.push_back(v);
}

void ReverseList(const vector<vector<int>>& list, vector<vector<int>>& rev_list) {
    for (int i = 1; i < list.size(); i++) {
        for (int j : list[i]) {
            rev_list[j].push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> list(n + 1);
    FillList(list, m);

    vector<vector<int>> rev_list(n + 1);
    ReverseList(list, rev_list);

    vector<bool> visited(n + 1);
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            DFS(i, rev_list, visited, order);
    }
    reverse(order.begin(), order.end());

    visited.assign(n + 1, false);
    vector<vector<int>> kss;

    for (int v : order) {
        if (!visited[v]) {
            vector<int> component;
            DFS(v, list, visited, component);
            kss.push_back(component);
        }
    }

    vector<int> family(n + 1);
    for (auto& component : kss) {
        int minHouse = *min_element(component.begin(), component.end());
        for (int house : component) {
            family[house] = minHouse;
        }
    }

    set<pair<int, int>> familyEdges;
    for (int i = 1; i <= n; i++) {
        for (int j : list[i]) {
            if (family[i] != family[j])
                familyEdges.insert(make_pair(family[i], family[j]));
        }
    }

    cout << kss.size() << " " << familyEdges.size() << "\n";
    for (auto &edge : familyEdges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}

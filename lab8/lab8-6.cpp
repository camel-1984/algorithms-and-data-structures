#include <iostream>
#include <queue>

using namespace std;

void FillList(std::vector<std::vector<int>>& list, const int& M) {
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
}

void BFS(const int v, const std::vector<std::vector<int>>& list, std::vector<bool>& visited, std::vector<int>& order,
    std::vector<int>& dist) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int i = q.front();
        order.push_back(i);
        q.pop();
        for (int j : list[i]) {
            if (!visited[j]) {
                dist[j] = dist[i] + 1;
                q.push(j);
                visited[j] = true;
            }
        }
    }
}


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int m, k;
    std:: cin >> m >> k;

    std::vector<std::vector<int>> list(n + 1);


    FillList(list, m);

    std::vector<bool> visited(n + 1);
    std::vector<int> order;
    std::vector<int> dist(n+1,100000);
    dist[1] = 0;

    BFS(1,list,visited,order,dist);

    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == k) {
            std::cout << i << "\n";
        }
    }

    auto i = find(dist.begin(),dist.end(), k);
    if (i == dist.end()) {
        std::cout << "NO";
    }

    return 0;
}
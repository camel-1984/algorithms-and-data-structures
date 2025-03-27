void PrintList(const std::vector<std::vector<int>>& list) {
    for (int i = 1; i < list.size(); i++) {
        std::cout << i << ": ";
        for (int j : list[i]) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

void FillList(std::vector<std::vector<int>>& list, const int& M) {
    for (int i = 0; i < M; i++) {
        int v;
        int k;
        std::cin >> v >> k;
        list[v].push_back(k);
    }
}

void DFS(const int v, std::vector<std::vector<int>>& list, std::vector<bool>& visited, std::vector<int>& order) {
    visited[v] = true;
    for (const int i : list[v]) {
        if (!visited[i]) {
            DFS(i, list,visited,order);
        }
    }
    order.push_back(v);
}

void Reverse(std::vector<int>& order) {
    int left = 0, right = order.size() - 1;
    while (left < right) {
        std::swap(order[left], order[right]);
        left++;
        right--;
    }
}

void ReverseList(const std::vector<std::vector<int>>& list, std::vector<std::vector<int>>& rev_list) {
    for (int i = 1; i < list.size(); i++) {
        for (int j : list[i]) {
            rev_list[j].push_back(i);
        }
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

std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
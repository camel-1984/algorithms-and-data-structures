#include <iostream>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> spisok;
vector<int> parent;

void Fillspisok(vector<vector<pair<int, int>>>& spisok, const int e) {
    for (int i = 0; i < e; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        spisok[v1].emplace_back(v2, weight);
        spisok[v2].emplace_back(v1, weight);
    }
}

vector<int> Deykstra(vector<vector<pair<int, int>>>& spisok, vector<int>& parent, const int v, const int s) {
    vector<int> dis(v + 1, INT_MAX);
    dis[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        int currentDist = que.top().first;
        int currentNode = que.top().second;
        que.pop();

        if (currentDist > dis[currentNode]) {
            continue;
        }

        for (const pair<int, int>& edge : spisok[currentNode]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dis[neighbor] > currentDist + weight) {
                dis[neighbor] = currentDist + weight;
                parent[neighbor] = currentNode;
                que.emplace(dis[neighbor], neighbor);
            }
        }
    }

    return dis;
}

vector<int> RecoverPath(const vector<int>& parent, int f) {
    vector<int> path;
    for (int v = f; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int v, e;
    cin >> v >> e;

    int s, f;
    cin >> s >> f;

    spisok.assign(v+1, vector<pair<int, int>>());
    parent.assign(v+1, -1);

    Fillspisok(spisok, e);

    vector<int> dis = Deykstra(spisok, parent, v, s);

    if (dis[f] == INT_MAX) {
        cout << -1;
        return 0;
    } else {
        cout << dis[f];
        cout << "\n";
    }

    vector<int> path = RecoverPath(parent, f);


    return 0;
}
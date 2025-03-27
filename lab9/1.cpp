#include <iostream>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> spisok;

void Fillspisok(vector<vector<pair<int, int>>>& spisok, const int v) {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            int weight;
            cin >> weight;
            if (weight != -1 && i != j) {
                spisok[i].emplace_back(j, weight);
            }
        }
    }
}

vector<int> Deykstra(vector<vector<pair<int, int>>>& spisok, const int v, const int s) {
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

        for (const pair<int,int>& i : spisok[currentNode]) {
            int neighbor = i.first;
            int weight = i.second;

            if (dis[neighbor] > currentDist + weight) {
                dis[neighbor] = currentDist + weight;
                que.emplace(dis[neighbor], neighbor);
            }
        }
    }

    return dis;
}

int main() {
    int v, s, f;
    cin >> v >> s >> f;

    spisok.assign(v+1, vector<pair<int, int>>());
    Fillspisok(spisok, v);

    vector<int> vec = Deykstra(spisok, v, s);

    if (vec[f] == INT_MAX) {
        cout << -1;
    } else {
        cout << vec[f];
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if (m != n){
        cout << "EUCLID";
        return 0;
    }

    vector<vector<int>> list(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    int countVisited = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        countVisited++;
        for (int nxt : list[cur]){
            if (!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    if (countVisited != n){
        cout << "EUCLID";
        return 0;
    }

    vector<int> stepen(n, 0);
    vector<bool> removed(n, false);
    for (int i = 0; i < n; i++){
        stepen[i] = list[i].size();
    }
    queue<int> leaves;
    for (int i = 0; i < n; i++){
        if (stepen[i] == 1)
            leaves.push(i);
    }

    while(!leaves.empty()){
        int v = leaves.front();
        leaves.pop();
        removed[v] = true;
        for (int u : list[v]){
            if (!removed[u]){
                stepen[u]--;
                if (stepen[u] == 1)
                    leaves.push(u);
            }
        }
    }

    int cycleCount = 0;
    for (int i = 0; i < n; i++){
        if (!removed[i])
            cycleCount++;
    }
    if(cycleCount >= 3)
        cout << "ARCHIMEDES";
    else
        cout << "EUCLID";

    return 0;
}

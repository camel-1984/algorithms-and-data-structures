#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int pos(int i) {
    return 2 * (i - 1);
}

int neg(int i) {
    return 2 * (i - 1) + 1;
}

vector<int> kss;
vector<int> disc;
vector<int> low;
vector<bool> stage;
stack<int> st;
vector<vector<int>> LIST;

void addE(int u, int v) {
    LIST[u].push_back(v);
}

void addV(int l1, int l2) {
    int not_l1;
    if (l1 % 2 == 0) {
        not_l1 = l1 + 1;
    } else {
        not_l1 = l1 - 1;
    }
    int not_l2;
    if (l2 % 2 == 0) {
        not_l2 = l2 + 1;
    } else {
        not_l2 = l2 - 1;
    }
    addE(not_l1, l2);
    addE(not_l2, l1);
}

void addUnitClause(int a) {
    int not_lit;
    if (a % 2 == 0) {
        not_lit = a + 1;
    } else {
        not_lit = a - 1;
    }
    addE(not_lit, a);
}

int timeCounter = 0, kssCount = 0;

void DFS(const int u) {
    disc[u] = ++timeCounter;
    low[u] = disc[u];
    st.push(u);
    stage[u] = true;

    for (int v : LIST[u]) {
        if (disc[v] == 0) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else if (stage[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        while (true) {
            int w = st.top();
            st.pop();
            stage[w] = false;
            kss[w] = kssCount;
            if (w == u)
                break;
        }
        kssCount++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cin.ignore();

    int totalVertices = 2 * n;
    LIST.assign(totalVertices, vector<int>());

    for (int i = 0; i < k; i++){
        string line;
        getline(cin, line);

        istringstream iss(line);
        string token;
        vector<string> tokens;
        while (iss >> token)
            tokens.push_back(token);

        if (tokens.size() == 1) {
            if (tokens[0][0] == '!'){
                int ing = stoi(tokens[0].substr(1));
                addUnitClause(neg(ing));
            }
        } else if (tokens.size() == 3) {
            int A = stoi(tokens[0]);
            int B = stoi(tokens[2]);
            string op = tokens[1];
            if (op == "||") {
                addV(pos(A), pos(B));
            } else if (op == "->") {
                addE(pos(A), pos(B));
                int notB = neg(B);
                int notA = neg(A);
                addE(notB, notA);
            } else if (op == "&") {
                addUnitClause(pos(A));
                addUnitClause(pos(B));
            } else if (op == "^") {
                addV(pos(A), pos(B));
                addV(neg(A), neg(B));
            }
        }
    }

    kss.assign(totalVertices, -1);
    disc.assign(totalVertices, 0);
    low.assign(totalVertices, 0);
    stage.assign(totalVertices, false);
    timeCounter = 0;
    kssCount = 0;
    for (int i = 0; i < totalVertices; i++){
        if (disc[i] == 0)
            DFS(i);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++){
        if (kss[pos(i)] == kss[neg(i)]) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

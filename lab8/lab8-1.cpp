 #include <iostream>

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

 int main() {

     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);


     int N;
     int M;
     std::cin >> N >> M;

     std::vector<std::vector<int>> list(N+1);

     FillList(list, M);

     std::vector<bool> visited(N+1);
     std::vector<int> order;

     for (int i = 1; i <= N; i++) {
         if (!visited[i]) DFS(i, list, visited, order);
     }

     Reverse(order);

     std::vector<int> position(N + 1);

     for (int i = 0; i < N; i++) {
         position[order[i]] = i + 1;
     }
     for (int i = 1; i <= N; i++) {
         std::cout << position[i] << " ";
     }

 return 0;
 }
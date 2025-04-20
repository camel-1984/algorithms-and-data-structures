// #include <iostream>
// using namespace std;
//
// long long MOD = 1000000007;
//
// int main(){
//
//     int N, M;
//     cin >> N >> M;
//
//     vector<vector<long long>> table(N+1, vector<long long>(M+1, 0));
//
//     table[1][1] = 1;
//
//     for(int s = 2; s <= N + M; s++){
//         for(int r = 1; r <= N; r++){
//             int c = s - r;
//             if(c < 1 || c > M) continue;
//
//             long long ways = 0;
//
//             if(r+1 <= N && c-2 >= 1)
//                 ways = (ways + table[r+1][c-2]) % MOD;
//
//             if(r-1 >= 1 && c-2 >= 1)
//                 ways = (ways + table[r-1][c-2]) % MOD;
//
//             if(r-2 >= 1 && c-1 >= 1)
//                 ways = (ways + table[r-2][c-1]) % MOD;
//
//             if(r-2 >= 1 && c+1 <= M)
//                 ways = (ways + table[r-2][c+1]) % MOD;
//
//             table[r][c] = (table[r][c] + ways) % MOD;
//         }
//     }
//
//     cout << table[N][M] % MOD << "\n";
// }

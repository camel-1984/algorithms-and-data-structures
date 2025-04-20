//  /* // сумма O(1) O(1)
//  #include <iostream>
//
//  int main() {
//      int a, b;
//      std::cin >> a;
//      std::cin >> b;
//      std::cout << a + b;
//  } */
//
//  /* // алгоритм евклида для нод (O(1) O(n))
//  #include <iostream>
//  using namespace std;
//  int main() {
//      long a, b;а
//      cin >> a >> b;
//      while (b != a) {
//          if (b>a) {
//              b = b-a;
//          }
//          else {
//              a = a-b;
//          }
//      }
//      cout << b;
//  } */
//
//  /* // полиндром (O(n) O(n))
//  #include <iostream>
//  #include <string>
//  using namespace std;
//
//  bool palindrom(const string s, int l, int r) {
//      while (l < r) {
//          if (s[l] != s[r])
//              return false;
//          l++;
//          r--;
//      }
//      return true;
//  }
//  int main() {
//      int N;
//      string W;
//      cin >> N >> W;
//      int l = 0, r = N - 1;
//
//      while (l < r && W[l] == W[r]) {
//          l++;
//          r--;
//      }
//      if (l == r) {
//          cout << "YES";
//      } else {
//          if (palindrom(W, l + 1, r) || palindrom(W, l, r - 1)) {
//              cout << "YES";
//          } else {
//              cout << "NO";
//          }
//      }
//  } */
//
//  /* // райт = алл - лефт (O(n) O(n))
//  #include <iostream>
//  using namespace std;
//  int main() {
//      int N;
//      cin >> N;
//      int arr[N];
//      for (int i = 0; i < N; ++i) {
//          cin >> arr[i];
//      }
//      int sum = 0;
//      for (int i = 0; i < N; ++i) {
//          sum += arr[i];
//      }
//      int left = 0;
//      for (int i = 0; i < N; ++i) {
//          int right = sum - left - arr[i];
//          if (left == right) {
//              cout << i;
//              return 0;
//          }
//          left += arr[i];
//      }
//      cout << -1;
//  } */
//
//  /* сдвиг (O(n) O(n * k))
//  #include <iostream>
//
//  void shift(int arr[], int N) {
//      int last = arr[N - 1];
//      for (int i = N - 1; i > 0; --i) {
//          arr[i] = arr[i - 1];
//      }
//      arr[0] = last;
//  }
//
//  int main() {
//      int N;
//      long K;
//      std::cin >> N >> K;
//      int arr[N];
//
//      K = K % N;
//      if (K < 0) {
//          K += N;
//      }
//
//      for (int i = 0; i < N; i++) {
//          std::cin >> arr[i];
//      }
//      for (long i = 0; i < K; ++i) {
//              shift(arr, N);
//          }
//      for (int i = 0; i < N; i++) {
//          std::cout<< arr[i] << " ";
//      }
//  } */
//
//  // бинари O(1) O(1)
//  #include <iostream>
//
//  using namespace std;
//
//  int main() {
//      long long x, y;
//      cin >> x >> y;
//      int count = 0;
//      for (int a1 = 1; a1 < 61; ++a1) {
//          for (int a2 = 1; a2 < 61-a1; ++a2) {
//              for (int a3 = 1; a3 < 61-a1-a2; ++a3) {
//                  string s2 = string(a1, '1') + string(a2, '0') + string(a3, '1');
//                  long long s10 = stoll(s2, NULL, 2);
//                  if (x <= s10 && s10 <= y) {
//                      ++count;
//                  }
//              }
//          }
//      }
//      cout << count;
//  }
//

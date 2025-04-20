// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
//
// using namespace std;
//
// int string_compare(string x, string y, int n) {
//     int c = 0;
//     for (int i = 0; i < n; i++) {
//         if (x[i] != y[i]) {
//             c += 1;
//         }
//     }
//     return c;
// }
//
// void create_string(int n, string b, vector<string> &vec) {
//     vec.clear();
//     string a(n, '0');
//     vec.push_back(a);
//     string prev = a;
//     int f = static_cast<int>(pow(2, n)); // Calculate f inside the function
//     for (int i = 0; i < f; i++) {
//         for (int j = n - 1; j >= 0; j--) {
//             prev[j] = '1';
//             if (string_compare(prev, b, n) == 1) {
//                 vec.push_back(prev); // Use prev instead of b
//             }
//         }
//     }
// }
//
// int main() {
//     int n = 3;
//     string b(n, '0'); // Initialize string b with the correct length
//
//     vector<string> vec;
//     create_string(n, b, vec);
//
//     for (int i = 0; i < vec.size(); i++) {
//         cout << vec[i] << "\n";
//     }
//
//     return 0;
// }
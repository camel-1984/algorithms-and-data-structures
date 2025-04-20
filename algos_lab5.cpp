// #include <iostream>
//
// int main() {
//
//     int n;
//     std::cin >> n;
//
//     bool f = true;
//
//     long long* arr = nullptr;
//     arr = new long long[n];
//     for (int i = 0; i < n; i++) {
//         std::cin >> arr[i];
//     }
//
//     for(int i = 0; i < n; i++) {
//         if (2 * i + 1 < n) {
//             if (arr[i] <= arr[2*i+1] == false) {
//                 f = false;
//                 break;;
//             }
//         }
//         if (2 * i + 2 < n){
//             if (arr[i] <= arr[2*i+2] == false) {
//                 f = false;
//                 break;
//             }
//         }
//     }
//
//     if (f) {
//         std::cout << "YES";
//     } else {
//         std::cout << "NO";
//     }
//     delete[] arr;
//
// }
// #include <iostream>
//
// using namespace std;
//
// struct Node {
//     int value;
//     Node* left;
//     Node* right;
//
//     Node(int v) : value(v), left(nullptr), right(nullptr) {}
// };
//
// class BST {
// public:
//
//     Node* root;
//
//     BST() : root(nullptr) {}
//
//     void add(int value) {
//         root = addRec(root, value);
//     }
//
//     int findMinHeight() {
//         if (!root) return 0;
//         return MinHeight(root, 0);
//     }
//
//     int findMaxHeight() {
//         if (!root) return 0;
//         return MaxHeight(root, 0);
//     }
//
// private:
//
//     Node* addRec(Node* node, int value) {
//         if (!node) return new Node(value);
//         if (value < node->value)
//             node->left = addRec(node->left, value);
//         else
//             node->right = addRec(node->right, value);
//         return node;
//     }
//
//     int MinHeight(Node* node, int depth) {
//         if (!node) return 100000;
//
//         if (!node->left && !node->right) {
//             return depth;
//         }
//
//         return min(MinHeight(node->left, depth + 1),
//                    MinHeight(node->right, depth + 1));
//     }
//
//     int MaxHeight(Node* node, int depth) {
//         if (!node) return depth - 1;
//
//         return max(MaxHeight(node->left, depth + 1),
//                    MaxHeight(node->right, depth + 1));
//     }
// };
//
// int main() {
//
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//
//     int n;
//     cin >> n;
//
//     BST bst;
//
//     for (int i = 0; i < n; ++i) {
//         int height;
//         cin >> height;
//         bst.add(height);
//     }
//
//     int minHeight = bst.findMinHeight();
//     int maxHeight = bst.findMaxHeight();
//
//     cout << (maxHeight - minHeight);
//
//     return 0;
// }

// #include <iostream>
// #include <string>
//
// using namespace std;
//
// struct Node {
//     char value;
//     Node* next;
//
//     Node(char v) : value(v), next(nullptr) {}
// };
//
// struct Stack {
//     Node* top;
//     size_t size;
//
//     Stack() : top(nullptr), size(0) {}
//
//     void push(char c) {
//         Node* newNode = new Node(c);
//         newNode->next = top;
//         top = newNode;
//         ++size;
//     }
//
//     void pop() {
//         if (top) {
//             Node* temp = top;
//             top = top->next;
//             delete temp;
//             --size;
//         }
//     }
//
//     char peek() const {
//         if (top) {
//             return top->value;
//         }
//         return '\0';
//     }
//
//     bool empty() const {
//         return top == nullptr;
//     }
//
//     int Size() const {
//         return size;
//     }
// };
//
// pair<int, int> free(const string& s) {
//     Stack stack;
//     int count = 0;
//
//     for (char c : s) {
//         if (c == '(') {
//             stack.push(c);
//         } else if (c == ')') {
//             if (!stack.empty() && stack.peek() == '(') {
//                 stack.pop();
//             } else {
//                 ++count;
//             }
//         }
//     }
//
//     return {stack.Size(), count};
// }
//
// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//
//     int n;
//     cin >> n;
//
//     string* str = new string[n];
//     int cOpen[100] = {0};
//     int cClose[100] = {0};
//
//     for (int i = 0; i < n; ++i) {
//         cin >> str[i];
//         pair<int, int> result = free(str[i]);
//         int extraOpen = result.first;
//         int extraClose = result.second;
//
//         if (extraOpen > 0 && extraClose == 0) {
//             ++cOpen[extraOpen];
//         } else if (extraClose > 0 && extraOpen == 0) {
//             ++cClose[extraClose];
//         }
//     }
//
//     int pairCount = 0;
//
//     for (int i = 0; i < 100; ++i) {
//         pairCount += min(cOpen[i], cClose[i]);
//     }
//
//     cout << pairCount;
//
//     delete[] str;
//
//     return 0;
// }

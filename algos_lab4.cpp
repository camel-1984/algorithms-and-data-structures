/* #include <iostream>

struct node {
    int value;
    node *child_r;
    node *child_l;

    node(int val) : value(val), child_l(nullptr), child_r(nullptr) {}
};

class BST {
public:
    node *root;

    BST() : root(nullptr) {}

    node *insert(node *leaf, int value) {
        if (leaf == nullptr) {
            return new node(value);
        }
        if (value < leaf->value) {
            leaf->child_l = insert(leaf->child_l, value);
        } else {
            leaf->child_r = insert(leaf->child_r, value);
        }
        return leaf;
    }

    void inserting(int64_t value) {
        root = insert(root, value);
    }

    void inorder(node *leaf) {
        if (leaf == nullptr) return;
        inorder(leaf->child_l);
        std::cout << leaf->value << " ";
        inorder(leaf->child_r);
    }

    void inordering() {
        inorder(root);
    }
};

int main() {
    BST bst;
    uint32_t n;
    std::cin >> n;
    for (uint32_t i = 0; i < n; i++) {
        int64_t value;
        std::cin >> value;
        bst.inserting(value);
    }

    bst.inordering();
    return 0;
} */

/* #include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int x) {
        root = insertNode(root, x);
    }

    void remove(int x) {
        root = removeNode(root, x);
    }

    bool find(int x) {
        return findNode(root, x) != nullptr;
    }

    int find_next(int x) {
        Node* result = nullptr;
        find_nextnode(root, x, result);
        return result ? result->value : -1;
    }

    int find_prev(int x) {
        Node* result = nullptr;
        find_prevnode(root, x, result);
        return result ? result->value : -1;
    }

    Node* root;

    Node* insertNode(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->value) {
            node->left = insertNode(node->left, x);
        } else if (x > node->value) {
            node->right = insertNode(node->right, x);
        }
        return node;
    }

    Node* removeNode(Node* node, int x) {
        if (node == nullptr) return nullptr;

        if (x < node->value) {
            node->left = removeNode(node->left, x);
        } else if (x > node->value) {
            node->right = removeNode(node->right, x);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = getMin(node->right);
                node->value = successor->value;
                node->right = removeNode(node->right, successor->value);
            }
        }
        return node;
    }

    Node* getMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* findNode(Node* node, int x) {
        if (node == nullptr || node->value == x) {
            return node;
        }
        if (x < node->value) {
            return findNode(node->left, x);
        }
        return findNode(node->right, x);
    }

    void find_nextnode(Node* node, int x, Node*& result) {
        if (!node) return;

        if (node->value > x) {
            result = node;
            find_nextnode(node->left, x, result);
        } else {
            find_nextnode(node->right, x, result);
        }
    }

    void find_prevnode(Node* node, int x, Node*& result) {
        if (!node) return;

        if (node->value < x) {
            result = node;
            find_prevnode(node->right, x, result);
        } else {
            find_prevnode(node->left, x, result);
        }
    }
};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    BST bst;
    int opper, x;

    while (std::cin >> opper >> x) {
        if (opper == 0) {
            bst.insert(x);
        } else if (opper == 1) {
            bst.remove(x);
        } else if (opper == 2) {
            std::cout << (bst.find(x) ? "true" : "false") << '\n';
        } else if (opper == 3) {
            int result = bst.find_next(x);
            if (result == -1) {
                std::cout << "none" << '\n';
            } else {
                std::cout << result << '\n';
            }
        } else if (opper == 4) {
            int result = bst.find_prev(x);
            if (result == -1) {
                std::cout << "none" << '\n';
            } else {
                std::cout << result << '\n';
            }
        }
    }
    return 0;
}*/

/*#include <iostream>

struct Node {
    int value;
    int size; 
    Node* left;
    Node* right;

    Node(int val) : value(val), size(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int x) {
        root = insertNode(root, x);
    }

    void remove(int x) {
        root = removeNode(root, x);
    }
    
    int fingK(int k) {
        Node* result = findK_node(root, k);
        return result ? result->value : -1; 
    }

private:
    Node* root;

    Node* insertNode(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->value) {
            node->left = insertNode(node->left, x);
        } else if (x > node->value) {
            node->right = insertNode(node->right, x);
        }
        node->size = 1 + getSize(node->left) + getSize(node->right); 
        return node;
    }

    Node* removeNode(Node* node, int x) {
        if (node == nullptr) return nullptr;

        if (x < node->value) {
            node->left = removeNode(node->left, x);
        } else if (x > node->value) {
            node->right = removeNode(node->right, x);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = getMin(node->right);
                node->value = successor->value;
                node->right = removeNode(node->right, successor->value);
            }
        }
        node->size = 1 + getSize(node->left) + getSize(node->right); 
        return node;
    }
    

    Node* getMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    int getSize(Node* node) {
        return node ? node->size : 0;
    }

    Node* findK_node(Node* node, int k) {
        if (!node) return nullptr;

        int rightSize = getSize(node->right);

        if (k == rightSize + 1) {
            return node; 
        } else if (k <= rightSize) {
            return findK_node(node->right, k); 
        } else {
            return findK_node(node->left, k - rightSize - 1); 
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BST bst;
    int n;
    std::cin >> n;

    while (n--) {
        int opper, x;
        std::cin >> opper >> x;

        if (opper == 1) {
            bst.insert(x);
        } else if (opper == -1) {
            bst.remove(x);
        } else if (opper == 0) {
            int result = bst.fingK(x);
            std::cout << result << '\n';
            }
        }
    
    return 0;
} */

/* #include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int x) {
        root = insertNode(root, x);
    }

    void most_right() {
        int initial_lvl = -1;
        most_Right(root, 0, initial_lvl);
    }

private:
    Node* root;

    Node* insertNode(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->value) {
            node->left = insertNode(node->left, x);
        } else if (x > node->value) {
            node->right = insertNode(node->right, x);
        }
        return node;
    }

    void most_Right(Node* node, int level, int& initial_lvl) {
        if (!node) return;

        if (level > initial_lvl) {
            std::cout << node->value << " ";
            initial_lvl = level;
        }

        most_Right(node->right, level + 1, initial_lvl);
        most_Right(node->left, level + 1, initial_lvl);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    BST bst;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        bst.insert(x);
    }

    bst.most_right();
    return 0;
}*/

/*#include <iostream>
#include <stack>

using namespace std;

bool validateInOrder(int* inOrder, int n) {
    for (int i = 1; i < n; ++i) {
        if (inOrder[i - 1] > inOrder[i]) {
            return false;
        }
    }
    return true;
}

bool validatePreOrder(int* preOrder, int* inOrder, int n) {
    stack<int> s;
    int inIndex = 0;
    for (int i = 0; i < n; ++i) {
        s.push(preOrder[i]);
        while (!s.empty() && s.top() == inOrder[inIndex]) {
            s.pop();
            inIndex++;
        }
    }
    return inIndex == n;
}

bool validatePostOrder(int* postOrder, int* inOrder, int n) {
    stack<int> s;
    int inIndex = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        s.push(postOrder[i]);
        while (!s.empty() && s.top() == inOrder[inIndex]) {
            s.pop();
            inIndex--;
        }
    }
    return inIndex == -1;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;

    int* preOrder = new int[n];
    int* inOrder = new int[n];
    int* postOrder = new int[n];

    for (int i = 0; i < n; ++i) cin >> preOrder[i];
    for (int i = 0; i < n; ++i) cin >> inOrder[i];
    for (int i = 0; i < n; ++i) cin >> postOrder[i];

    if (!validateInOrder(inOrder, n)) {
        cout << "NO" << endl;
    } else {
        bool preValid = validatePreOrder(preOrder, inOrder, n);
        bool postValid = validatePostOrder(postOrder, inOrder, n);

        if (preValid && postValid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    delete[] preOrder;
    delete[] inOrder;
    delete[] postOrder;

    return 0;
}*/




/* #include <iostream>
#include <string>

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() : top(nullptr) {}

    void push(long long value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        Node *temp = top;
        int result = temp->data;
        top = top->next;
        delete temp;
        return result;
    }
};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n;
    Stack stack;
    std::string opper;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> opper;
        if (opper == "+") {
            long long x;
            std::cin >> x;
            stack.push(x);
        } else if (opper == "-"){
            std::cout << stack.pop() << '\n';
        }
    }
} */

/* #include <iostream>
#include <string>

struct Node {
    long long value;
    Node* next;
    Node(long long value) : value(value), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(long long value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
        }
        tail = newNode;
        if (!head) {
            head = newNode;
        }
    }

    long long pop() {
        long long value = head->value;
        Node* temp = head;
        head = head->next;

        delete temp;
        return value;
    }
};

int main() {

        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int n;
        std::cin >> n;
        std::string opper;
        Queue queue;

        for (int i = 0; i < n; i++) {
            std::cin >> opper;
            if (opper == "+") {
                long long x;
                std::cin >> x;
                queue.push(x);
            } else if (opper == "-") {
                std::cout << queue.pop() << '\n';

            }
        }
} */

/* #include <iostream>
#include <string>

void cSort(std::string arr[], int n, int k, int pos) {
    std::string output[n];
    int c[256] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i][k - pos - 1];
        c[index]++;
    }

    for (int i = 1; i < 256; i++) {
        c[i] += c[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = arr[i][k - pos - 1];
        output[c[index] - 1] = arr[i];
        c[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort_T(std::string arr[], int n, int k, int t) {
    for (int pos = 0; pos < t; pos++) {
        cSort(arr, n, k, pos);
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, k, t;
    std::cin >> n >> k >> t;

    std::string arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    radixSort_T(arr, n, k, t);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << '\n';
    }

    return 0;
} */

/* #include <iostream>

bool placing(int pos[], int N, int K, int min) {
    int c = 1;
    int last = pos[0];

    for (int i = 1; i < N; ++i) {
        if (pos[i] - last >= min) {
            c++;
            last = pos[i];
            if (c == K) return true;
        }
    }
    return false;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    int pos[N];

    for (int i = 0; i < N; ++i) {
        std::cin >> pos[i];
    }

    int low = 1;
    int high = pos[N - 1] - pos[0];
    int distance = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (placing(pos, N, K, mid)) {
            distance = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << distance;
} */

/*
#include <iostream>
using namespace std;

struct Node {
    int chislitel;
    int znamenatel;
    double value;
    Node(int chis, int znam, int* arr) : chislitel(chis), znamenatel(znam) {
        value = static_cast<double>(arr[chis]) / arr[znam];
    }
};

class Heap {
public:
    Node** heap;
    int size;
    int capacity;

    Heap(int cap) : size(0), capacity(cap) {
        heap = new Node*[capacity];
    }

    void push(Node* node) {
        heap[size] = node;
        int index = size++;
        while (index > 0 && heap[parent(index)]->value > heap[index]->value) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    Node* pop() {
        Node* minNode = heap[0];
        heap[0] = heap[--size];
        heapify(0);
        return minNode;
    }

    bool empty() const {
        return size == 0;
    }

private:
    int parent(int i) const {
        return (i - 1) / 2;
    }

    int left(int i) const {
        return 2 * i + 1;
    }

    int right(int i) const {
        return 2 * i + 2;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && heap[l]->value < heap[smallest]->value)
            smallest = l;
        if (r < size && heap[r]->value < heap[smallest]->value)
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
};

pair<int, int> quotient(int* arr, int n, int k) {
    Heap heap(n - 1);

    for (int i = 0; i < n - 1; i++) {
        heap.push(new Node(i, n - 1, arr));
    }

    for (int i = 1; i < k; i++) {
        Node* smallest = heap.pop();
        if (smallest->znamenatel - 1 > smallest->chislitel) {
            heap.push(new Node(smallest->chislitel, smallest->znamenatel - 1, arr));
        }
        delete smallest;
    }

    Node* result = heap.pop();
    pair<int, int> res = {arr[result->chislitel], arr[result->znamenatel]};
    delete result;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = quotient(arr, n, k);
    cout << result.first << " " << result.second;

    delete[] arr;
    return 0;
}*/

/*#include <iostream>
#include <map>
#include <cctype>
#include <string>

class Stack {
public:
    struct Node {
        std::map<char, int> data;
        Node* next;
        Node(const std::map<char, int>& data) : data(data), next(nullptr) {}
    };

    Node* top = nullptr;

    void push(const std::map<char, int>& value) {
        Node* node = new Node(value);
        node->next = top;
        top = node;
    }

    std::map<char, int> pop() {
        Node* temp = top;
        std::map<char, int> data = top->data;
        top = top->next;
        delete temp;
        return data;
    }

    std::map<char, int>& peek() {
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};


int digit(const std::string& s, int& i) {
    int num = 0;
    while (i < s.length() && std::isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        ++i;
    }
    return num == 0 ? 1 : num;
}


std::string unmake_formula(const std::string& formula) {
    Stack stack;
    stack.push({});

    int i = 0;
    while (i < formula.size()) {
        char current = formula[i];

        if (std::isalpha(current)) {
            i++;
            int count = (i < formula.size() && std::isdigit(formula[i])) ? digit(formula, i) : 1;
            stack.peek()[current] += count;
        } else if (current == '(') {
            stack.push({});
            i++;
        } else if (current == ')') {
            i++;
            int multiplier = digit(formula, i);
            std::map<char, int> top = stack.pop();
            for (auto& element : top) {
                stack.peek()[element.first] += element.second * multiplier;
            }
        }
    }

    std::map<char, int>& result_map = stack.peek();
    std::string result;
    for (auto& element : result_map) {
        result += element.first;
        if (element.second > 1) result += std::to_string(element.second);
    }

    return result;
}

int main() {
        std::string formula;
        std::cin >> formula;
        std::cout << unmake_formula(formula);
        return 0;
}*/

































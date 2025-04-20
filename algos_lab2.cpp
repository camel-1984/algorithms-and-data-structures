/* // 1
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int j = 1; j < n; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
} */

/* // 2
#include <iostream>
using namespace std;

int random_pivot(int arr[], int low, int high) {
    int pivot = low + rand() % (high - low + 1);

    swap(arr[pivot], arr[high]);

    return arr[high];
}
void quicksort(int arr[], int l, int r) {
    int i = l;
    int j = r;
    int pivot = random_pivot(arr, l, r);

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        quicksort(arr, l, j);
    }
    if (r > i) {
        quicksort(arr, i, r);
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int k = 0; k < n; k++) {
        cin >> a[k];
    }

    quicksort(a, 0, n - 1);

    for (int d = 0; d < n; d++) {
        cout << a[d] << " ";
    }
} */

/* // 3
#include <iostream>
using namespace std;

void antiquicksort(int arr[], int size) {
    for (int i = 2; i < size; i++) {
    int temp;
    temp = arr[i];
    arr[i] = arr[i / 2];
    arr[i / 2] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    antiquicksort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
} */

/* // 4
#include <iostream>
using namespace std;

void quicksort(pair<int, int> arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    pair<int, int> mid = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quicksort(arr, l, j);
    quicksort(arr, i, r);
}

int main() {
    int n;
    cin >> n;
    pair<int, int> arr[n];

    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        arr[i] = {start, end};
    }

    quicksort(arr, 0, n - 1);

    int c = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i].second >= arr[i + 1].first) {
            arr[i + 1].first = min(arr[i].first, arr[i + 1].first);
            arr[i + 1].second = max(arr[i].second, arr[i + 1].second);
            arr[i] = {0, 0};
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].first != 0 || arr[i].second != 0) {
            c += arr[i].second - arr[i].first + 1;
        }
    }
    cout << c;
} */

/* // 5
#include <iostream>
using namespace std;

void quicksortDescending(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (arr[i] > pivot) {
            i++;
        }
        while (arr[j] < pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quicksortDescending(arr, l, j);
    quicksortDescending(arr, i, r);
}

int main() {
    int n;
    cin >> n;

    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksortDescending(arr, 0, n - 1);

    long long maxsum = 0;
    int* sides = new int[n];
    int sidesCount = 0;

    int i = 0;
    while (i < n - 1) {
        if (arr[i] == arr[i + 1]) {
            sides[sidesCount++] = arr[i];
            i += 2;
        }
        else if (arr[i] - 1 == arr[i + 1]) {
            sides[sidesCount++] = arr[i] - 1;
            i += 2;
        }
        else {
            i += 1;
        }
    }

    if (sidesCount >= 2) {
        for (int j = 0; j < sidesCount - 1; j += 2) {
            maxsum += static_cast<long long>(sides[j]) * sides[j + 1];
        }
    } else {
        cout << 0;
        delete[] arr;
        delete[] sides;
        return 0;
    }
    cout << maxsum;

} */

/* // 6
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, long long& c) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            c += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right, long long& c) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, c);
        mergeSort(arr, mid + 1, right, c);
        merge(arr, left, mid, right, c);
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long c = 0;

    mergeSort(arr, 0, n - 1, c);

    cout << c;

    delete[] arr;
} */

/* // 7
#include <iostream>
using namespace std;

void quickSortRev(int arr[], int left, int right, int k) {
    int mid = arr[right];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] > mid) {
            i++;
        }
        while (arr[j] < mid) {
            j--;
        }
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j && j >= k - 1) {
        quickSortRev(arr, left, j, k);
    }
    if (i < right && i < k) {
        quickSortRev(arr, i, right, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int A, B, C, a1, a2;
    cin >> A >> B >> C >> a1 >> a2;
    int c[n];
    c[0] = a1;
    c[1] = a2;

    for (int i = 2; i < n; i++) {
        c[i] = c[i - 2] * A + c[i - 1] * B + C;
    }
    quickSortRev(c, 0, n - 1, k);
    int count = 0;
    for (int i = 0; i < k; i++) {
        count ^= c[i];
    }
    cout << count;
} */

// вставками (n^2 1) (n)
// квик (nlogn logn) (n)
// merge (nlogn n)
// last(nlogk logk) (n)


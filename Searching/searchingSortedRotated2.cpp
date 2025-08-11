#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int k) {
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k) return mid;

        // Check which part is sorted
        if (arr[start] <= arr[mid]) {
            // Left part sorted
            if (arr[start] <= k && k < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // Right part sorted
            if (arr[mid] < k && k <= arr[end]) {
                start = mid ;
            } else {
                end = mid - 1;
            }
        }
    }

    return start;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << searchInRotatedSortedArray(A, K) << endl;
    }
    return 0;
}

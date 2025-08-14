#include <iostream>
#include <vector>

using namespace std;

/*
Check if the k-th smallest element in a binary min-heap is >= x.
We count how many elements are < x by traversing the heap with pruning.
If count >= k -> the k-th smallest < x  -> answer is NO (not >= x).
If count <  k -> the k-th smallest >= x -> answer is YES.

Time: O(k) in the worst case (we visit at most k nodes before deciding).
*/

bool kthSmallestIsAtLeastX(const vector<double>& h, int k, double x) {
    if (k <= 0) return true;                 // vacuously true
    if (h.empty()) return true;              // no elements -> trivially >= x

    int n = (int)h.size();
    int countLess = 0;

    // DFS stack of indices to visit (only those potentially < x)
    vector<int> st;
    st.push_back(0); // start at root if it might be < x (we'll check inside)

    while (!st.empty() && countLess < k) {
        int i = st.back(); st.pop_back();
        if (i >= n) continue;

        if (h[i] < x) {
            ++countLess;
            if (countLess >= k) break;

            // children indices in array-heap
            int L = 2*i + 1, R = 2*i + 2;
            if (L < n) st.push_back(L);
            if (R < n) st.push_back(R);
        }
        // else (h[i] >= x) -> prune subtree: do nothing
    }

    // If we found at least k elements < x, then k-th smallest < x -> return false.
    // Otherwise, fewer than k elements are < x -> k-th smallest >= x -> return true.
    return countLess < k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<double> heap(n);
    for (int i = 0; i < n; ++i) cin >> heap[i];

    int k; 
    double x;
    cin >> k >> x;

    bool ok = kthSmallestIsAtLeastX(heap, k, x);
    cout << (ok ? "YES" : "NO") << "\n";
    return 0;
}

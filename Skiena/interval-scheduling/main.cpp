#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MIN

using namespace std;

/*
Interval Scheduling (Activity Selection)
- Greedy algorithm to select the maximum number of non-overlapping intervals
- Sort intervals by finishing time (ascending)
- Pick each interval that starts after the last selected interval finishes
- Time complexity: O(n log n) due to sorting
- Space complexity: O(n) for storing chosen intervals
*/

struct Interval {
    int s; // Start time
    int f; // Finish time

    // Sort intervals by finishing time ascending
    bool operator<(const Interval& other) const {
        if (f != other.f) return f < other.f;
        return s < other.s; // Tie-breaker: earlier start time first
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // Number of intervals

    vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].s >> intervals[i].f; // Read start and finish times
    }

    // Sort intervals by finish time
    sort(intervals.begin(), intervals.end());

    vector<Interval> chosen; // Store selected intervals
    int lastFinish = INT_MIN; // Finish time of last selected interval

    for (size_t i = 0; i < intervals.size(); ++i) {
        // If current interval starts after last selected finishes, choose it
        if (intervals[i].s >= lastFinish) {
            chosen.push_back(intervals[i]);
            lastFinish = intervals[i].f;
        }
    }

    // Output results
    cout << chosen.size() << "\n"; // Number of selected intervals
    for (size_t i = 0; i < chosen.size(); ++i) {
        cout << chosen[i].s << ' ' << chosen[i].f << "\n"; // Interval details
    }

    return 0;
}

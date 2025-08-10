#include <bits/stdc++.h>
using namespace std;

// Custom comparator: descending order
struct Descending {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    // Sample data: pairs of (x, y)
    vector<pair<int, int>> data = {
        {1, 5}, {2, 3}, {1, 2}, {2, 1}
    };

    // Custom comparator using a lambda function
    // This comparator sorts first by the first element ascending,
    // and if they are equal, by the second element descending.
    sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first; // ascending on first
        } else {
            return a.second > b.second; // descending on second
        }
    });

    set<int, Descending> s;

    priority_queue<int, std::vector<int>, Descending> pq;

    return 0;
}

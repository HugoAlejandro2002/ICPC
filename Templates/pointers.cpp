#include <bits/stdc++.h>
using namespace std;

int main() {
    // Sorting
    vector<int> v = {1, 3, 5, 7, 9, 11};
    sort(v.begin(), v.end());

    int n = 6;
    int arr[n] = {1, 3, 5, 7, 9, 11};
    sort(arr,arr+n);
    
    // For lower_bound, upper_bound, binary_search -> container must be sorted
    int val = 6;
    // lower_bound: first element >= val
    auto it_low = lower_bound(v.begin(), v.end(), val); 
    if (it_low != v.end()) cout << "Lower bound: " << *it_low << endl;

    // upper_bound: first element > val
    auto it_up = upper_bound(v.begin(), v.end(), val);
    if (it_up != v.end()) cout << "Upper bound: " << *it_up << endl;

    // binary_search: returns true if val exists
    bool found = binary_search(v.begin(), v.end(), val);
    cout << "Binary search: " << (found ? "Found" : "Not found") << endl;

    // iterator operations (only in random access containers like vector, deque, array)
    auto it = v.begin();
    it++; // allowed: moves forward
    cout << "it++: " << *it << endl;

    auto nxt = next(it); // allowed: moves iterator forward by 1 (or n)
    auto prv = prev(it); // allowed: moves iterator back by 1 (or n)

    cout << "Next: " << *nxt << ", Prev: " << *prv << endl;

    int d = distance(v.begin(), it); // allowed: gives index difference
    cout << "Distance from begin: " << d << endl;

    // Accessing last element < val, for <= use upper_bound
    if (it_low != v.begin()) {
        auto le = prev(it_low);
        cout << "Last element <= val: " << *le << endl;
    }

    return 0;
}

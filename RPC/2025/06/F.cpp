#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // We'll count how many numbers have exponent b (i.e., value = 2^b).
    // After that, merging two 2^b gives one 2^(b+1): like binary carry.
    vector<long long> cnt(200, 0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        // Parse input (a power of two ≤ 2^100) into a 128‐bit integer
        unsigned __int128 x = 0;
        for (char c : s) {
            x = x * 10 + (c - '0');
        }
        // Compute exponent b such that x == 2^b
        int b = 0;
        while (x > 1) {
            x >>= 1;
            ++b;
        }
        cnt[b]++;
    }

    // Simulate merges: at each level b, floor(cnt[b]/2) pairs merge into b+1
    for (int b = 0; b + 1 < (int)cnt.size(); ++b) {
        cnt[b + 1] += cnt[b] / 2;
    }

    // Find highest b with at least one tile remaining
    int final_exp = 0;
    for (int b = (int)cnt.size() - 1; b >= 0; --b) {
        if (cnt[b] > 0) {
            final_exp = b;
            break;
        }
    }

    // Compute 2^final_exp using 128‐bit and print in decimal
    unsigned __int128 res = (unsigned __int128)1 << final_exp;
    if (res == 0) {
        cout << "0\n";
        return 0;
    }
    string out;
    while (res > 0) {
        out.push_back(char('0' + (res % 10)));
        res /= 10;
    }
    reverse(out.begin(), out.end());
    cout << out << "\n";
    return 0;
}

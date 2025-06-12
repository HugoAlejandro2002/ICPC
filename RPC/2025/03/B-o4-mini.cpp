#include <bits/stdc++.h>
using namespace std;
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int n;
long double p;
cin >> n >> p;
const long double EPS = 1e-12;
vector<pair<long double, long double>> pos, neg;
long double sum_zero = 0.0;
for (int i = 0; i < n; i++) {
    long double ci, pi;
    cin >> ci >> pi;
    long double diff = pi - p;
    if (fabsl(diff) <= EPS) {
        sum_zero += ci;
    } else if (diff > 0) {
        pos.emplace_back(diff, ci);
    } else {
        neg.emplace_back(-diff, ci);
    }
}
long double S_pos_max = 0.0, S_neg_max = 0.0;
for (auto &pr : pos) S_pos_max += pr.first * pr.second;
for (auto &pr : neg) S_neg_max += pr.first * pr.second;
long double S = min(S_pos_max, S_neg_max);
long double total = sum_zero;
if (S_pos_max <= S_neg_max) {
    long double total_pos = 0.0;
    for (auto &pr : pos) total_pos += pr.second;
    total += total_pos;
    long double S_rem = S;
    sort(neg.begin(), neg.end(), [](auto &a, auto &b){ return a.first < b.first; });
    long double total_neg = 0.0;
    for (auto &pr : neg) {
        long double dj = pr.first, ci = pr.second;
        long double max_contrib = dj * ci;
        if (S_rem > max_contrib - EPS) {
            S_rem -= max_contrib;
            total_neg += ci;
        } else {
            long double needed_ci = S_rem / dj;
            total_neg += needed_ci;
            break;
        }
    }
    total += total_neg;
} else {
    long double total_neg = 0.0;
    for (auto &pr : neg) total_neg += pr.second;
    total += total_neg;
    long double S_rem = S;
    sort(pos.begin(), pos.end(), [](auto &a, auto &b){ return a.first < b.first; });
    long double total_pos = 0.0;
    for (auto &pr : pos) {
        long double dj = pr.first, ci = pr.second;
        long double max_contrib = dj * ci;
        if (S_rem > max_contrib - EPS) {
            S_rem -= max_contrib;
            total_pos += ci;
        } else {
            long double needed_ci = S_rem / dj;
            total_pos += needed_ci;
            break;
        }
    }
    total += total_pos;
}
cout << fixed << setprecision(10) << (double)total << "\n";
return 0;
}
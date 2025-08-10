#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort by end time (second of pair)
    sort(movies.begin(), movies.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    int count = 0;
    int current_end = 0;

    for (auto& [start, end] : movies) {
        if (start >= current_end) {
            ++count;
            current_end = end;
        }
    }

    cout << count << endl;
    return 0;
}

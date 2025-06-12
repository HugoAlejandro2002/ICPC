#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sweep_max(const vector<pair<ll,int>>& evs) {
    // ev.first = coordenada, ev.second = +1 (inicio) o -1 (fin)
    vector<pair<ll,int>> v = evs;
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first < b.first;
        // en igual coordenada, procesar +1 antes que -1 para intervalos cerrados
        return a.second > b.second;
    });
    int cur = 0, best = 0;
    for (auto &e : v) {
        cur += e.second;
        best = max(best, cur);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll A, B, C;
    cin >> n >> A >> B >> C;

    vector<pair<ll,int>> ex, ey, ez;
    ex.reserve(2*n);
    ey.reserve(2*n);
    ez.reserve(2*n);

    for (int i = 0; i < n; i++) {
        ll x1,y1,z1, x2,y2,z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // eje X
        {
            ll l = min(x1,x2), r = max(x1,x2);
            ex.emplace_back(l, +1);
            ex.emplace_back(r, -1);
        }
        // eje Y
        {
            ll l = min(y1,y2), r = max(y1,y2);
            ey.emplace_back(l, +1);
            ey.emplace_back(r, -1);
        }
        // eje Z
        {
            ll l = min(z1,z2), r = max(z1,z2);
            ez.emplace_back(l, +1);
            ez.emplace_back(r, -1);
        }
    }

    int best_x = sweep_max(ex);
    int best_y = sweep_max(ey);
    int best_z = sweep_max(ez);

    cout << max({best_x, best_y, best_z}) << "\n";
    return 0;
}
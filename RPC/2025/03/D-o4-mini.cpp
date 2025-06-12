#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> reservations(n);
    vector<pair<int,int>> shifts(m);
    vector<int> coords;
    coords.reserve(2*(n+m));

    // Read reservations, collect events l, r+1
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        reservations[i] = {l, r};
        coords.push_back(l);
        coords.push_back(r + 1);
    }
    // Read shifts, collect events l, r+1
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        shifts[i] = {l, r};
        coords.push_back(l);
        coords.push_back(r + 1);
    }

    // Coordinate compress
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int M = coords.size();

    // Difference arrays for A(t), W(t)
    vector<int> dA(M, 0), dW(M, 0);

    // Fill dA
    for(auto &pr : reservations){
        int l = pr.first, r = pr.second;
        int iL = int(lower_bound(coords.begin(), coords.end(), l) - coords.begin());
        int iR = int(lower_bound(coords.begin(), coords.end(), r+1) - coords.begin());
        dA[iL] ++;
        dA[iR] --;
    }
    // Fill dW
    for(auto &pr : shifts){
        int l = pr.first, r = pr.second;
        int iL = int(lower_bound(coords.begin(), coords.end(), l) - coords.begin());
        int iR = int(lower_bound(coords.begin(), coords.end(), r+1) - coords.begin());
        dW[iL] ++;
        dW[iR] --;
    }

    // Build L[i] = ceil(A_i / W_i) on each segment [coords[i], coords[i+1]-1]
    int S = M - 1;            // number of segments
    vector<int> L(S);
    int cumA = 0, cumW = 0;
    for(int i = 0; i < S; i++){
        cumA += dA[i];
        cumW += dW[i];
        if(cumW > 0){
            L[i] = (cumA + cumW - 1) / cumW;  // ceil division
        } else {
            L[i] = 0;
        }
    }

    // Build a segment tree for RMQ(max) over L[0..S-1]
    int N0 = 1;
    while(N0 < S) N0 <<= 1;
    vector<int> seg(2*N0, 0);
    for(int i = 0; i < S; i++){
        seg[N0 + i] = L[i];
    }
    for(int i = N0 - 1; i >= 1; i--){
        seg[i] = max(seg[2*i], seg[2*i + 1]);
    }

    // RMQ query [l..r] inclusive
    auto rmq = [&](int l, int r){
        int res = 0;
        l += N0;  r += N0;
        while(l <= r){
            if(l & 1) res = max(res, seg[l++]);
            if(!(r & 1)) res = max(res, seg[r--]);
            l >>= 1;  r >>= 1;
        }
        return res;
    };

    // Answer each shift
    // For shift [l,r]: segments from
    //   i_l = upper_bound(coords, l) - 1
    //   i_r = upper_bound(coords, r) - 1
    // and take max over [i_l, i_r].
    string output = "";
    for(auto &sh : shifts){
        int l = sh.first, r = sh.second;
        int iL = int(upper_bound(coords.begin(), coords.end(), l) - coords.begin()) - 1;
        int iR = int(upper_bound(coords.begin(), coords.end(), r) - coords.begin()) - 1;
        if(iL < 0) iL = 0;
        if(iR < 0) iR = 0;
        if(iL >= S) iL = S - 1;
        if(iR >= S) iR = S - 1;
        int ans = 0;
        if(iL <= iR) ans = rmq(iL, iR);
        output += (ans + " ");
    }

    cout << output;
    return 0;
}
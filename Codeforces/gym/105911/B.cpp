#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n, m;
vector<string> A;
int idx(int x,int y){ return x*m + y; }
pii rev(int v){ return {v/m, v%m}; }

// DSU for good spanning tree
struct DSU {
    vector<int> p;
    DSU(int N): p(N, -1) {}
    int find(int x){ return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int a,int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a,b);
        p[a] += p[b]; p[b] = a;
        return true;
    }
};

vector<vector<int>> tree;
vector<int> parent;
vector<vector<int>> B0, B1;
int next0 = 1, next1 = 1;

void placeL(int a,int b,int c) {
    for(int v : {a,b,c}){
        auto [x,y] = rev(v);
        B0[x][y] = next0;
    }
    next0++;
}
void placeDom(int a,int b) {
    for(int v : {a,b}){
        auto [x,y] = rev(v);
        B1[x][y] = next1;
    }
    next1++;
}
void placeMono(int a) {
    auto [x,y] = rev(a);
    B0[x][y] = next0++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    A.resize(n);
    for(int i=0;i<n;i++) cin >> A[i];
    int N = n*m;
    // build good tree via DSU
    DSU dsu(N);
    parent.assign(N, -1);
    tree.assign(N, {});
    // vertical edges top-down
    for(int j=0;j<m;j++) for(int i=0;i+1<n;i++){
        if(A[i][j]=='1' && A[i+1][j]=='1'){
            int u=idx(i,j), v=idx(i+1,j);
            if(dsu.unite(u,v)){
                parent[v]=u;
                tree[u].push_back(v);
            }
        }
    }
    // horizontal edges alternating
    for(int i=0;i<n;i++){
        bool lr = (i%2==0);
        if(lr){
            for(int j=0;j+1<m;j++){
                if(A[i][j]=='1'&&A[i][j+1]=='1'){
                    int u=idx(i,j), v=idx(i,j+1);
                    if(dsu.unite(u,v)){
                        parent[v]=u;
                        tree[u].push_back(v);
                    }
                }
            }
        } else {
            for(int j=m-2;j>=0;j--){
                if(A[i][j]=='1'&&A[i][j+1]=='1'){
                    int u=idx(i,j+1), v=idx(i,j);
                    if(dsu.unite(u,v)){
                        parent[v]=u;
                        tree[u].push_back(v);
                    }
                }
            }
        }
    }
    // find root
    int root = -1;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(A[i][j]=='1'){
        int u=idx(i,j);
        if(parent[u]<0) { root=u; break; }
    }
    // prepare layers
    B0.assign(n, vector<int>(m,0));
    B1.assign(n, vector<int>(m,0));
    // post-order
    vector<int> order;
    order.reserve(N);
    {
        vector<int> st{root};
        vector<int> it(N,0);
        while(!st.empty()){
            int u=st.back();
            if(it[u] < (int)tree[u].size()){
                st.push_back(tree[u][it[u]++]);
            } else {
                order.push_back(u);
                st.pop_back();
            }
        }
    }
    // bottom-up pairing
    vector<vector<int>> pend(N);
    for(int u : order){
        auto &S = pend[u];
        // collect from children
        for(int v: tree[u]){
            if(!pend[v].empty()){
                S.push_back(pend[v][0]);
                pend[v].clear();
            }
        }
        // pair L
        while(S.size()>=2){
            int x=S.back(); S.pop_back();
            int y=S.back(); S.pop_back();
            placeL(x,u,y);
        }
        if(S.size()==1){
            int z=S.back(); S.pop_back();
            placeDom(z,u);
            // u still needs layer0 coverage
            if(u!=root) pend[u].push_back(u);
        } else {
            // no child single: pend u for layer0
            if(u!=root) pend[u].push_back(u);
        }
        // root final
        if(u==root){
            if(pend[u].size()==1){
                // place monomino at root for layer0
                placeMono(root);
                pend[u].clear();
            }
        }
    }
    // output
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<B0[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<B1[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
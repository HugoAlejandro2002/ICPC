#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m; // number of nodes and edges
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        vector<int> adj[n+1];
        bool visited[n+1];

        int kidx[n+1][n+1];
        int k[m];
        memset(visited,0,sizeof visited);
        memset(k,-1,sizeof k);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            // assuming undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
            kidx[u][v] = i;
            kidx[v][u] = i;
        }

        vector<set<int>> paths(2);

        int start=1;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if(k[kidx[u][v]]==-1){
                    for (int i = 1; i < paths.size(); i++)
                    {
                        if(paths[i].find(u)!=paths[i].end()){
                            if(paths[i].find(v)!=paths[i].end()){
                                k[kidx[u][v]]=i;
                                break;
                            } else if (paths[i].size()<n-1){
                                paths[i].insert(v);
                                k[kidx[u][v]]=i;
                                break;
                            }
                        } else if (paths[i].find(v)!=paths[i].end()) {
                            if(paths[i].size()<n-1){
                                paths[i].insert(u);
                                k[kidx[u][v]]=i;
                                break;
                            }
                        } else{
                            if(paths[i].size()<n-2){
                                paths[i].insert(u);
                                paths[i].insert(v);
                                k[kidx[u][v]]=i;
                                break;
                            }
                        }
                    }

                    if(k[kidx[u][v]]==-1){
                        set<int> s({u,v});
                        paths.push_back(s);
                        k[kidx[u][v]]=paths.size()-1;
                    }
                }
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout<<paths.size()-1<<'\n';
        for (int i = 0; i < m-1; i++)
        {
            cout<<k[i]<<" ";
        }
        cout<<k[m-1]<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << endl

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAXN = 1005;
int n, m;
char grid[MAXN][MAXN];    // input grid (e.g. '.' = open, '#' = wall)
bool visited[MAXN][MAXN]; // visited cells
int distM[MAXN][MAXN];    // distance from start
int dist[MAXN][MAXN];     // distance from start
int dirs[MAXN][MAXN];     // distance from start

queue<ii> q;
// 4 possible directions (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char ins[] = {'L', 'R', 'U', 'D'};
ii a;
string path;

void bfsM()
{
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // check bounds and validity
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !visited[ny][nx] && grid[ny][nx] != '#')
            {

                visited[ny][nx] = true;
                distM[ny][nx] = distM[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfs(int sx, int sy)
{
    visited[sy][sx] = true;
    dist[sy][sx] = 0;
    q.push({sx, sy});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // check bounds and validity
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !visited[ny][nx] && grid[ny][nx] != '#')
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                if (distM[ny][nx]==-1 || dist[ny][nx] < distM[ny][nx])
                {
                    dirs[ny][nx] = dir;
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1)
                    {
                        int cx=nx, cy=ny;
                        while (cx!=a.first || cy!=a.second)
                        {
                            int ndir = dirs[cy][cx];
                            path+=ins[ndir];
                            cx = cx - dx[ndir];
                            cy = cy - dy[ndir];
                        }
                        
                        return 1;
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
    return 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;
    // read the grid
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    memset(visited, 0, sizeof visited);
    memset(dist, -1, sizeof dist);
    memset(distM, -1, sizeof distM);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'M'){
                distM[i][j]=0;
                visited[i][j]=1;
                q.push({j, i});
            }
            if (grid[i][j] == 'A'){
                dist[i][j]=0;
                if (j == 0 || j == m - 1 || i == 0 || i == n - 1){
                    cout << "YES\n0\n";
                    return 0;
                }
                a = {j, i};
            }
        }
    }
    bfsM();
    memset(visited, 0, sizeof visited);
    if (bfs(a.first, a.second))
    {
        cout << "YES\n";
        cout<<path.size()<<'\n';
        reverse(path.begin(), path.end());
        cout<<path<<'\n';
        
    }
    else
    {
        cout << "NO\n";
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout<<distM[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    return 0;
}

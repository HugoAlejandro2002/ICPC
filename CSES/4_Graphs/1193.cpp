#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

const int MAXN = 1005;
int n, m;
char grid[MAXN][MAXN];    // input grid (e.g. '.' = open, '#' = wall)
bool visited[MAXN][MAXN]; // visited cells
int dist[MAXN][MAXN];     // distance from start

string path;

// 4 possible directions (left, right, up, down)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char ins[] = {'R', 'L', 'D', 'U'};
ii fin;

bool bfs(int sx, int sy)
{
    queue<ii> q;
    visited[sy][sx] = true;
    dist[sy][sx] = 0;
    q.push({sx, sy});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (grid[y][x] == 'B')
        {
            fin = {x, y};
            return 1;
        }

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
                q.push({nx, ny});
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    // read the grid
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    memset(visited, 0, sizeof visited);
    memset(dist, 0, sizeof dist);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                if (bfs(j, i))
                {
                    int x = fin.first;
                    int y = fin.second;

                    while (y != i || x != j)
                    {
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                                grid[ny][nx] != '#' && dist[ny][nx]==dist[y][x]-1)
                            {
                                path+=ins[dir];
                                x = nx;
                                y = ny;
                                break;
                            }
                        }
                    }
                    cout << "YES\n";
                    reverse(path.begin(), path.end());
                    cout << path.size() << '\n';
                    cout << path << '\n';
                }
                else
                {
                    cout << "NO\n";
                }
                return 0;
            }
        }
    }

    return 0;
}

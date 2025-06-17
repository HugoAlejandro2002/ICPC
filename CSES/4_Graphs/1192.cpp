#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

const int MAXN = 1005;
int n, m;
char grid[MAXN][MAXN];       // input grid (e.g. '.' = open, '#' = wall)
bool visited[MAXN][MAXN];    // visited cells
int rooms = 0;

// 4 possible directions (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy) {
    rooms++;
    queue<ii> q;
    visited[sy][sx] = true;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // check bounds and validity
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !visited[ny][nx] && grid[ny][nx] == '.') {
                
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    // read the grid
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    memset(visited, 0, sizeof visited);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j]=='.')
                bfs(j, i);
        }
    }

    cout<<rooms<<'\n';

    return 0;
}

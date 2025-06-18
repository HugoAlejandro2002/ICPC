#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAXN = 1005;
int n, m; // n rows and m columns

char grid[MAXN][MAXN];       // input grid (e.g. '.' = open, '#' = wall)
bool visited[MAXN][MAXN];    // visited cells
int dist[MAXN][MAXN];        // distance from start

// 4 possible directions (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// O(n*m)
void bfs(int sx, int sy) {
    queue<ii> q;
    visited[sy][sx] = true;
    dist[sy][sx] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // check bounds and validity
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !visited[ny][nx] && grid[ny][nx] != '#') {
                
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
}

// O(n*m)
void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return; // out of bounds
    if (visited[y][x] || grid[y][x] == '#') return; // visited or wall

    visited[y][x] = true;

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    // read the grid
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    memset(visited, 0, sizeof visited);
    memset(dist, -1, sizeof dist);

    int sx, sy;
    cin >> sx >> sy; // start position (0-indexed)

    bfs(sx, sy);

    // print distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j])
                cout << dist[i][j] << ' ';
            else
                cout << "-1 ";
        }
        cout << '\n';
    }

    return 0;
}

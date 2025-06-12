#include <bits/stdc++.h>
using namespace std;

#define input freopen("K.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

// int r, c, m, n, w, even, odd;
int n, m, sol;
char grafo[1001][1001];
bool v[1001][1001];

void imprimirMatriz()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int nodoX, int nodoY)
{
    // int a = 0, b = 8;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // if (m == 0 || n == 0)
    //     b = 4;
    // if (m == n)
    // {
    //     a = 2;
    //     b = 6;
    // }
    v[nodoY][nodoX] = 1;

    queue<pair<int, int>> cola;
    cola.push(make_pair(nodoX, nodoY));
    // grafo[nodoX][nodoY] = 1;
    // nivel[nodoX][nodoY] = 0;
    while (!cola.empty())
    {
        pair<int, int> actual = cola.front();
        cola.pop();
        int x = actual.first;
        int y = actual.second;
        // printf("aaqui x:%d y:%d\n", x, y);

        if (grafo[y][x] != '.' && grafo[y][x] != 'S')
        {
            // printf("aaahahsh\n");
            int tes = grafo[y][x] - '0';
            // show(tes);
            sol += tes;
        }

        bool hayT = false;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !v[ny][nx] && grafo[ny][nx] == 'T')
            {
                // grafo[x][y]++;
                // if (grafo[nx][ny] == -1)
                // {
                //     grafo[nx][ny] = 0;
                //     cola.push(make_pair(nx, ny));
                // }
                // printf("hay T x:%d y:%d\n", nx, ny);

                hayT = 1;
                break;
            }
        }

        if (hayT)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grafo[ny][nx] != '#' && !v[ny][nx])
            {
                // grafo[x][y]++;
                // if (grafo[nx][ny] == -1)
                // {
                //     grafo[nx][ny] = 0;
                v[ny][nx] = 1;
                cola.push(make_pair(nx, ny));
                // }
                // hayT = 1;
                // break;
            }
        }
    }
}

int main()
{
    // input;
    while (cin >> n)
    {
        cin >> m;
        sol = 0;
        pii inicial;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grafo[i][j];
                if (grafo[i][j] == 'S')
                    inicial = {j, i};
            }
        }

        memset(v, 0, sizeof v);

        // imprimirMatriz();
        bfs(inicial.first, inicial.second);
        printf("%d\n", sol);
        // bfs(0, 0);
        // imprimirMatriz();
        // cout << "Case " << caso << ": " << even << " " << odd << endl;

    }
    return 0;
}
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;

int maxX = 0;
int maxY = 0;

bool matriz[2001][2001];
int maxArea = 0;

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

void bfs()
{
    int areas = 0;
    queue<pair<int, int>> cola;
    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX; j++)
        {
            // if (matriz[i][j] && !visitado[i][j])
            if (!matriz[i][j])
            {
                areas++;
                int area = 0;
                pair<int, int> nodoActual;
                matriz[i][j] = 1;
                cola.push(make_pair(i, j));
                while (!cola.empty())
                {
                    nodoActual = cola.front();
                    cola.pop();

                    int actX = nodoActual.second;
                    int actY = nodoActual.first;

                    //printf("%d %d\n", actY, actX);

                    for (int d = 0; d < 4; d++)
                    {
                        int x = actX + dirX[d];
                        int y = actY + dirY[d];
                        if (x < 0 || y < 0 || x >= maxX || y >= maxY)
                        {
                            continue;
                        }

                        // if (matriz[y][x] && !visitado[y][x])
                        if (!matriz[y][x])
                        {
                            matriz[y][x] = 1;
                            // printf("a la cola: %d %d\n",y,x);
                            cola.push(make_pair(y, x));
                        }
                    }

                    // matriz[actY][actX] = 1;
                    if (actX % 2 == 0 && actY % 2 == 0)
                    {
                        // printf("contando: %d %d\n", actY, actX);
                        area++;
                    }
                }

                if (areas > 1 && area > maxArea)
                {
                    maxArea = area;
                    // printf("%d\n", maxArea);
                }

                // for (int i = 0; i < maxY; i++)
                // {
                //     for (int j = 0; j < maxX; j++)
                //     {
                //         printf("%d ", matriz[i][j]);
                //     }
                //     printf("\n");
                // }
            }
        }
    }
    // printf("areas: %d\n", areas);
}

int main()
{
    input;
    int n, x0, y0, x, y;
    memset(matriz, 0, sizeof(matriz));

    scanf("%d", &n);
    scanf("%d %d", &x0, &y0);
    x0 = 2 * x0 - 1;
    y0 = 2 * y0 - 1;

    // printf("todo ok?");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        x = 2 * x - 1;
        y = 2 * y - 1;
        if (x > maxX)
            maxX = x + 2;
        if (y > maxY)
            maxY = y + 2;

        // int actual = (x0 == x);

        if (x0 == x)
        {
            for (int punt = y0; punt != y; punt += (y > y0) ? 1 : -1)
            {
                matriz[punt][x] = 1;
            }
        }
        else
        {
            for (int punt = x0; punt != x; punt += (x > x0) ? 1 : -1)
            {
                matriz[y][punt] = 1;
            }
        }
        matriz[y][x] = 1;

        x0 = x;
        y0 = y;
    }

    // printf("MaxX: %d\n", maxX);
    // printf("MaxY: %d\n", maxY);

    // for (int i = 0; i < maxY; i++)
    // {
    //     for (int j = 0; j < maxX; j++)
    //     {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    bfs();

    printf("%d", maxArea);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printMatrix(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}

struct SegmentTree2D {
    int n, m;
    vector<vector<long long>> tree;

    SegmentTree2D(int rows, int cols) : n(rows), m(cols) {
        tree.assign(4 * n, vector<long long>(4 * m, 0));
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry, const vector<vector<int>> &a) {
        if (ly + 1 == ry) {
            if (lx + 1 == rx) {
                tree[vx][vy] = a[lx][ly];
            } else {
                tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
            }
            return;
        }
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my, a);
        build_y(vx, lx, rx, vy*2+1, my, ry, a);
        tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
    }

    void build_x(int vx, int lx, int rx, const vector<vector<int>> &a) {
        if (lx + 1 != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx, a);
            build_x(vx*2+1, mx, rx, a);
        }
        build_y(vx, lx, rx, 1, 0, m, a);
    }

    long long query_y(int vx, int vy, int ly, int ry, int y1, int y2) {
        if (y2 <= ly || ry <= y1) return 0;
        if (y1 <= ly && ry <= y2) return tree[vx][vy];
        int my = (ly + ry) / 2;
        return query_y(vx, vy*2, ly, my, y1, y2) +
               query_y(vx, vy*2+1, my, ry, y1, y2);
    }

    long long query_x(int vx, int lx, int rx, int x1, int x2, int y1, int y2) {
        if (x2 <= lx || rx <= x1) return 0;
        if (x1 <= lx && rx <= x2) {
            return query_y(vx, 1, 0, m, y1, y2);
        }
        int mx = (lx + rx) / 2;
        return query_x(vx*2, lx, mx, x1, x2, y1, y2) +
               query_x(vx*2+1, mx, rx, x1, x2, y1, y2);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int val) {
        if (ly + 1 == ry) {
            if (lx + 1 == rx) {
                tree[vx][vy] = val;
            } else {
                tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
            }
            return;
        }
        int my = (ly + ry) / 2;
        if (y < my) update_y(vx, lx, rx, vy*2, ly, my, x, y, val);
        else update_y(vx, lx, rx, vy*2+1, my, ry, x, y, val);
        tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
    }

    void update_x(int vx, int lx, int rx, int x, int y, int val) {
        if (lx + 1 != rx) {
            int mx = (lx + rx) / 2;
            if (x < mx) update_x(vx*2, lx, mx, x, y, val);
            else update_x(vx*2+1, mx, rx, x, y, val);
        }
        update_y(vx, lx, rx, 1, 0, m, x, y, val);
    }

    long long query(int x1, int y1, int x2, int y2) {
        return query_x(1, 0, n, x1, x2, y1, y2);
    }

    void update(int x, int y, int val) {
        update_x(1, 0, n, x, y, val);
    }

};
// Example usage
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> matrix(n, vector<int>(n));
    string line;
    for (auto& row : matrix)
    {
        cin >> line;
        for (int i = 0; i < n; i++)
        {
            if (line[i] == '*')
            {
                row[i] = 1;
            }
        }
    }

    // printMatrix(matrix);

    SegmentTree2D st(n,n);
    st.build_x(1, 0, n, matrix);

    int y1, y2, x1, x2;

    while (q--)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << st.query(y1-1,x1-1,y2,x2) << '\n';
    }

    return 0;
}

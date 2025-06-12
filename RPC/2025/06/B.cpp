#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    long double s;
    cin >> m >> n >> k >> s;
    int N = m + n;
    vector<long double> A(N);
    for(int i = 0; i < m; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> A[m + i];

    // 1) Ordenar abscisas
    sort(A.begin(), A.end());

    // 2) Prefijos de suma y suma de cuadrados
    vector<long double> S1(N+1, 0.0L), S2(N+1, 0.0L);
    for(int i = 1; i <= N; i++){
        S1[i] = S1[i-1] + A[i-1];
        S2[i] = S2[i-1] + A[i-1]*A[i-1];
    }

    // No necesitamos más clusters que puntos
    k = min(k, N);

    // dp[c][j]: mínimo SSE horizontal usando c clusters para los primeros j puntos
    const long double INF = 1e300L;
    vector<vector<long double>> dp(k+1, vector<long double>(N+1, INF));

    // Caso base: 1 cluster para j puntos
    for(int j = 1; j <= N; j++){
        long double sum_x  = S1[j] - S1[0];
        long double sum_x2 = S2[j] - S2[0];
        long double len    = j;
        dp[1][j] = sum_x2 - sum_x*sum_x/len;
    }

    // Transición
    for(int c = 2; c <= k; c++){
        for(int j = c; j <= N; j++){
            long double best = INF;
            // probamos cortar antes en t
            for(int t = c-1; t < j; t++){
                long double len    = j - t;
                long double sum_x  = S1[j] - S1[t];
                long double sum_x2 = S2[j] - S2[t];
                long double cost   = sum_x2 - sum_x*sum_x/len;
                best = min(best, dp[c-1][t] + cost);
            }
            dp[c][j] = best;
        }
    }

    // SSE horizontal óptimo + constante vertical
    long double horizontalSSE = dp[k][N];
    long double verticalConst = (long double)N * s * s / 4.0L;
    long double ans = horizontalSSE + verticalConst;

    cout << fixed << setprecision(8) << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXF = 1000000;  // máximo total de posiciones sobre todos los casos

ll fac[MAXF+1], ifac[MAXF+1];

// cálculo rápido de a^e mod (e puede ser MOD-2 para inverso)
ll modexp(ll a, ll e = MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

// Precomputar factoriales e inversos factoriales hasta MAXF
void init_factorials() {
    fac[0] = 1;
    for (int i = 1; i <= MAXF; i++)
        fac[i] = fac[i-1] * i % MOD;
    ifac[MAXF] = modexp(fac[MAXF]);             // (MAXF!)^{-1}
    for (int i = MAXF; i > 0; i--)
        ifac[i-1] = ifac[i] * i % MOD;          // (i-1)!^{-1} = i!^{-1} * i
}

// Binomial nCk mod
ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_factorials();

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        // Guardar posiciones de los '1'
        vector<int> pos1;
        pos1.reserve(n);
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                pos1.push_back(i);

        int ones = pos1.size();
        // Si hay menos de k '1's, no hay subsegmento válido
        if (ones < k) {
            cout << 0 << "\n";
            continue;
        }

        ll ans = 0;
        // Recorremos cada uno de los unos como posible "último" en el bloque
        for (int i = 0; i < ones; i++) {
            // k1 = cuántos unos estoy tomando de atrás (máximo k, pero no más que (i+1) disponibles)
            int k1 = min(k, i+1);

            // L = índice de la '1' que queda justo fuera a la izquierda, o -1 si no hay
            int L = (i >= k ? pos1[i-k] : -1);
            // R = índice de la '1' que queda justo fuera a la derecha, o n si no hay
            int R = (i+1 < ones ? pos1[i+1] : n);

            // Número total de posiciones entre (L, R) excluyendo L y R es (R - L - 1).
            // De esas posiciones elegimos k1 para poner unos:
            ans = (ans + C(R - L - 1, k1)) % MOD;

            // Restamos las configuraciones en las que el i-ésimo '1' ocupa
            // alguna de las k1 posiciones ANTERIORES a su posición original,
            // pues ya las contaríamos cuando él mismo llegaba justo a pos1[i].
            ans = (ans - C(pos1[i] - L - 1, k1 - 1) + MOD) % MOD;
        }

        // +1 para contar la cadena sin modificar
        ans = (ans + 1) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
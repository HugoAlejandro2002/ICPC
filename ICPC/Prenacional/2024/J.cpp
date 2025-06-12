#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long super_alfil_formula_adjusted(long long n, long long m) {
    long long r = gcd(n - 1, m - 1);
    long long a = (n - 1) / r;
    long long b = (m - 1) / r;
    
    long long term1 = b * (n - 1);
    long long term2 = 1;
    long long term3 = (a - 1) * (b - 1) / 2;
    long long correction = term1 + term2 - term3;
    
    long long visited_casillas = n * m - correction;
    return visited_casillas;
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        cout << super_alfil_formula_adjusted(n, m) << endl;
    }
    return 0;
}
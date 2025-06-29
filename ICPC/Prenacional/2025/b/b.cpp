#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)

int main() {
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n;
    cin >> n;
    set<char> vert{'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
    set<char> hor{'B', 'C', 'D', 'E', 'H', 'I', 'K', 'O', 'X'};
    vector<int> prefv;
    vector<int> prefh;
    prefv.push_back(0);
    prefh.push_back(0);
    long vertc = 0;
    long horc = 0;
    for (int i = 0; i < s.length(); i++) {
        if (vert.count(s[i])) {
            vertc++;
        }
        if (hor.count(s[i])) {
            horc++;
        }
        // if s[i] in hor:
        prefv.push_back(vertc);
        prefh.push_back(horc);
    }

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        int r;
        cin >> r;
        int ansv = prefv[r + 1] - prefv[l];
        int ansh = prefh[r + 1] - prefh[l];

        if (ansv == ansh) {
            printf("Simetr\u00eda igual.\n");
        } else {
            if (ansv > ansh) {
                printf("M\u00e1s simetr\u00eda vertical.\n");
            } else {
                printf("M\u00e1s simetr\u00eda horizontal.\n");
            }
        }
    }

    return 0;
}

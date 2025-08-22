#include <bits/stdc++.h>
using namespace std;

vector<int> compute_lps(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmp_search(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    vector<int> lps = compute_lps(pattern);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABCABCABCABC";
    string pattern = "ABABCABCAB";
    
    kmp_search(text, pattern);
    
    return 0;
}

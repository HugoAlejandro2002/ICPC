#include <bits/stdc++.h>
using namespace std;

bool is_valid_clue(const string& a, const string& b, tuple<int, int, char, char, char, char>& clue_key1, tuple<int, int, char, char, char, char>& clue_key2) {
    int n = a.size();
    int count = 0;
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (count == 0) {
                idx = i;
            } else if (count == 1 && i == idx + 1) {
                // ok
            } else {
                return false;
            }
            count++;
        }
    }

    if (count == 2 && idx != -1 && idx + 1 < n) {
        clue_key1 = {n, idx, a[idx], a[idx + 1], b[idx], b[idx + 1]};
        clue_key2 = {n, idx, b[idx], b[idx + 1], a[idx], a[idx + 1]};
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, vector<string>> words_by_length;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        words_by_length[words[i].size()].push_back(words[i]);
    }

    map<tuple<int, int, char, char, char, char>, vector<pair<string, string>>> clues;

    for (auto& [length, group] : words_by_length) {
        for (int i = 0; i < group.size(); i++) {
            for (int j = i + 1; j < group.size(); j++) {
                tuple<int, int, char, char, char, char> clue_key1;
                tuple<int, int, char, char, char, char> clue_key2;
                if (is_valid_clue(group[i], group[j], clue_key1, clue_key2)) {
                    clues[clue_key1].push_back({group[i], group[j]});
                    clues[clue_key2].push_back({group[i], group[j]});
                }
            }
        }
    }

    int result = 0;
    for (auto& [key, vec] : clues) {
        if (vec.size() == 1) result++;
    }

    cout << result/2 << '\n';
    return 0;
}
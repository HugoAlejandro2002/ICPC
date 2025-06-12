#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Matrix = vector<vector<int>>;
using Plan = vector<vector<char>>;

// Rotate the plan 90 degrees clockwise
Plan rotate90(const Plan& plan) {
    int rows = plan.size(), cols = plan[0].size();
    Plan rotated(cols, vector<char>(rows));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            rotated[j][rows - 1 - i] = plan[i][j];
    return rotated;
}

// Compute max tree sum after placing building
int computeMaxTreeSum(int r, int c, const Matrix& land, int s, int t, const Plan& originalPlan) {
    int totalSum = 0;
    for (const auto& row : land)
        for (int val : row)
            totalSum += val;

    int maxSum = 0;
    Plan plan = originalPlan;

    for (int rot = 0; rot < 4; ++rot) {
        int pr = plan.size(), pc = plan[0].size();

        for (int i = 0; i <= r - pr; ++i) {
            for (int j = 0; j <= c - pc; ++j) {
                int covered = 0;
                for (int x = 0; x < pr; ++x)
                    for (int y = 0; y < pc; ++y)
                        if (plan[x][y] == '#')
                            covered += land[i + x][j + y];

                maxSum = max(maxSum, totalSum - covered);
            }
        }

        plan = rotate90(plan);
    }

    return maxSum;
}

int main() {
    int r, c;
    cin >> r >> c;

    Matrix land(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> land[i][j];

    int s, t;
    cin >> s >> t;

    Plan building(s, vector<char>(t));
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < t; ++j)
            cin >> building[i][j];

    int result = computeMaxTreeSum(r, c, land, s, t, building);
    cout << result << endl;

    return 0;
}

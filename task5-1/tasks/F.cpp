#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int grid[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int d[n][m];
    pair<int, int> prev[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                d[i][j] = grid[i][j];
            } else if (i == 0) {
                d[i][j] = grid[i][j] + d[i][j - 1];
            } else if (j == 0) {
                d[i][j] = grid[i][j] + d[i - 1][j];
            } else {
                if (d[i - 1][j] < d[i][j - 1]) {
                    d[i][j] = d[i - 1][j] + grid[i][j];
                    prev[i][j] = make_pair(i - 1, j);
                } else {
                    d[i][j] = d[i][j - 1] + grid[i][j];
                    prev[i][j] = make_pair(i, j - 1);
                }
            }
        }
    }

    cout << d[n - 1][m - 1] << endl;

    vector<pair<int, int>> path;

    int i = n - 1, j = m - 1;

    while (i >= 0 && j >= 0) {
        path.emplace_back(i, j);

        if (i == 0) {
            --j;
        } else if (j == 0) {
            --i;
        } else if (d[i - 1][j] < d[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(path.begin(), path.end());

    for (auto &val: path) {
        cout << val.first + 1 << " " << val.second + 1 << endl;
    }

    return 0;
}
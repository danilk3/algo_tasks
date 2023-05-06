#include "iostream"
#include "vector"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n + 2, vector<int>(m + 2, 0));
    d[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i + 2][j + 1] += d[i][j];
            d[i + 1][j + 2] += d[i][j];
        }
    }

    cout << d[n - 1][m - 1] << endl;

    return 0;
}
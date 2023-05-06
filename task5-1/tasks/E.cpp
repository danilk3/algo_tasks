#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1, 1e9);
    vector<int> pred(n + 1);
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int k: {i + 1, i * 2, i * 3}) {
            if (k <= n && d[k] > d[i] + 1) {
                d[k] = d[i] + 1;
                pred[k] = i;
            }
        }
    }

    vector<int> path;
    int x = n;
    while (x != 1) {
        path.push_back(x);
        x = pred[x];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << d[n] << endl;

    for (int num: path) {
        cout << num << " ";
    }

    return 0;
}
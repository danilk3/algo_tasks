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

    vector<int> h(n + 1);
    vector<int> d(n + 1, 1e9);
    vector<int> prev(n + 1);
    vector<int> path;

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    d[1] = 0;

    for (int i = 1; i < n; ++i) {
        if (d[i + 1] > d[i] + abs(h[i + 1] - h[i])) {
            d[i + 1] = d[i] + abs(h[i + 1] - h[i]);
            prev[i + 1] = i;
        }
        if (i + 2 <= n && d[i + 2] > d[i] + 3 * abs(h[i + 2] - h[i])) {
            d[i + 2] = d[i] + 3 * abs(h[i + 2] - h[i]);
            prev[i + 2] = i;
        }
    }

    cout << d[n] << endl;

    int x = n;
    int counter = 0;
    while (x != 0) {
        path.push_back(x);
        x = prev[x];q
        ++counter;
    }

    cout << counter << endl;

    reverse(path.begin(), path.end());

    for (int val: path) {
        cout << val << " ";
    }

    return 0;
}
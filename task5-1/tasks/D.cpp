#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1, 0);
    vector<int> h(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    d[2] = abs(h[2] - h[1]);

    for (int i = 3; i <= n; ++i) {
        d[i] = min(abs(h[i - 1] - h[i]) + d[i - 1], abs(h[i - 2] - h[i]) + d[i - 2]);
    }

    cout << d[n] << endl;

    return 0;
}
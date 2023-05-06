#include "iostream"
#include "vector"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1, 1e9);
    d[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (char c: to_string(i)) {
            d[i] = min(d[i], d[i - (c - '0')] + 1);
        }
    }

    cout << d[n] << endl;

    return 0;
}
#include "iostream"
#include "vector"

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int mod = 1e9+7;
    cin >> n;
    vector<int> d(n + 1, 0);

    d[0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j <= n) {
                d[i + j] = (d[i + j] + d[i]) % mod;
            }
        }
    }

    cout << d[n];

    return 0;
}
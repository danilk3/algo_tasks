#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int n, k, res = 0;
    cin >> n >> k >> s;

    int a[n + 1];
    int b[n + 1];
    a[0] = 0;
    b[0] = 0;

    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
        b[i] = b[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
    }

    for (int i = 1; i <= n; ++i) {
        int l = i;
        int r = n;

        while (l <= r) {
            int mid = (r + l) / 2;

            if (a[mid] - a[i - 1] <= k || b[mid] - b[i - 1] <= k) {
                res = max(res, mid - i + 1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    cout << res;

    return 0;
}
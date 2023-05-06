#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, res, curr;

    cin >> n >> res;

    for (int i = 1; i < n; ++i) {
        cin >> curr;
        res = gcd(res, curr);

        if (res == 1) {
            cout << res;
            return 0;
        }
    }

    cout << res;

    return 0;
}

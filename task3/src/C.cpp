#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long start = 0;
    long long end = 1e18;

    while (end - start > 1) {
        long long mid = start + (end - start) / 2;
        long long currTime = 0;

        for (int i = 0; i < n; ++i) {
            currTime += (mid / a[i]);
            if (currTime >= t) {
                break;
            }
        }

        if (currTime >= t) {
            end = mid;
        } else {
            start = mid;
        }
    }

    cout << end;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    cin >> n >> m;

    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < m; ++i) {
        cin >> num;

        int start = -1;
        int end = n;

        while (end - start > 1) {
            int mid = start + (end - start) / 2;

            if (a[mid] > num) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (start == -1) {
            cout << a[0] << endl;
        } else {
            if (start < n - 1 && a[start] != num && abs(a[start] - num) > abs(a[start + 1] - num)) {
                cout << a[start + 1] << endl;
            } else {
                cout << a[start] << endl;
            }
        }
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int l = 0;
    int currNumberOfZeros = 0;
    int res = 0;
    int start = -1;
    int end = -1;

    for (int r = 0; r < n; ++r) {
        currNumberOfZeros += arr[r] == 0 ? 1 : 0;

        while (l <= r && currNumberOfZeros > k) {
            currNumberOfZeros -= arr[l] == 0 ? 1 : 0;
            ++l;
        }

        if (r - l + 1 > res) {
            res = r - l + 1;
            start = l;
            end = r;
        }
    }

    cout << res << endl;

    for (int i = 0; i < n; ++i) {
        if (i >= start && i <= end) {
            cout << "1 ";
        } else {
            cout << arr[i] << " ";
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int hotels[n];

    for (int i = 0; i < n; ++i) {
        cin >> hotels[i];
    }

    int l = 0;
    int res = 0;
    int currSum = 0;

    for (int r = 0; r < n; ++r) {
        currSum += hotels[r];

        while (l <= r && currSum > m) {
            currSum -= hotels[l++];
        }

        res = max(currSum, res);
    }

    cout << res;

    return 0;
}

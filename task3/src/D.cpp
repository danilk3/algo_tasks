#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> ropes(n);

    for (int i = 0; i < n; ++i) {
        cin >> ropes[i];
    }

    int start = 0;
    int end = 1e9;

    while (end - start > 1) {
        int len = (end + start) / 2;

        int currNum = 0;

        for (int i = 0; i < n; ++i) {
            currNum += ropes[i] / len;
        }

        if (currNum >= k) {
            start = len;
        } else {
            end = len;
        }
    }

    cout << start;

    return 0;
}
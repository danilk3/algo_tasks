#include <iostream>
#include <vector>

using namespace std;

bool checkCow(int x, int k, vector<int> arr) {
    int numberOfCows = 1;
    int currentCow = arr[0];

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] - currentCow >= x) {
            ++numberOfCows;
            currentCow = arr[i];
        }
    }

    return numberOfCows >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int start = 0;
    int end = arr[n - 1] - arr[0] + 1;

    while (end - start > 1) {
        int mid = (end + start) / 2;

        if (checkCow(mid, k, arr)) {
            start = mid;
        } else {
            end = mid;
        }
    }

    cout << start;

    return 0;
}
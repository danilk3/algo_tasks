#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<int> arr(n);

    long long start = 1;
    long long end = 1e9;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    while (end - start > 1) {
        long long sum = start + (end - start) / 2;

        long long currSum = 0;
        long long numberOfParts = 1;

        for (int i = 0; i < n; ++i) {
            if (arr[i] > sum) {
                numberOfParts = k + 1;
                break;
            }
            if (currSum + arr[i] <= sum) {
                currSum += arr[i];
            } else {
                ++numberOfParts;
                currSum = arr[i];
            }
        }

        if (numberOfParts <= k) {
            end = sum;
        } else {
            start = sum;
        }
    }

    cout << end;

    return 0;
}
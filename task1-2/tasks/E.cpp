#include "iostream"

using namespace std;

int main() {
    int n, el;

    cin >> n;

    int prefix[n + 1];
    prefix[0] = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> el;
        prefix[i] = el + prefix[i - 1];
    }

    int res = 0;
    int bound = prefix[n] / 3;
    int counter = 0;

    for (int i = 1; i < n; ++i) {
        if (prefix[i] == 2 * bound) {
            res += counter;
        }
        if (prefix[i] == bound) {
            ++counter;
        }
    }

    cout << res;

    return 0;
}
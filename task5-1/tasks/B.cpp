#include "iostream"
#include "vector"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n;
    vector<int> steps(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> steps[i];
    }
    cin >> k;

    vector<int> d(n + 2, 0);

    for (int i = 1; i < n + 2; ++i) {
        int start = i - k >= 1 ? i - k : 0;
        int max_num = -1e5;
        for (int j = start; j < i; ++j) {
            max_num = max(max_num, d[j]);
        }
        d[i] = max_num + steps[i];
    }

    cout << d[n + 1];

    return 0;
}
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    int children[n];
    int boarded[n];

    for (int i = 0; i < n; ++i) {
        cin >> children[i];
    }

    sort(children, children + n);

    int res = 0;
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (children[i] + children[j] > x) {
            j--;
        } else {
            res += 1;
            boarded[i] = 1;
            boarded[j] = 1;
            j--;
            i++;
        }
    }

    for (int k = 0; k < n; ++k) {
        if (boarded[k] != 1) {
            ++res;
        }
    }

    cout << res;

    return 0;
}
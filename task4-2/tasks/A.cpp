#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    if (s % n == 0) {
        cout << s / n;
    } else {
        cout << s / n + 1;
    }

    return 0;
}
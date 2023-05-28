#include <iostream>

using namespace std;

int main() {
    int t, n;
    string nString;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;
        nString = to_string(n);

        cout << (nString[0] - '0') + (9 * nString.size()) - 9 << endl;
    }

    return 0;
}
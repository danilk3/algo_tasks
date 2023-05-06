#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int maxDiff = 5;
    int n;
    cin >> n;
    int skills[n];

    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }

    sort(skills, skills + n);

    int l = 0;
    int res = 0;

    for (int r = 0; r < n; ++r) {
        while (l < r && abs(skills[r] - skills[l]) > maxDiff) {
            ++l;
        }

        res = max(res, r - l + 1);
    }

    cout << res;

    return 0;
}

#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    int men[n];

    for (int i = 0; i < n; ++i) {
        cin >> men[i];
    }

    cin >> m;
    int women[m];
    for (int i = 0; i < m; ++i) {
        cin >> women[i];
    }

    sort(men, men + n);
    sort(women, women + m);

    int m_index = 0;
    int w_index = 0;
    int res = 0;

    while (m_index < n && w_index < m) {
        if (abs(men[m_index] - women[w_index]) <= 1) {
            ++res;
            ++m_index;
            ++w_index;
            continue;
        }

        if (men[m_index] < women[w_index]) {
            ++m_index;
        } else {
            ++w_index;
        }
    }

    cout << res;

    return 0;
}
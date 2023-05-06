#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> res;

void hanoi(int n, int i, int k) {
    if (n == 1) {
        res.push_back(make_pair(i, k));
        return;
    }
    int tmp = 6 - i - k;
    hanoi(n - 1, i, tmp);
    res.push_back(make_pair(i, k));
    hanoi(n - 1, tmp, k);
}


int main() {
    int n;

    cin >> n;

    hanoi(n, 1, 3);

    cout << res.size() << endl;

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << endl;
    }

    return 0;
}

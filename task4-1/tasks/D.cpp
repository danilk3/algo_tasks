#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<long long, long long> e1, pair<long long, long long> e2) {
    return e1.first < e2.first;
}

int main() {
    int n, d;
    cin >> n >> d;

    pair<long long, long long> friends[n]; // {кол-во денег, степень дружбы}

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        friends[i] = make_pair(a, b);
    }

    sort(friends, friends + n, comp);

    int l = 0;
    long long res = 0;
    long long currAmountOfFriendship = 0;

    for (int r = 0; r < n; ++r) {
        currAmountOfFriendship += friends[r].second;

        while (l <= r && friends[r].first - friends[l].first >= d) {
            currAmountOfFriendship -= friends[l++].second;
        }

        res = max(res, currAmountOfFriendship);
    }

    cout << res;

    return 0;
}

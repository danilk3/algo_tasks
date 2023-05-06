#include <deque>
#include "iostream"

typedef long long ll;

using namespace std;

struct min_window {

    // {value, index}
    deque<pair<ll, ll>> d;
    int l_index, r_index;

    min_window() {
        l_index = r_index = 0;
    }

    void push(ll value, ll index) {
        while (!d.empty() && d.back().first >= value) {
            d.pop_back();
        }
        d.emplace_back(value, index);
        ++r_index;
    }

    void pop_front() {
        if (d.front().second <= l_index) {
            d.pop_front();
        }
        ++l_index;
    }

    ll getMin() {
        return d.front().first;
    }
};

struct max_window {

    // {value, index}
    deque<pair<ll, ll>> d;
    int l_index, r_index;

    max_window() {
        l_index = r_index = 0;
    }

    void push(ll value, ll index) {
        while (!d.empty() && d.back().first <= value) {
            d.pop_back();
        }
        d.emplace_back(value, index);
        ++r_index;
    }

    void pop_front() {
        if (d.front().second <= l_index) {
            d.pop_front();
        }
        ++l_index;
    }

    ll getMax() {
        return d.front().first;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    ll max_res[n - k + 1];
    ll min_res[n - k + 1];

    min_window min_w = min_window();
    max_window max_w = max_window();

    for (ll i = 0; i < n; ++i) {
        int num;
        cin >> num;
        min_w.push(num, i);
        max_w.push(num, i);
        if (i >= k - 1) {
            min_res[i - k + 1] = min_w.getMin();
            min_w.pop_front();

            max_res[i - k + 1] = max_w.getMax();
            max_w.pop_front();
        }
    }


    // ----------------

    for (int i = 0; i < n - k + 1; ++i) {
        cout << min_res[i];
        if (i != n - k) {
            cout << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < n - k + 1; ++i) {
        cout << max_res[i];
        if (i != n - k) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}
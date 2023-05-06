#include "iostream"
#include "queue"

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, Compare> pq;
    int n, d, a;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> d;
        pq.push(make_pair(a, d));
    }

    long long res = 0;
    long long f = 0;

    while (!pq.empty()) {
        pair<int, int> a = pq.top();
        pq.pop();
        f += a.first;
        res += a.second - f;
    }

    cout << res;

    return 0;
}
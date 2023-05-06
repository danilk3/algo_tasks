#include "iostream"
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);

    int n, a;
    cin >> n;

    std::priority_queue<int, vector<int>, greater<int> > min_heap;
    std::priority_queue<int > max_heap;


    for (int i = 0; i < n; ++i) {
        cin >> a;

        if (max_heap.empty() || max_heap.top() > a) {
            max_heap.push(a);
        } else {
            min_heap.push(a);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if (max_heap.size() == min_heap.size()) {
            cout << 1.0 * (min_heap.top() + max_heap.top()) / 2 << endl;
        } else {
            cout << (max_heap.size() > min_heap.size() ? max_heap.top() * 1.0 : min_heap.top() * 1.0) << endl;
        }
    }

    return 0;
}
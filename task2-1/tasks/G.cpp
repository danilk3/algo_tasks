#include <iostream>
#include <stack>

using namespace std;


int main() {
    int t, n, h;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;

        int maxHeight = 0;
        stack<pair<int, int>> s;
        s.push(make_pair(-1, 0));// {height, index}

        for (int j = 1; j <= n + 1; ++j) {
            if (j == n + 1) {
                h = 0;
            } else {
                cin >> h;
            }
            int index = j;
            while (s.top().first >= h) {
                index = s.top().second;
                int currentHeight = s.top().first * (j - index);

                if (currentHeight > maxHeight) {
                    maxHeight = currentHeight;
                }
                s.pop();
            }

            s.push(make_pair(h, index));
        }

        cout << "Case " << i + 1 << ": " << maxHeight << endl;
    }

    return 0;
}

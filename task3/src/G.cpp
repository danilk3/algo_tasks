#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t; // t - кол-во свободных минут ; n - кол-во книг

    vector<int> booksReadTime(n);

    for (int i = 0; i < n; ++i) {
        cin >> booksReadTime[i];
    }

    int start = 0;
    int currTime = 0;
    int res = 0;

    for (int end = 0; end < n; ++end) {
        currTime += booksReadTime[end];

        if (currTime > t) {
            currTime -= booksReadTime[start];
            ++start;
        }

        res = max(end - start + 1, res);
    }

    cout << res;

    return 0;
}
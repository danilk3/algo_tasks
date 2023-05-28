#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Есть n прямоугольников одинакового размера: w в ширину и h в длину.
    int64_t w, h, n;
    cin >> w >> h >> n;

    int64_t start = 0;
    int64_t end  = max(w, h) * n;

    while (end - start > 1) {
        int64_t m = start + (end - start) / 2;

        if ((m / w) * (m / h) >= n) {
            end = m;
        } else {
            start = m;
        }
    }

    cout << end;

    return 0;
}
#include <iostream>

using namespace std;

double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double start;
    double end = 1;

    while (f(end, a, b, c, d) * f(-end, a, b, c, d) >= 0) {
        end *= 2;
    }

    start = -end;

    for (int i = 0; i < 50000; ++i) {
        double x = start + (end - start) / 2;

        if (f(x, a, b, c, d) * f(end, a, b, c, d) > 0) {
            end = x;
        } else {
            start = x;
        }
    }

    cout << start;

    return 0;
}
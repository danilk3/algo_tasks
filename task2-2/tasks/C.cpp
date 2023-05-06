#include <iostream>

using namespace std;

int fibStringLen[45] = {1, 1};

char findChar(int n, int k) {
    if (n == 0) {
        return 'a';
    }
    if (n == 1) {
        return 'b';
    }

    if (k <= fibStringLen[n - 2]) {
        return findChar(n - 2, k);
    }
    return findChar(n - 1, k - fibStringLen[n - 2]);
}


int main() {
    for (int i = 2; i < 45; ++i) {
        fibStringLen[i] = fibStringLen[i - 1] + fibStringLen[i - 2];
    }

    int t, n, k;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        cout << findChar(n, k) << endl;
    }

    return 0;
}

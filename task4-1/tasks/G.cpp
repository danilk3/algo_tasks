#include "iostream"
#include "map"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<int, int> nums;

    int res = 0;
    int l_pointer = 0;
    int numberOfNonUnique = 0;

    for (int r_pointer = 0; r_pointer < n; ++r_pointer) {
        ++nums[arr[r_pointer]];

        if (nums[arr[r_pointer]] > 1) {
            ++numberOfNonUnique;
        }

        while (l_pointer <= r_pointer && numberOfNonUnique > 0) {
            --nums[arr[l_pointer]];
            if (nums[arr[l_pointer]] == 1) {
                --numberOfNonUnique;
            }
            ++l_pointer;
        }

        if (numberOfNonUnique == 0) {
            res = max(res, r_pointer - l_pointer + 1);
        }
    }

    cout << res;

    return 0;
}

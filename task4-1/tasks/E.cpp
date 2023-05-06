#include "iostream"
#include "map"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<int, int> nums;

    int left_res = 0;
    int right_res = 0;
    int l_pointer = 0;
    int numberOfUnique = 0;

    for (int r_pointer = 0; r_pointer < n; ++r_pointer) {
        if (nums[arr[r_pointer]] == 0) {
            ++numberOfUnique;
        }
        ++nums[arr[r_pointer]];

        while (l_pointer <= r_pointer && numberOfUnique > k) {
            --nums[arr[l_pointer]];
            if (nums[arr[l_pointer]] == 0) {
                --numberOfUnique;
            }
            ++l_pointer;
        }

        if (right_res - left_res + 1 < r_pointer - l_pointer + 1) {
            right_res = r_pointer;
            left_res = l_pointer;
        }
    }
    cout << left_res + 1 << " " << right_res + 1;

    return 0;
}

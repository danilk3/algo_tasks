#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n, num;

    while ((cin >> n, getchar(), n != 0)) {
        string line;
        stringstream stream;
        getline(cin, line, '\n');

        while (line != "0") {
            vector<int> pos;
            stream.str("");
            stream.clear();
            stream << line;
            stream >> num;

            for (int i = 1; i <= n; i++) {
                pos.push_back(i);
                while (!pos.empty() && num == pos.back()) {
                    pos.pop_back();
                    stream >> num;
                }
            }

            if (pos.empty()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }

            getline(cin, line, '\n');
        }
        cout << endl;
    }

}
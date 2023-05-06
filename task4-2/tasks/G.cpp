#include "iostream"
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // {client_id, priority}
    set<pair<int, int>> s;

    int command, priority, client_id;

    cin >> command;

    while (command) {
        if (command == 1) {
            cin >> client_id >> priority;
            s.insert(make_pair(priority, client_id));
        } else if (command == 2) {
            if (s.empty()) {
                cout << 0 << endl;
            } else {
                auto it = s.end();
                it--;
                cout << (*it).second << endl;
                s.erase(it);
            }
        } else { // command == 3
            if (s.empty()) {
                cout << 0 << endl;
            } else {
                auto it = s.begin();
                cout << (*it).second << endl;
                s.erase(it);
            }
        }
        cin >> command;
    }

    return 0;
}
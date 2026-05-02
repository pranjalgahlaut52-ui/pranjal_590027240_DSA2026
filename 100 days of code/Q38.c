#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if (op == "push_back") {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if (op == "pop_front") {
            if (!dq.empty()) dq.pop_front();
        }
        else if (op == "pop_back") {
            if (!dq.empty()) dq.pop_back();
        }
        else if (op == "front") {
            if (!dq.empty()) cout << dq.front() << endl;
            else cout << -1 << endl;
        }
        else if (op == "back") {
            if (!dq.empty()) cout << dq.back() << endl;
            else cout << -1 << endl;
        }
        else if (op == "empty") {
            cout << (dq.empty() ? "true" : "false") << endl;
        }
        else if (op == "size") {
            cout << dq.size() << endl;
        }
        else if (op == "clear") {
            dq.clear();
        }
        else if (op == "reverse") {
            reverse(dq.begin(), dq.end());
        }
        else if (op == "sort") {
            sort(dq.begin(), dq.end());
        }
        else if (op == "display") {
            for (int x : dq) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}
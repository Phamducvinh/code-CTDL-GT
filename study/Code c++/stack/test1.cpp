#include <bits/stdc++.h>
#include <stack>
using namespace std;

// bool isValid(char open, char close) {
//     return (open == '(' && close == ')') ||
//            (open == '[' && close == ']') ||
//            (open == '{' && close == '}');
// }

void solve() {
    string s;
    cin >> s;
    stack<char> st;

    for (char x : s) {
        if (x == '(' ) {
            st.push(x);
        } else {
            if (st.empty()) {
                cout << "INVALID\n";
                return;
            } else {
                st.pop();
            }
        }
    }

    if (st.empty()) {
        cout << "VALID\n";
    } else {
        cout << "INVALID\n";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

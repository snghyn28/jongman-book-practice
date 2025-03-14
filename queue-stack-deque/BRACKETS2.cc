#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solve(string& str) {
    stack<int> st;
    for (char c : str) {
        switch (c) {
            case '(':
                st.push(0);
                break;
            case '[':
                st.push(1);
                break;
            case '{':
                st.push(2);
                break;
            case ')':
                if (st.empty() || st.top() != 0) return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != 1) return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != 2) return false;
                st.pop();
                break;
            default:
                return false;
        }
    }
    if (!st.empty()) return false;
    return true;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        string str;
        cin >> str;
        if (solve(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

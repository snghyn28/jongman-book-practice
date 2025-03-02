#include <iostream>
#include <list>

using namespace std;

void next(list<int>& l, list<int>::iterator& it, int k) {
    for (int i = 0; i < k; i++) {
        it++;
        if (it == l.end()) it = l.begin();
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        list<int> soldier;
        for (int i = 1; i <= n; i++) {
            soldier.push_back(i);
        }
        list<int>::iterator it = soldier.begin();
        for (int i = 0; i < n - 2; i++) {
            it = soldier.erase(it);
            if (it == soldier.end()) it = soldier.begin();
            next(soldier, it, (k - 1) % (n - i - 1));
        }
        int a = *soldier.begin(), b = *soldier.rbegin();
        if (a < b) cout << a << ' ' << b << endl;
        else cout << b << ' ' << a << endl;
    }
}

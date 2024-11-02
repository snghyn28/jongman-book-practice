#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator& it) {
    if (*it != 'x') {
        string ret(1, *it);
        it++;
        return ret;
    }

    it++;
    string lu, ru, ld, rd;
    lu = reverse(it);
    ru = reverse(it);
    ld = reverse(it);
    rd = reverse(it);
    string ret = ld + rd + lu + ru;
    ret.insert(ret.begin(), 'x');

    return ret;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        string quadTree;
        cin >> quadTree;
        string::iterator it = quadTree.begin();
        string reversed = reverse(it);
        cout << reversed << endl;
    }
}
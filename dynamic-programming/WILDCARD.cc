#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string w, s;
int cache[101][101];

void resetCache() {
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++)
            cache[i][j] = -1;
}

bool isMatch(int i, int j) {
    if(i == w.length() && j == s.length()) return true;
    else if(i == w.length()) return false;
    int& ret = cache[i][j];
    if(ret != -1) return ret;
    if(w[i] == '?' || w[i] == s[j]) return ret = isMatch(i + 1, j + 1);
    else if(w[i] == '*') return ret = isMatch(i + 1, j) || isMatch(i, j + 1);
    else return ret = false;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> w;
        int sn;
        cin >> sn;
        vector<string> matchList;
        while(sn--) {
            cin >> s;
            resetCache();
            if(isMatch(0, 0)) matchList.push_back(s);
        }
        sort(matchList.begin(), matchList.end());
        for(string& match : matchList)
            cout << match << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> digits;
int cache[10000];

void reset() {
    digits.clear();
    memset(cache, -1, sizeof(int) * 10000);
}

int difficulty(int from, int num) {
    bool same = true;
    bool seq = true;
    int diff;
    bool alter = true;
    
    for (int i = from; i < from + num - 1; i++) {
        if (i == from) {
            diff = digits[i + 1] - digits[i];
        } else if (digits[i + 1] - digits[i] != diff) {
            seq = false;
        }
        
        if (digits[i] != digits[i + 1]) {
            same = false;
        }
        
        if (!(((i - from) % 2 == 0) ? 
                (digits[i + 1] - digits[i] == diff) :
                (digits[i + 1] - digits[i] == -diff))) {
            alter = false;
        }
    }
    
    if (same) return 1;
    if (seq && (diff == 1 || diff == -1)) return 2;
    if (alter) return 4;
    if (seq) return 5;
    return 10;
}

int solve(int from) {
    if (from == digits.size()) return 0;
    int& ret = cache[from];
    if (ret != -1) return ret;
    ret = 987654321;
    for (int i = 3; i <= 5; i++) {
        if (from + i > digits.size()) break;
        ret = min(ret, difficulty(from, i) + solve(from + i));
    }
    return ret;
}

int main() {
    int test;
    cin >> test;
    cin.ignore();
    while (test--) {
        reset();
        while (true) {
            char c;
            cin.get(c);
            if (c == '\n') break;
            digits.push_back(c - '0');
        }
        cout << solve(0) << endl;
    }
}

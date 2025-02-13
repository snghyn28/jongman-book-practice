#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() - 1, 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    return c;
}

vector<int> shift(const vector<int>& a, int k) {
    vector<int> b = a;
    b.insert(b.begin(), k, 0);
    return b;
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if(an < bn) return add(b, a);
    vector<int> c = vector<int>(an);
    for(int i = 0; i < an; i++) {
        if (i < bn) c[i] = a[i] + b[i];
        else c[i] = a[i];
    }
    return c;
}

vector<int> sub(const vector<int>&a, const vector<int>& b) {
    vector<int> c = a;
    for(int i = 0; i < b.size(); i++) {
        c[i] -= b[i];
    }
    return c;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a);
    if(an < 50) return multiply(a, b);
    int half = an / 2;
    
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
    vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());
    
    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z1 = sub(karatsuba(add(a0, a1), add(b0, b1)), add(z0, z2));
    
    return add(add(shift(z2, half * 2), shift(z1, half)), z0);
}

int solve(vector<int>& member, vector<int>& fan) {
    reverse(member.begin(), member.end());
    vector<int> mul = karatsuba(member, fan);
    int cnt = 0;
    for(int i = member.size() - 1; i < fan.size(); i++) {
        if(mul[i] == 0) cnt++;
    }
    return cnt;
}

int main() {
    int test;
    cin >> test;
    cin.ignore();
    while(test--) {
        vector<int> member, fan;
        char c;
        while(cin.get(c) && c != '\n') {
            if (c == 'F') {
                member.push_back(0);
            } else if (c == 'M') {
                member.push_back(1);
            }
        }
        while(cin.get(c) && c != '\n') {
            if (c == 'F') {
                fan.push_back(0);
            } else if (c == 'M') {
                fan.push_back(1);
            }
        }
        cout << solve(member, fan) << endl;
    }
    return 0;
}

#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std;

int cache[101];

int tileCount(int n) {
    if (n == 0 || n == 1) return 1;
    int& ret = cache[n];
    if (ret != -1) return ret;
    return ret = (tileCount(n - 1) + tileCount(n - 2)) % MOD;
}

int mod(int n) {
    while (n < 0) {
        n += MOD;
    }
    return n;
}

int main() {
    int test;
    cin >> test;
    memset(cache, -1, sizeof(int) * 101);
    while (test--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << mod(tileCount(n) - tileCount(n / 2)) << endl;
        } else {
            cout << mod(tileCount(n) - tileCount(n / 2) - tileCount(n / 2 - 1)) << endl;
        }
    }
}

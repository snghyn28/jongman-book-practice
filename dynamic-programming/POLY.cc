#include <iostream>
#include <cstring>
#define MOD 10000000

using namespace std;

int cache[101][101];

int solve(int n, int m) {
    if (n == m) return 1;
    int& ret = cache[n][m];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= n - m; i++) {
        ret += solve(n - m, i) * (m + i - 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    int test;
    cin >> test;
    memset(cache, -1, sizeof(int) * 101 * 101);
    while (test--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(n, i);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

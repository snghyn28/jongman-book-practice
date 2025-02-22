#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

int cache[101][101];
vector<long long> A, B;
int n, m;
const long long NEGINF = numeric_limits<long long>::min();

void reset() {
    memset(cache, -1, sizeof(int) * 101 * 101);
    A.clear();
    B.clear();
}

int jlis(int a, int b) {
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    long long bigger = max<long long>(A[a], B[b]);
    ret = 2;
    for(int i = a + 1; i <= n; i++)
        if(A[i] > bigger) ret = max(ret, 1 + jlis(i, b));
    for(int i = b + 1; i <= m; i++)
        if(B[i] > bigger) ret = max(ret, 1 + jlis(a, i));
    return ret;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        reset();
        cin >> n >> m;
        A.push_back(NEGINF);
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }
        B.push_back(NEGINF);
        for(int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            B.push_back(tmp);
        }
        cout << jlis(0, 0) - 2 << endl;
    }
}

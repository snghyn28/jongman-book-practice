#include <iostream>
#include <cstring>

using namespace std;

bool connected[50][50];
int out[50];
int n;
int prison;
double cache[101][50];

void reset() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 50; j++) {
            cache[i][j] = -1;
        }
    }
    memset(out, 0, sizeof(int) * 50);
}

double solve(int d, int at) {
    if (d == 0) {
        if (at == prison) return 1;
        else return 0;
    }
    double& ret = cache[d][at];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (connected[i][at]) {
            ret += solve(d - 1, i) / out[i];
        }
    }
    return ret;
}

int main() {
    cout.precision(10);
    int test;
    cin >> test;
    while (test--) {
        reset();
        int d;
        cin >> n >> d >> prison;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> connected[i][j];
                if (connected[i][j]) {
                    out[i]++;
                }
            }
        }
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int v;
            cin >> v;
            cout << solve(d, v) << ' ';
        }
        cout << endl;
    }
}

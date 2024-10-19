#include <iostream>

using namespace std;

int friendTable[10][10];
int taken[10];

void reset() {
    for (int i = 0; i < 10; i++) {
        taken[i] = 0;
        for (int j = 0; j < 10; j++) friendTable[i][j] = 0;
    }
}

int solve(int n) {
    int first = 0;
    while (first < n && taken[first]) first++;
    if (first == n) return 1;
    int res = 0;
    taken[first] = 1;
    for (int second = first + 1; second < n; second++) {
        if (friendTable[first][second] && !taken[second]) {
            taken[second] = 1;
            res += solve(n);
            taken[second] = 0;
        }
    }
    taken[first] = 0;
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        reset();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            friendTable[a][b] = friendTable[b][a] = 1;
        }
        cout << solve(n) << endl;
    }
}

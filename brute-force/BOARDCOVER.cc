#include <iostream>

using namespace std;

int board[20][20];
int coverPosition[4][3][2] = {
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
};

int cover(int height, int width, int y, int x, int type, int mode) {
    for (int i = 0; i < 3; i++) {
        int y_ = y + coverPosition[type][i][0];
        int x_ = x + coverPosition[type][i][1];
        if (!(0 <= y_ && y_ < height && 0 <= x_ && x_ < width) ||
            (mode == 1 && board[y_][x_] == 1))
            return 0;
    }
    for (int i = 0; i < 3; i++) {
        int y_ = y + coverPosition[type][i][0];
        int x_ = x + coverPosition[type][i][1];
        board[y_][x_] = mode;
    }
    return 1;
}

int countCover(int height, int width) {
    int y, x;
    int cnt = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (!board[y][x]) {
                for (int type = 0; type < 4; type++) {
                    if(cover(height, width, y, x, type, 1)) {
                        cnt += countCover(height, width);
                        cover(height, width, y, x, type, 0);
                    }
                }
                return cnt;
            }
        }
    }
    return 1;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int height, width;
        cin >> height >> width;
        for (int i = 0; i < height; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < width; j++) {
                if (str[j] == '#') board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
        cout << countCover(height, width) << endl;
    }
}

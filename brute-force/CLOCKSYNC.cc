#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int clocks[16];
vector<vector<int>> clocksConnectedToButton {
    { 0, 1, 2 },
    { 3, 7, 9, 11 },
    { 4, 10, 14, 15 },
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15 },
    { 3, 14, 15 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 }
};

void moveClock(int clockNum) {
    clocks[clockNum] = (clocks[clockNum] + 3) % 12;
    if (clocks[clockNum] == 0) clocks[clockNum] = 12;
}

void clickButton(int buttonNum) {
    for (int clockNum : clocksConnectedToButton[buttonNum])
        moveClock(clockNum);
}

bool isClockAligned() {
    for (int clockNum = 0; clockNum < 16; clockNum++)
        if (clocks[clockNum] != 12) return false;
    return true;
}

int getMinClickCnt(int buttonNum) {
    if (buttonNum == 10) {
        if (isClockAligned()) return 0;
        else return INF;
    }

    int minClickCnt = INF;
    for (int clickCnt = 0; clickCnt <= 3; clickCnt++) {
        int followingClickCnt = getMinClickCnt(buttonNum + 1);
        if (minClickCnt > clickCnt + followingClickCnt)
            minClickCnt = clickCnt + followingClickCnt;
        clickButton(buttonNum);
    }

    return minClickCnt;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        for (int i = 0; i < 16; i++)
            cin >> clocks[i];
        int ans = getMinClickCnt(0);
        if (ans >= INF) 
            cout << -1 << endl;
        else
            cout << getMinClickCnt(0) << endl;
    }
}

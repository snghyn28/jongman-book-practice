#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> numbers;
vector<int> acc;
int cache[1001][11];

void reset() {
    numbers.clear();
    acc.clear();
    memset(cache, -1, sizeof(int) * 1001 * 11);
}

void calculateAcc() {
    acc.push_back(0);
    for (int i = 0; i < numbers.size(); i++) {
        acc.push_back(acc[i] + numbers[i]);
    }
}

int getSum(int from, int to) {
    return acc[to + 1] - acc[from];
}

int getAvg(int from, int to) {
    return (float) getSum(from, to) / (to - from + 1) + 0.5;
}

int square(int x) {
    return x * x;
}

int mse(int from, int to) {
    int avg = getAvg(from, to);
    int sum = 0;
    for (int i = from; i <= to; i++) {
        sum += square(numbers[i] - avg);
    }
    return sum;
}

int solve(int from, int s) {
    int& ret = cache[from][s];
    if (ret != -1) return ret;
    if (from == numbers.size()) return 0;
    if (s == 1) return ret = mse(from, numbers.size() - 1);
    ret = 987654321;
    for (int i = from; i < numbers.size(); i++) {
        ret = min(ret, mse(from, i) + solve(i + 1, s - 1));
    }
    return ret;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        reset();
        int n, s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            numbers.push_back(tmp);
        }
        sort(numbers.begin(), numbers.end());
        calculateAcc();
        cout << solve(0, s) << endl;
    }
}

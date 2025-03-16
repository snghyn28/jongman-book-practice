#include <iostream>
#include <queue>

using namespace std;

unsigned int A;

unsigned int getSignal() {
    if (A == 0) {
        A = 1983;
    } else A = A * 214013 + 2531011;
    return A % 10000 + 1;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int k, n;
        queue<unsigned int> signals;
        cin >> k >> n;
        unsigned int sum = 0;
        A = 0;
        int ans = 0;
        while (true) {
            if (sum < k) {
                if (n == 0) break;
                unsigned int signal = getSignal();
                sum += signal;
                signals.push(signal);
                n--;
            } else if (sum > k) {
                unsigned int signal = signals.front();
                signals.pop();
                sum -= signal;
            } else {
                ans += 1;
                if (n == 0) break;
                unsigned int signal = signals.front();
                signals.pop();
                sum -= signal;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

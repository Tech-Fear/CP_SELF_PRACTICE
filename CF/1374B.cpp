#include <iostream>
using namespace std;

int count(int n) {
    int co2 = 0;
    int co3 = 0;
    while (n % 2 == 0) {
        n /= 2;
        co2++;
    }
    while (n % 3 == 0) {
        n /= 3;
        co3++;
    }
    if (n != 1) return -1;
    if (co2 > co3) return -1;
    return abs(co3 - co2) * 2 + co2;
}

void solve(int tc = 0) {
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 0 << endl;
        } else if (n % 3 != 0) {
            cout << -1 << endl;
        } else {
            cout << count(n) << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

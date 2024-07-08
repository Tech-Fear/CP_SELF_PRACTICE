#include <bits/stdc++.h>
using namespace std;

int max_limit = 1e6 + 1;
vector<bool> primes(max_limit, true);
vector<int> countP(max_limit, 0);

void sieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i < max_limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < max_limit; j += i) {
                primes[j] = false;
            }
        }
    }
    int count = 0;
    countP[0] = countP[1] = 0;
    for (int i = 2; i < max_limit; i++) {
        if (primes[i]) {
            count++;
        }
        countP[i] = count;
    }
}

int main() {
    int t;
    cin >> t;
    sieve();
    while (t--) {
        int n;
        cin >> n;
        cout << countP[n] << endl;
    }
    return 0;
}

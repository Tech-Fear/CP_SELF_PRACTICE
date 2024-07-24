#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INTMOD = 1e9+7;

ll binaryExp(ll a, ll b) {
    if (b == 0) return 1;
    ll temp = binaryExp(a, b / 2);
    if (b % 2 == 0) {
        return ((temp % INTMOD) * (temp % INTMOD)) % INTMOD;
    } else {
        return ((((temp % INTMOD) * (temp % INTMOD)) % INTMOD) * (a % INTMOD)) % INTMOD;
    }
}

void solve(ll n, ll p, ll q) {
    ll pC = binaryExp(p, n);
    ll qC = binaryExp(q, n);
    ll mmi = binaryExp(qC, INTMOD - 2);
    ll ans = ((pC % INTMOD) * (mmi % INTMOD)) % INTMOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, p, q;
        cin >> n >> p >> q;
        solve(n, p, q);
    }
    return 0;
}

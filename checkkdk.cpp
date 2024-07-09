#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define MOD 1e9+7

using namespace std;

ll mod_fact(ll n, ll mod) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res%mod * i%mod) % mod;
    }
    return res;
}

ll mod_inverse(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;
    if (mod == 1)
        return 0;
    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

ll nPr(ll n, ll r, ll mod) {
    if (r > n) return 0;
    ll num = mod_fact(n, mod);
    ll denom = mod_fact(n - r, mod);
    return (num * mod_inverse(denom, mod)) % mod;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << nPr(k, n, MOD) << endl;
    }
    return 0;
}

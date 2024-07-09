#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
const int MOD=1e9+7;
using namespace std;
ll fact(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n; i++) {
        result = (result%MOD * i%MOD)%MOD;
    }
    return result;
}

ll mod_inverse(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x = 0, y = 1;
    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x;
        x = y - q * x;
        y = t;
    }
    if (y < 0) y += m0;
    return y;
}

ll nPr(ll n, ll r)
{
    if(n>r) return 0;
    ll numerator=fact(n);
    ll denominator=fact(n-r);
    return (numerator*mod_inverse(denominator,MOD))%MOD;
}
int main()
{
int t;
cin>>t;
while(t--){
  int n,k;
  cin>>n>>k;
  cout<<nPr(k,n)<<endl;
}
return 0;
}
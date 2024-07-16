#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
const ll MOD = 998244353;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll solve(int n,ll val,v64 &weights,v64 &value,vv64 &dp){
    if(val==0) return 0;
    if(n==0) return INF;
    if(dp[n][val]!=-1) return dp[n][val];
    ll cur=solve(n-1,val,weights,value,dp);
    if(val>=value[n-1]){
         ll include_item = solve(n - 1, val- value[n - 1], weights, value, dp);
        if (include_item != INF) {
            cur = min(cur, include_item + weights[n - 1]);
        }
    }
      return dp[n][val] = cur;
}

int main() {
    fast_cin();
    ll n,w;
    cin >> n >> w;
    v64 weights(n),value(n);
    forn(i,n){
      cin>>weights[i]>>value[i];
    }
    ll sum=accumulate(all(value),0ll);
    vv64 dp(n+1,v64(sum+1,-1));
    ll best_value = 0;
     for (ll v = 0; v <= sum; v++) {
        if (solve(n, v, weights, value, dp) <= w) {
            best_value = v;
        }
    }
    cout<<best_value;
    return 0;
}


// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef vector<ll> v64;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     ll n, w;
//     cin >> n >> w;
//     v64 weights(n), values(n);

//     for (ll i = 0; i < n; i++) {
//         cin >> weights[i] >> values[i];
//     }

//     ll max_value = accumulate(values.begin(), values.end(), 0LL);
//     v64 dp(max_value + 1, LLONG_MAX);
//     dp[0] = 0;

//     for (ll i = 0; i < n; i++) {
//         for (ll v = max_value; v >= values[i]; v--) {
//             if (dp[v - values[i]] != LLONG_MAX) {
//                 dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
//             }
//         }
//     }

//     ll best_value = 0;
//     for (ll v = 0; v <= max_value; v++) {
//         if (dp[v] <= w) {
//             best_value = v;
//         }
//     }

//     cout << best_value << "\n";
//     return 0;
// }

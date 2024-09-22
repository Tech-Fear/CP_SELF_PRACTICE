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
#define forn(a,e) for(ll i = a; i < e; i++)
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
const int INTMOD = 1e9+7;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
v32 memo;
ll dpFunc(int n) {
    if (n < 0) return INT_MAX;
    if (n == 0) return 0;
    if(memo[n]!=-1) return memo[n];
    ll count = INT_MAX;
    count = min(count, dpFunc(n - 10) + 1);
    count = min(count, dpFunc(n - 1) + 1);
    count = min(count, dpFunc(n - 5) + 1);
    count = min(count, dpFunc(n - 20) + 1);
    count = min(count, dpFunc(n - 100) + 1);
    return memo[n]=count;
}
void solve() {
    ll n;
    cin >> n;
    memo.resize(n+1,-1);
    int count = dpFunc(n);
    // cout << (count == INT_MAX ? -1 : count) << endl;
    vector<ll>coins={1,5,10,20,100};
    vector<ll>dp(n+1,INT_MAX);
    dp[0]=0;
    for(ll i=0;i<n;i++){
      for(auto &coin:coins){
        if(i+1-coin>=0){
          dp[i+1]=min(dp[i+1-coin]+1,dp[i+1]);
        }
      }
    }
    cout<<dp[n];
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--){
       solve();
    }
    return 0;
}
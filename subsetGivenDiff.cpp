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

ll solve(int i, ll x, ll to_calc, v32 &arr, vv32 &dp) {
    if (i == arr.size()) {
        return (to_calc - 2 * x == 0) ? 1 : 0;
    }
    if (dp[i][x] != -1) return dp[i][x];
    ll include = (arr[i] <= to_calc) ? solve(i + 1, x + arr[i], to_calc, arr, dp) : 0;
    ll exclude = solve(i + 1, x, to_calc, arr, dp);
    return dp[i][x] = include + exclude;
}

int main() {
    fast_cin();
    int n,x;
    cin>>n>>x;
    v32 arr(n);
    forn(0,n){
      cin>>arr[i];
    }
    ll total_sum=accumulate(all(arr),0ll);
    ll to_calc=(total_sum+x);
    vv32 dp(n,v32(to_calc,-1));
    cout<<solve(0,0,to_calc,arr,dp);
    
    return 0;
}
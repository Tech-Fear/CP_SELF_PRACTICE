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
// ll solve(ll w,v64 &weights,v64 &value,ll n,vv64 &dp) {
//   if(w==0 || n==0) return 0;
//   if(dp[n][w]!=-1) return dp[n][w];
//   if(weights[n-1]>w){
//     return dp[n][w]=solve(w,weights,value,n-1,dp);
//   }
//   return dp[n][w]=max(value[n-1]+solve(w-weights[n-1],weights,value,n-1,dp),solve(w,weights,value,n-1,dp));
// }

// int main() {
//     fast_cin();
//     ll n,w;
//     cin >> n >> w;
//     v64 weights(n),value(n);
//     vv64 dp(n+1,v64(w+1,-1));
//     dp[n][0]=0;
//     dp[0][w]=0;
//     forn(i,n){
//       cin>>weights[i]>>value[i];
//     }
//     cout<<solve(w,weights,value,n,dp);
  
//     return 0;
// }

int main() {
    fast_cin();
    ll n,w;
    cin >> n >> w;
    v64 weights(n),value(n);
    vv64 dp(n+1,v64(w+1,0));
    forn(i,n){
      cin>>weights[i]>>value[i];
    }
    for(int i=n-1;i>=0;i--){
      for(int j=1;j<=w;j++){
        if(weights[i]<=j){
          dp[i][j]=max(dp[i+1][j],dp[i+1][j-weights[i]]+value[i]);
        }else{
          dp[i][j]=dp[i+1][j];
        }
      }
    }
    cout<<dp[0][w];
    return 0;
}


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
class Solution {
private:
  int solve(int i,int amount,v32 &coins,vv32 &dp){
    if(i>=coins.size()) return 0;
    if(amount==0) return 1;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int np = solve(i+1,amount,coins,dp)%INTMOD;
    int p = 0;
    if(amount>=coins[i]){
          p = solve(i,amount-coins[i],coins,dp)%INTMOD;
    }
    return dp[i][amount] = (p+np)%INTMOD;
  }
public:
    int change(int amount, v32 &coins) {
        vv32 dp(coins.size()+1,v32(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};

// int main() {
//     fast_cin();
//     int n;
//     cin>>n;
//     int amount;
//     cin>>amount;
//     v32 arr(n);
//     forsn(i,0,n){
//       cin>>arr[i];
//     }
//     Solution obj1;
//     // cout<<obj1.change(amount,arr);
//     vv32 dp(n+1,v32(amount+1,0));
//     dp[n][amount]=1;
//     for(int i=0;i<amount;i++){
//       dp[n][i]=0;
//     }
//     for(int i=n-1;i>=0;i--){
//       for(int j=amount;j>=0;j--){
//         dp[i][j]=dp[i+1][j];
//         if(j+arr[i]<=amount){
//           dp[i][j]+=dp[i][j+arr[i]];
//         }
//       }
//     }
//     cout<<dp[0][0]%INTMOD;
//     return 0;
// }
int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;

  vector<vector<int>> dp(n+1,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0) {
	(dp[i][j] += dp[i][left]) %= mod;
      }
    }
  }
  cout << dp[n][target] << endl;
}
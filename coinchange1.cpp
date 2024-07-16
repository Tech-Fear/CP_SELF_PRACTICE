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
      if(i==coins.size()){
        if(amount==0) return 0;
        return 1e8;
      }
      if(dp[i][amount]!=-1) return dp[i][amount];
      int ans=1e8;
      ans=min(ans,solve(i+1,amount,coins,dp));
      if(coins[i]<=amount){
        ans=min(ans,solve(i,amount-coins[i],coins,dp)+1);
      }
      return dp[i][amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vv32 dp(coins.size()+1,v32(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};

int main() {
    fast_cin();
    int n;
    cin>>n;
    int amount;
    cin>>amount;
    v32 arr(n);
    forsn(i,0,n){
      cin>>arr[i];
    }
    Solution obj1;
    cout<<obj1.coinChange(arr,amount);
    return 0;
}

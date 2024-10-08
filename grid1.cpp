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
const int INT_INF=1e9+7;
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

ll uniquePaths(vector<string>&grid,int i,int j,int n,int m,vv64 &dp){
  if(i==n-1 && j==m-1) return 1;
  if(i>=n || j>=m || grid[i][j]=='#') return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  dp[i][j]=(uniquePaths(grid,i+1,j,n,m,dp)%INT_INF+uniquePaths(grid,i,j+1,n,m,dp)%INT_INF)%INT_INF;
  return dp[i][j];
}

int main() {
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);  
    vv64 dp(n,v64(m,-1));
    forn(i,n){
      cin>>grid[i];
    }
    cout<<uniquePaths(grid,0,0,n,m,dp);
    return 0;
}
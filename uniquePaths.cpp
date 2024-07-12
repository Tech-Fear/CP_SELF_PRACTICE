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

ll uniquePaths(ll i,ll j,vv64 &grid,ll m,ll n){
  if(i>=m || j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  if (grid[i][j] != -1) return grid[i][j];
    grid[i][j] = uniquePaths(i + 1, j, grid, m, n) + uniquePaths(i, j + 1, grid, m, n);
    return grid[i][j];
}

int main() {
    fast_cin();
    ll m,n;
    cin>>m>>n;
    vv64 grid(m,v64(n,-1));
    cout<<uniquePaths(0,0,grid,m,n);
    return 0;
}
//iterative approch 
/*
  dp[n+1][m+1]
  dp[n-1][m-1]=1;
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      if(i==m-1 && j==m-1) continue;
      int ans=0;
      if(i+1<n) ans+=dp[i+1][j];
      id(j+1<m) ans+=dp[i][j+1];
    }
  }
  return dp[0][0];
*/
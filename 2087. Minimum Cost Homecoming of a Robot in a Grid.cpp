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

// class Solution {
// private:
//   int solve(int i,int j,int n,int m,vector<int>&rowCost,vector<int>&colCost){
//     if(i==n && j==m) return 0;
//     int ans=1e9;
//     if(i-1>=0){
//       ans=min(ans,solve(i-1,j,n,m,rowCost,colCost)+rowCost[i-1]);
//     }
//     if(i+1<rowCost.size()){
//       ans=min(ans,solve(i+1,j,n,m,rowCost,colCost)+rowCost[i+1]);
//     }
//     if(j+1<colCost.size()){
//       ans=min(ans,solve(i,j+1,n,m,rowCost,colCost)+colCost[j+1]);
//     }
//     if(j-1>=0){
//       ans=min(ans,solve(i,j-1,n,m,rowCost,colCost)+colCost[j-1]);
//     }
//     return ans;
//   }
// public:
//     int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
//         cout<<solve(startPos[0],startPos[1],homePos[0],homePos[1],rowCosts,colCosts);
//     }
// };

class Solution {
private:
  int solve(int i, int j, int n, int m, vector<int>& rowCost, vector<int>& colCost, vector<vector<int>>& memo) {
    if(i == n && j == m) return  ;
    if(memo[i][j] != -1) return memo[i][j];
    
    int ans = INT_MAX;
    if(i - 1 >= 0) {
      ans = min(ans, solve(i - 1, j, n, m, rowCost, colCost, memo) + rowCost[i]);
    }
    if(i + 1 < rowCost.size()) {
      ans = min(ans, solve(i + 1, j, n, m, rowCost, colCost, memo) + rowCost[i + 1]);
    }
    if(j - 1 >= 0) {
      ans = min(ans, solve(i, j - 1, n, m, rowCost, colCost, memo) + colCost[j]);
    }
    if(j + 1 < colCost.size()) {
      ans = min(ans, solve(i, j + 1, n, m, rowCost, colCost, memo) + colCost[j + 1]);
    }
    
    return memo[i][j] = ans;
  }
public:
  int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int rows = rowCosts.size();
    int cols = colCosts.size();
    vector<vector<int>> memo(rows, vector<int>(cols, -1));
    return solve(startPos[0], startPos[1], homePos[0], homePos[1], rowCosts, colCosts, memo);
  }
};

int main() {
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<int>start(2,0),home(2,0);
    vector<int>rowCost(n),colCost(m);
    Solution obj1;
    cout<<obj1.minCost(start,home,rowCost,colCost);
    return 0;
}
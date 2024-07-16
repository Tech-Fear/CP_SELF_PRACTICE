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
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vv32 dp(n+1,v32(m+1,0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
              dp[i][j]=min(dp[i-1][j]+1,min(dp[i-1][j-1]+1,dp[i][j-1]+1));
            }
          }
        }
        return dp[n][m];
    }
};

int solve(string w1,string w2,int i,int j,vv32 &dp){
  if(i==w1.length() && j==w2.length()){
    return 0;
  }
  if(dp[i][j]!=-1) return dp[i][j];
  if(w1[i]==w2[i]) return dp[i][j]=solve(w1,w2,i+1,j+1,dp);
  int del=solve(w1,w2,i+1,j,dp)+1;
  int ins=solve(w1,w2,i,j+1,dp)+1;
  int rep=solve(w1,w2,i+1,j+1,dp)+1;
  dp[i][j]= min(del,min(rep,ins));
  return dp[i][j];
}
int main() {
    fast_cin();
    string w,w2;
    cin>>w>>w2;
    int n=w.length();
    int m=w2.length();
    vv32 dp(n+1,v32(m+1,-1));
    Solution obj1;
    cout<<obj1.minDistance(w,w2);
    // cout<<solve(w,w2,0,0,dp);
    return 0;
}
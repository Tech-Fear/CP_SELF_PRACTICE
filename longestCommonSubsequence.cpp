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
// string solve(int n,int m,string s,string t,vector<vector<string>>&dp){
//   if(n==0||m==0) return "";
//   if(dp[n][m]!="!") return dp[n][m];
//   if(s[n-1]==t[m-1]) return dp[n][m]=solve(n-1,m-1,s,t,dp)+s[n-1];
//   string str1=solve(n-1,m,s,t,dp);
//   string str2=solve(n,m-1,s,t,dp);
//   return dp[n][m]=(str1.length()>str2.length()?str1:str2);
// }
// int main() {
//     fast_cin();
//     string s,t;
//     cin>>s>>t;
//     int n=s.length(),m=t.length();
//     vector<vector<string>>dp(n+1,vector<string>(m+1,"!"));
//     cout<<solve(n,m,s,t,dp);
//     return 0;
// }

// approch 2 Due to tle in testcases at atcoder
// int main() {
//     fast_cin();
//     string s,t;
//     cin>>s>>t;
//     int n=s.length(),m=t.length();
//     vector<vector<string>>dp(n+1,vector<string>(m+1,"0"));
//     for(int i=1;i<=n;i++){
//       for(int j=1;j<=m;j++){
//         if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+s[i-1];
//         else{
//           dp[i][j]=dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
//         }
//       }
//     }
//     cout<<dp[n][m];
//     return 0;
// }

//approch 3 building from dp table 
int main(){
 fast_cin();
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
      dp[i][m]=0;
    }
    for(int i=0;i<=m;i++){
      dp[n][i]=0;
    }
    for(int i=n-1;i>=0;i--){
      for(int j=m-1;j>=0;j--){
        if(s[i]==t[j]) dp[i][j]=dp[i+1][j+1]+1;
        else{
          dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        } 
      }
    }
    string ans;
    int i=0,j=0;
    while(i<n &&j<m){
      if(s[i]==t[j]){
        ans.push_back(s[i]);
        i++,j++;
      }else{
        if(dp[i+1][j]>dp[i][j+1]) i++;
        else j++;
      }
    }
    cout<<ans;
    return 0;
}
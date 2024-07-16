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


// int main() {
//     fast_cin();
//     string s;
//     cin>>s;
//     // lsc of string and its reverse gives the palindromic subsequence of the string 
    
//     return 0;
// }

int main(){
 fast_cin();
    string s;
    cin>>s;
    string s1=s;
    reverse(s1.begin(),s1.end());
    string t=s1;
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
    cout<<s.length()-ans.length();
    return 0;
}
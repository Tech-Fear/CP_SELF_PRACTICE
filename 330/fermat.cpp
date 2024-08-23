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

ll power(ll a,ll b,int p){
  if(b==0) return 1;
  int res=power(a,b/2,p);
  if(b&1){
    return (((res%p)*(res%p))%p*(a%p))%p;
  }else{
    return ((res%p)*(res%p))%p;
  }
}
bool primeCheck(int p){
  if(p==1) return true;
  if(p==2 || p==3) return true;
  if(p%2==0 || p%3==0) return false;
  for(int i=5;i*i<=p;i+=6){
    if(p%i==0 || p%(i+2)==0) return false;
  }
  return true;
}
void solve(int tc=0) {
  int p,a;
  cin>>p>>a;
  if(!primeCheck(p) || a<=0) {cout<<"First number should be prime and both should be positive integer\n";
  return ;}
  ll po=power(a,p-1,p);
  if(po%p==1) cout<<"Is prime";
  else cout<<"Not a prime";
}
int main() {
    fast_cin();
    solve();
    return 0;
}
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

//DSU implemetation 
class UnionFind{
  v32 p,rank,setSize;
  int numSets;
  public:
  UnionFind(int N){
    p.assign(N,0);
    forsn(i,0,N){
      p[i]=i;
    }
    rank.assign(N,0);
    setSize.assign(N,1);
    numSets=N;
  }
  int findSet(int i){
    if(p[i]==i) return i;
    return p[i]=findSet(p[i]);
  }
  bool isSameSet(int i,int j){
    if(findSet(i)==findSet(j)) return true;
    return false;
  }
  void unionSet(int i,int j){
    if(isSameSet(i,j)) return;
    int x=findSet(i);
    int y=findSet(j);
    if(rank[x]>rank[y]) swap(x,y);
    p[x]=y;
    if(rank[x]==rank[y]){
      rank[y]++;
    }
    setSize[y]+=setSize[x];
    numSets--;
  }
  int sizeOfSet(int i){
    return setSize[findSet(i)];
  }
  int numDisjointSets(){
    return numSets;
  }
};


void solve(int tc=0) {
}
int main() {
    fast_cin();
    solve();
    return 0;
}
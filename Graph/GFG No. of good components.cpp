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

// https://www.geeksforgeeks.org/problems/number-of-good-components--170647/0


class Solution {
    private:
        void dfs(map<int,vector<int>>&adj,vector<bool>&visited,int &edg,int &vertices,int s){
            visited[s]=true;
            edg+=adj[s].size();
            for(auto &d:adj[s]){
                if(!visited[d]){
                    vertices++;
                    dfs(adj,visited,edg,vertices,d);
                }
            }
        }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        int full=0;
        map<int,vector<int>>adj;
        for(auto &k:edges){
            int fir=k[0];
            int sec=k[1];
            adj[fir].push_back(sec);
            adj[sec].push_back(fir);
        }
        vector<bool>visited(v+1,false);
        for(int i=1;i<=v;i++){
            int edg=0;
            int vertices=1;
            if(!visited[i]){
                dfs(adj,visited,edg,vertices,i);
                if((vertices*(vertices-1))/2==edg/2) full++;
            }  
        }
        return full;
    }
};

void solve(int tc=0) {
  int v,e; // v -> number of vertices, e -> number of edges
  cin>>v>>e;
  vv32 edges(e,v32(2)); // stores the number of edges in format 1-2, 2-3 which tells that there is edges from 1 to 2 (Undirected)
  for(int i=0;i<e;i++){
    cin>>edges[i][0]>>edges[i][1];
  }
  Solution sol;
  cout<<sol.findNumberOfGoodComponent(e,v,edges);
}
int main() {
    fast_cin();
    solve();
    return 0;
}
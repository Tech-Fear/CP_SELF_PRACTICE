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
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>originalEdges=edges;
        for(auto &v:edges){
          int a=v[0];
          int b=v[1];
          int w=v[2];
          mp[a].push_back({b,w});
          mp[b].push_back({a,w});
        }
        auto dijkstra = [&](int start) {
            vector<int> dist(n, INF);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, start);
            dist[start] = 0;
            
            while (!pq.empty()) {
                int d, u;
                tie(d, u) = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (const auto& e : mp[u]) {
                    int v, w;
                    tie(v, w) = e;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            return dist;
        };
        vector<int> distFromSource = dijkstra(source);
        vector<int> distFromDest = dijkstra(destination);
        
        int originalDistance = distFromSource[destination];
        
        if (originalDistance > target) {
            return {{}};
        }
        vector<vector<int>>result=edges;
        for(auto &e:result){
          if(e[2]==-1){
            int u=e[0],v=e[1];
            int minWeight=max(1,target-(distFromSource[u]+distFromDest[v]));
            int maxWeight=target-(distFromSource[u]+distFromDest[v]);
            if(minWeight>maxWeight){
              return {{}};
            }
            e[2]=maxWeight;
            mp[u].push_back({v,e[2]});
            mp[v].push_back({u,e[2]});
          }
        }
        vector<int>newDistFromSource=dijkstra(source);
        if(newDistFromSource[destination]!=target)
          return {{}};
        return result;
    }
};

void solve(int tc=0) {
}
int main() {
    fast_cin();
    solve();
    return 0;
}
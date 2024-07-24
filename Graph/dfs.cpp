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
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
const ll MOD = 998244353;
const double eps = 1e-12;
#define forn(a, e) for (ll i = a; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
const int INTMOD = 1e9 + 7;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void dfs(int u, unordered_map<int, vector<int>> &arr, vector<bool> &visited, vector<int> &result)
{
  visited[u] = true;
  result.push_back(u);
  for (auto &v : arr[u])
  {
    if (!visited[v])
    {
      dfs(v, arr, visited, result);
    }
  }
}
int main()
{
  fast_cin();
  int n, e;
  cin >> n >> e;
  unordered_map<int, vector<int>> arr;
  for (int i = 0; i < e; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  vector<bool> visited(n + 1, false);
  vector<int> result;
  dfs(1, arr, visited, result);
  for (auto n : result)
  {
    cout << n << " ";
  }
  return 0;
}

 class Solution {
    private:
        int dx[8]={-1,-1,0,0,1,1,0,-1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        bool checkValid(int i,int j,int n,int m,vector<vector<char>>& grid){
            if(i>=m || j>=n || i<0 || j<0 ||grid[i][j]!='1') return false;
            return true;
        }
        void check(int i,int j,int n,int m,vector<vector<char>>& grid){
            grid[i][j]=-1;
            for(int z=0;z<=7;z++){
                int x=i+dx[z];
                int y=j+dy[z];
                if(checkValid(x,y,n,m,grid)){
                    check(x,y,n,m,grid);
                }
            }
            return;
        }
        
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int ans=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    check(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
 };
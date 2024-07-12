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

ll minFallingPath(vv64 &grid, ll i, ll j, ll m, ll n,vv64 &dp) {
    if (i >= n || j >= m || i < 0 || j < 0) return LLONG_MAX;
    if (i == n - 1) return grid[i][j];
    if (dp[i][j]!=-1) return dp[i][j];
    ll ans = LLONG_MAX;
    ans = min(ans, minFallingPath(grid, i + 1, j, m, n,dp) + grid[i][j]);
    if (j + 1 < m) ans = min(ans, minFallingPath(grid, i + 1, j + 1, m, n,dp) + grid[i][j]);
    if (j - 1 >= 0) ans = min(ans, minFallingPath(grid, i + 1, j - 1, m, n,dp) + grid[i][j]);

  return dp[i][j]=ans;
}
ll findMinFallingPathSum(vv64 &grid) {
    ll m = grid[0].size();
    ll n = grid.size();
    ll minSum = LLONG_MAX;
    vv64 dp(n,v64(m,-1));
    for (ll j = 0; j < m; j++) {
        minSum = min(minSum, minFallingPath(grid, 0, j, m, n,dp));
    }

    return minSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vv64 grid(n, v64(m));
    forn(i, n) {
        forn(j, m) {
            cin >> grid[i][j];
        }
    }
    ll result = findMinFallingPathSum(grid);
    cout << result << endl;

    return 0;
}

/*
    ll findMinFallingPathSum(vv64 &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vv64 dp(n, v64(m, LLONG_MAX));
    for (int j = 0; j < m; j++) {
        dp[n - 1][j] = grid[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            ll ans = dp[i + 1][j]; // move down
            if (j > 0) ans = min(ans, dp[i + 1][j - 1]);
            if (j < m - 1) ans = min(ans, dp[i + 1][j + 1]);
            dp[i][j] = grid[i][j] + ans;
        }
    }

    // Find the minimum value in the first row
    ll minSum = LLONG_MAX;
    for (int j = 0; j < m; j++) {
        minSum = min(minSum, dp[0][j]);
    }

    return minSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vv64 grid(n, v64(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    ll result = findMinFallingPathSum(grid);
    cout << result << endl;

    return 0;
}
*/
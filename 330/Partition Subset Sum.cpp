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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool partitionCheck(v32 &arr, vv32 &dp, int i, int sum, int &x)
{
    if (i == arr.size())
    {
        return 2 * sum == x;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int include = partitionCheck(arr, dp, i + 1, sum + arr[i], x);
    int exclude = partitionCheck(arr, dp, i + 1, sum, x);
    return dp[i][sum] = include || exclude;
}

void solve()
{
    int n;
    cin >> n;
    v32 arr(n);
    int x = 0;
    forn(0, n)
    {
        cin >> arr[i];
        x += arr[i];
    }
    if (x % 2 != 0)
    {
        cout << 0;
        return;
    }
    vv32 dp(n, v32(x, -1));
    cout << partitionCheck(arr, dp, 0, 0, x);
}

void partiton()
{
    int n;
    cin >> n;
    v32 arr(n);
    int x = 0;
    forn(0, n)
    {
        cin >> arr[i];
        x += arr[i];
    }
    if (x % 2 != 0)
        cout << 0;
    else
    {
        int target = x / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        cout << dp[target];
    }
}
int main()
{
    fast_cin();
    int tc = 1;
    // cin>>tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
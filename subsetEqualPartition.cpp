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
private:
    int solve(int i, int sum, int x, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) {
            return (x - (2 * sum)) == 0 ? 1 : 0;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        int include = (nums[i] <= x) ? solve(i + 1, sum + nums[i], x, n, nums, dp) : 0;
        int exclude = solve(i+1,sum,x,n,nums,dp);
        return dp[i][sum] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (auto i : nums){
            x+=i;
        }
        vector<vector<int>> dp(n, vector<int>(x, -1));
        return solve(0, 0, x, n, nums, dp);
    }
};
int main() {
    fast_cin();
    return 0;
}


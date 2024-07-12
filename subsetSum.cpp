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


// bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//     if (target == 0)
//         return true;
//     if (ind == 0)
//         return arr[0] == target;
//     if (dp[ind][target] != -1)
//         return dp[ind][target];
//     bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
//     bool taken = false;
//     if (arr[ind] <= target)
//         taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
//     return dp[ind][target] = notTaken || taken;
// }
// bool subsetSumToK(int n, int k, vector<int>& arr) {
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return subsetSumUtil(n - 1, k, arr, dp);
// }

// int main() {
//     vector<int> arr = {1, 2, 3, 4};
//     int k = 4;
//     int n = arr.size();
//     if (subsetSumToK(n, k, arr))
//         cout << "Subset with the given target found";
//     else
//         cout << "Subset with the given target not found";

//     return 0;
// }

int subset(int i,int sum,vector<int>&A,int k){
  if(i==A.size()-1){
    if(sum==k) {
      return 1;
    }
    return 0;
  }
  // if(dp[sum]!=-1) return 
  int choose=subset(i+1,sum+A[i],A,k);
  int not_choose=subset(i+1,sum,A,k);
  return choose||not_choose;
}
int main(){
  fast_cin();
  int n,k;
  cin>>n>>k;
  v32 A(n);
  vector<int>dp(n,-1);
  forn(i,n){
    cin>>A[i];
  }
  int a=subset(0,0,A,k);
  cout<<a;
  return 0;
}

/*
  bool subset(int i, int sum, vector<int> &A, int k) {
    if (i == A.size()) {
        return sum == k;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    
    bool choose = subset(i + 1, sum + A[i], A, k);
    bool not_choose = subset(i + 1, sum, A, k);
    
    return dp[i][sum] = choose || not_choose;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Initialize dp with -1
    dp.resize(n + 1, vector<int>(total_sum + 1, -1));
    
    bool result = subset(0, 0, A, k);
    cout << (result ? 1 : 0) << endl;
    
    return 0;
}

*/
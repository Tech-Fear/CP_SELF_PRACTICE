// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> p32;
// typedef pair<ll,ll> p64;
// typedef pair<double,double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int>> vv32;
// typedef vector<vector<ll>> vv64;
// typedef vector<vector<p64>> vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// const ll MOD = 998244353;
// const double eps = 1e-12;
// #define forn(a,e) for(ll i = a; i < e; i++)
// #define forsn(i,s,e) for(ll i = s; i < e; i++)
// #define rforn(i,s) for(ll i = s; i >= 0; i--)
// #define rforsn(i,s,e) for(ll i = s; i >= e; i--)
// #define ln "\n"
// #define dbg(x) cout<<#x<<" = "<<x<<ln
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// const int INTMOD = 1e9+7;
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())

// ll power(ll x, ll y)
// {
//     ll temp;
//     if (y == 0)
//         return 1;
//     temp = power(x, y / 2);
//     if (y % 2 == 0)
//         return (temp%INTMOD * temp%INTMOD)%INTMOD;
//     else
//         return ((x%INTMOD * temp%INTMOD)%INTMOD * temp%INTMOD)%INTMOD;
// }
// void solve(ll n,ll k){
//   ll ans=power(n,k);
//   cout<<ans<<endl;

// }

// int main() {
//     fast_cin();
//     int t;
//     cin>>t;
//     while(t--){
//       ll n,k;
//       cin>>n>>k;
//       solve(n,k);
//     }
//     return 0;
// }






// long long solve(vector<int>& A) {
//     long long ans = LLONG_MIN;
//     int n = A.size();
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             long long len1 = A[i];
//             long long len2 = A[j];
//             if (len1 >= 2 && len2 >= 2) { 
//                 long long calc = (len1 - 1) * (len2 - 1);
//                 ans = max(ans, calc);
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     vector<int>A(n);
//     for(int i=0;i<n;i++){
//       cin>>A[i];
//     }
//     long long out=solve(A);
//     cout<<out<<endl;
//   }
//   return 0;
// }



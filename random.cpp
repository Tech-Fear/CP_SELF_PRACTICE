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

// v64 findSeq(ll n){
//   v64 seq;
//   ll cur=1;
//   while(cur<=n){
//     seq.push_back(cur);
//     cur=cur|(cur+1);
//   }
//   return seq;
// }

// void solve() {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     int cnt[2] = {0};
//     string st;
//     st.push_back(s[0]);
//     for (int i = 1; i < n; i++) {
//         if (s[i] == s[i - 1] && s[i] == '0')
//             continue;
//         st.push_back(s[i]);
//     }
//     for (int i = 0; i < st.size(); i++)
//         cnt[st[i] - '0']++;
//     cout << ((cnt[1] > cnt[0]) ? "Yes" : "No") << endl;
// }

// int main() {
//   fast_cin();
//   int t;
//   cin>>t;
//   while(t--){
//     solve();
//   }
//   return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long int
// #define vi vector<int>
// #define read(a)     \
//   for (auto &i : a) \
//   cin >> i
// // #define mod 998244353
// #define mod 1000000007

// signed main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int t = 1;
//   cin >> t;
//   // sieve();
//   while (t--)
//   {
//      int n;
//      cin >> n;
//      int k;
//      cin >> k;
//      if (n == 1)
//     {
//        cout << 0 << endl;
//        continue;
      
//     }
//      int ans = 0;
//     k--;
//      while (n > 1)
//     {
//        n = n - k;
//        ans++;
      
//     }
//     cout << ans << endl;
//   }

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

 
#define int long long int
#define vi vector<int>
#define read(a) for(auto &i: a) cin>>i
// #define mod 998244353
#define mod 1000000007

 
signed main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t=1;
 cin>>t;
 // sieve();
 while(t--){
  int n;
  cin>>n;
  int ans=0;
  vector<int> v;
  vector<int> bits;
  for(int i=0;i<61;i++){
   if(n & (1ll<<i)){ans++;bits.push_back((1LL<<i));}
  }
  ans++;
  // cout<<ans<<endl;
  v.push_back(n);
  for(auto it:bits){
   if(n-it>0){
    v.push_back(n-it);
   }
  }
  
  reverse(v.begin(),v.end());
  cout<<v.size()<<endl;
  for(auto it:v){
   cout<<it<<" ";
  }
  cout<<endl;
 }
 // 8
// 00000111
 return 0;
}
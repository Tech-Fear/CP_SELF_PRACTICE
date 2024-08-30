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
    string findOrder(string dict[], int n, int k) {
        // code here
        string ans="";
        if(n==0 || k==0) return ans;
        vector<int>indegree(k,0);
        unordered_map<char,vector<char>>mp;
        for(int i=1;i<n;i++){
            string prv=dict[i-1];
            string cur=dict[i];
            if((prv.length()==cur.length()+1)&&(prv.substr(0,cur.length())==cur)) return ans;
            for(int k=0;k<min(prv.size(),cur.size());k++){
                char c1=prv[k];
                char c2=cur[k];
                if(c1!=c2){
                    mp[c1].push_back(c2);
                    indegree[c2-'a']++;
                    break;
                }
            }
        }
        set<char>st;
        for(int i=0;i<n;i++){
            string s=dict[i];
            for(auto &c:s){
                st.insert(c);
            }
        }
        auto comp=[](const char &a,const char &b){
            return a>b;
        };
        priority_queue<char,vector<char>,decltype(comp)>pq(comp);
        for(const char &c:st){
            if(indegree[c-'a']==0){
                pq.push(c);
            }
        }
        // topological sort
        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();
            ans+=ch;
            for(auto &q:mp[ch]){
                indegree[q-'a']--;
                if(indegree[q-'a']==0) pq.push(q);
            }
        }
        if(ans.size()!=st.size()){
            return "";
        }
        return ans;
        
    }
};


void solve(int tc=0) {
  int n,k;
  cin>>n>>k;
  string dict[n];
  for(int i=0;i<n;i++){
    cin>>dict[i];
  }
  Solution sol;
  cout<<endl;
  cout<<sol.findOrder(dict,n,k);
}
int main() {
    fast_cin();
    solve();
    return 0;
}
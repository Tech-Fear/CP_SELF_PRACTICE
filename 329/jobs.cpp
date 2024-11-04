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

struct task{
    char id;
    int deadline;
    int profits;
};
static bool comp(task &t1, task &t2){
    return t1.deadline<t2.deadline;
}
void solve() {  
    vector<task>jobs;
    int n;
    cin>>n;
    forn(0,n){
        task task1;
        cin>>task1.id>>task1.deadline>>task1.profits;
        jobs.push_back(task1);
    }
    sort(jobs.begin(),jobs.end(),comp);
    int tem=1;
    for(int i=0;i<n;i++){
        if(jobs[i].deadline!=tem && tem<=jobs[i].deadline){
            jobs[i].deadline=tem;
            tem++;
        }else{
            tem++;
        }
    }
    int maxProfits=jobs[0].profits;
    for(int i=1;i<n;i++){
        if(jobs[i].deadline!=jobs[i-1].deadline){
            maxProfits+=jobs[i].profits;
        }else{
            
        }
    }
    cout<<maxProfits;

}
int main() {
    fast_cin();
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
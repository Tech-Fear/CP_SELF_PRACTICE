#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define mod 1000000007
using namespace std;

long long int pwr(ll a,ll b,int mo){
  long long int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mo;
        }
        a = (a * a) % mo;
        b /= 2;
    }
    return res;
}
void solution(vector<string>&A){
  int n=A.size();
  vector<long long int>an(n);
  for(int i=0;i<n;i++){
    int pref[A[i].size()]={0};
    for(int j=1;j<A[i].size();j++){
      int x=pref[j-1];
      while(x>0 && A[i][j]!=A[i][x]){
        x=A[i][x-1];
      }
      if(A[i][j]==A[i][x]) x++;
      pref[j]=x;
    }
    int len=A[i].size()-pref[A.size()-1];
    int finn=A[i].size();
    if(finn%len==0) finn=len;
    int op=1;
    ll sum=1;
    while(1){
      if(sum%finn==0 ) break;
      op++;
      sum+=op;
    }
    an[i]=op;
  }
  long long int lcm=1;
  map<long long int,long long int>mp;
for(int i=0;i<an.size();i++){
  for(int j=2;j*j<=an[i];j++){
    int cnt=0;
    while(an[i]%j==0){
      an[i]/=j;
      cnt++;
    }
    if(cnt>0) mp[j]=max(mp[j],(ll)cnt);
  }
  if(an[i]>1){
    mp[an[i]]=max(mp[an[i]],(ll)1);
  }
}
long long int res=1;
for(auto it:mp){
    res=(res*pwr(it.first,it.second,mod))%mod;
}
cout<<res;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<string>str(n);
for(int i=0;i<n;i++){
  cin>>str[i];
}
  solution(str);
return 0;
}
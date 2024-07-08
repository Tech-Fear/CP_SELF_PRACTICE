#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
#define mod 1000000007

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
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vi arr(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}
long long int lcm=1;
map<long long int,long long int>mp;
for(int i=0;i<arr.size();i++){
  for(int j=2;j*j<=arr[i];j++){
    int cnt=0;
    while(arr[i]%j==0){
      arr[i]/=j;
      cnt++;
    }
    if(cnt>0) mp[j]=max(mp[j],(ll)cnt);
  }
  if(arr[i]>1){
    mp[arr[i]]=max(mp[arr[i]],(ll)1);
  }
}
long long res=1;
for(auto it:mp){
    res=(res*pwr(it.first,it.second,mod))%mod;
}
cout<<res;
return 0;
}
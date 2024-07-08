#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
  string s,t;
  cin>>s>>t;
  int n=s.length();
  s+='#';
  s+=t;
  int ans=0;
  int kmp[s.size()]={0};
  for(int i=1;i<s.size();i++){
    int x=kmp[i-1];
    while(x>0 && s[i]!=s[x]){
      x=kmp[x-1];
    }
    if(s[x]==s[i]) x++;
    kmp[i]=x;
    if(x==n) ans++;
  }
  cout<<ans<<endl;
return 0;
}
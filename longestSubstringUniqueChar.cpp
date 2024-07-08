#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
  string s;
  cin>>s;
  unordered_map<char,int>mp;
  int ans=0;
  int l=0;
  for(int i=0;i<s.length();i++){
    if(mp.count(s[i])==0||mp[s[i]]<l){
      ans=max(ans,i-l+1);
      mp[s[i]]=i;
    }else{
      l=mp[s[i]]+1;
      mp[s[i]]=i;
    }
  }
  cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
//no of subarray sum equals k
int main()
{
std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int k;
  cin>>k;
  unordered_map<int,int>mp;
  int count=0;
  int cur=0;
  mp[0]=1;
  for(int i=0;i<n;i++){
    cur+=arr[i];
    if(mp.find(cur-k)!=mp.end()){
      count+=mp[cur-k];
    }
    mp[cur]++;
  }
  cout<<count;
  return 0;
}


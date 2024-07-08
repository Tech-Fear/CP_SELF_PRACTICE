#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  set<int>s1;
  int ans=0;
  int max=0;
  for(int i=0;i<n;i++){
    s1.insert(arr[i]);
    max=*max_element(s1.begin(),s1.end());
    if(i==max){
      ans++;
    }
  }
  cout<<ans<<endl;
    return 0;
}
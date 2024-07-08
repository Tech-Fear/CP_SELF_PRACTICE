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
  int x,k;
  vi arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>x>>k;
  int freq=0;
  for(int i=0;i<k;i++){
    if(arr[i]==x)
    freq++;
  }
  for(int i=k;i<n;i++){
    if(arr[i-k]==x) freq--;
    if(arr[i]==x) freq++;
    cout<<freq<<endl;
  }
  return 0;
}
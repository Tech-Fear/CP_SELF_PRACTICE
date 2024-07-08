#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
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
  //given array is sorted
  int k;
  cin>>k;
  int l=0,r=n-1;
  int ans=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(mid>l && arr[mid-1]==k){
      r=mid-1;
    }else if(arr[mid]==k){
      ans=mid;
      break;
    }else if(arr[mid]<k){
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  cout<<ans<<endl;
  l=0;r=n-1;
   while(l<=r){
    int mid=l+(r-l)/2;
    if(mid<r && arr[mid+1]==k){
      l=mid+1;
    }else if(arr[mid]==k){
      ans=mid;
      break;
    }else if(arr[mid]<k){
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  cout<<ans;
  return 0;
}
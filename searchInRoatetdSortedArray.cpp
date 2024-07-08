#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int peakElement = INT_MIN;
  int ind = -1;
  int l = 0, r = n - 1;

  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if ((mid == n - 1 || arr[mid] > arr[mid + 1]) && (mid == 0 || arr[mid] > arr[mid - 1]))
    {
      ind = (ind == -1 || arr[ind] < arr[mid]) ? mid : ind;
      peakElement=arr[ind];
      break;
    }
    else if (arr[mid] < arr[mid + 1])
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  int targ;
  cin>>targ;
  int ans=-1;
  l=0;
  int h=ind;
  while(l<=h){
    int mid=l+(h-l)/2;
    if(arr[mid]==targ){
      ans=mid;
      break;
    }else if(arr[mid]<targ){
      l=mid+1;
    }else{
      h=mid-1;
    }
  }
  l=ind+1;
  h=n-1;
  while(l<=h){
    int mid=l+(h-l)/2;
    if(arr[mid]==targ){
      ans=mid;
      break;
    }else if(arr[mid]<targ){
      l=mid+1;
    }else{
      h=mid-1;
    }
  }
  cout<<ans;
  return 0;
}
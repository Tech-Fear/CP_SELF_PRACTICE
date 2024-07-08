#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int hours(vi &arr,int mid){
  int sum=0;
  for(int i=0;i<arr.size();i++){
    sum+=ceil(arr[i]/(double)mid);
  }
  return sum;
}
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
cin>>n;
vi arr(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}
int h;
cin>>h;
int l=1,hi=*max_element(arr.begin(),arr.end());
while(l<=hi){
  int mid=l+(hi-l)/2;
  int ho=hours(arr,mid);
  if(ho>h){
    l=mid+1;
  }else{
    hi=mid-1;
  }
}
cout<<l;
return 0;
}

// class Solution {
// public:
//     int hours(vector<int> &arr,int mid){
//         int hou=0;
//         for(int i=0;i<arr.size();i++){
//             hou+=ceil(arr[i]/(double)mid);
//         }
//         return hou;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int l=1,hi=*max_element(piles.begin(),piles.end());
//         while(l<=hi){
//             int mid=l+(hi-l)/2;
//             int ho=hours(piles,mid);
//             if(ho>h){
//                 l=mid+1;
//             }else{
//                 hi=mid-1;
//             }
//         }
//         return l;
//     }
// };
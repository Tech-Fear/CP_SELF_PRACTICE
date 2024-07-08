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
  vi arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int prod=1;
  int maxProd=INT_MIN;
  for(int i=0;i<n;i++){
    prod*=arr[i];
    maxProd=max(prod,maxProd);
    if(prod==0) prod=1;
  }
  prod=1;
  for(int i=n-1;i>=0;i--){
    prod*=arr[i];
    maxProd=max(prod,maxProd);
    if(prod==0) prod=1;
  }
  cout<<maxProd;
    return 0;
}
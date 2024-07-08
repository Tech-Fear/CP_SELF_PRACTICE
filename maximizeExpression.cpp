// Array of n and p,q,r select indexes i j k such that i<j<k, value =arr[i]*p+arr[j]*q+arr[k]*r
#include<bits/stdc++.h>
#include<algorithm>
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
  int p,q,r;
  cin>>p>>q>>r;
  int f=-1,j=-1,k=-1;
  vll pArr;
  for(int i=0;i<n;i++){
     pArr[i] = max(pArr[i-1], (ll)arr[i] * p);
  }
  vll rArr(n);
    rArr[n-1]=arr[n-1] * r;
    for(int i=n-2;i>=0;i--) {
        rArr[i]=max(rArr[i+1],(ll)arr[i] * r);
    }
    ll maxSum=LLONG_MIN;
    for(int j=1;j<n-1;j++) {
        ll currentSum=pArr[j-1]+(ll)arr[j]*q+rArr[j+1];
        maxSum=max(maxSum,currentSum);
    }

    cout << maxSum << endl;
  return 0;
}
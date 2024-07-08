#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  int arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  int pref[n][m];
  pref[0][0]=arr[0][0];
  for(int i=1;i<n;i++){
    pref[i][0]=pref[i-1][0]+arr[i][0];
  }
  for(int j=1;j<m;j++){
    pref[0][j]=pref[0][j-1]+arr[0][j];
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
    }
  }
    return 0;
}
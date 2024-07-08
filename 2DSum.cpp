#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
cin>>n>>m;
int arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[n][m];
    }
  }
  int pre[n][m];
  pre[0][0]=arr[0][0];
  for(int i=1;i<n;i++){
    pre[i][0]=pre[i-1][0]+arr[i][0];
  }
  for(int i=0;i<m;i++){
    pre[0][i]=pre[0][i-1]+arr[0][i];
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+arr[i][j];
    }
  }
  int t;
  cin>>t;
  while(t--){
    int ur,lc,br,rc;
    cin>>ur>>lc>>br>>rc;
    int ans=pre[br][rc]-pre[ur-1][rc]-pre[br][lc-1]+pre[ur-1][lc-1];
    cout<<ans<<endl;
  }
    return 0;
}
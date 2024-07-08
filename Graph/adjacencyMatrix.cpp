#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int n,m;
cin>>n>>m;
int arr[n][n]={0};
for(int i=0;i<n;i++){
  int a,b;
  cin>>a>>b;
  arr[a][b]=1;
  arr[b][a]=1;
}
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++)
    cout<<arr[i][j]<<" ";
  cout<<endl;
}
return 0;
}
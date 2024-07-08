#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
vi calculateManhattan(vector<string>&grid,int n,int m){
  int minRow=n,maxRow=-1;
  int minCol=m,maxCol=-1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='#'){
        minRow=min(i,minRow);
        maxRow=max(i,maxRow);
        minCol=min(j,minCol);
        maxCol=max(j,maxCol);
      }
    }
  }
  int centerRow=(minRow+maxRow)/2+1;
  int centerCol=(minCol+maxCol)/2+1;
  cout<<centerRow<<" "<<centerCol<<endl;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
      cin>>grid[i];
    }
    calculateManhattan(grid,n,m);
  }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int maxi=0;
    int sumMax=0;
    int i=2;
    while(i<=n){
      int x=n/i;
      int sum=(i*((x)*(x+1))/2);
      if(sumMax<sum){
        sumMax=sum;
        maxi=i;
      }
      i++;
    }
    cout<<maxi<<endl;
  }
    return 0;
}
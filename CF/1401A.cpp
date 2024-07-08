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
  int a,b;
  cin>>a>>b;
  if(a<b){
    cout<<b-a<<endl;
  }else{
    cout<<(a-b)%2<<endl;
  }
}
return 0;
}
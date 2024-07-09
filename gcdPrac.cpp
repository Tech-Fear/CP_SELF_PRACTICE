#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int gdc(int a,int b){
  if(a==0) return b;
  return gdc(b%a,a);
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int a,b;
cin>>a>>b;
cout<<gdc(a,b);
return 0;
}
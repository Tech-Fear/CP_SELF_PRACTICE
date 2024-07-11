#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
void binary(int n){
  string s="";
  while(n){
    s=(char)(n%2+'0') +s;
    n=n/2;
  }
  cout<<s;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
// int n;
// cin>>n;
// binary(n);
// int a = (n & ~(1<<3));
// cout<<endl;
// toggle kth bit N = N^(i<<k)
// check set kth bit N = N &(i<<k)
// kth bit set N = N | (1<<k)
// kth bit unset N = N & ~(1<<k)
// count No of set bits
//
/* a=a^b;
b=a^b;
a=a^b;   */
cout<<INT_MAX<<endl;
int a = (1ll<<31)-1;
cout<<a<<endl;
int b=((1<<30)-1)*2+1;
cout<<b;
return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int fib(int n,vector<int>&memo){
  if(memo[n]!=-1){
    return memo[n];
  }
  if(n==0 || n==1) return n;
  int result=fib(n-1,memo)+fib(n-2,memo);
  memo[n]=result;
  return result;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
int a=0,b=1,c=1;
int temp=n;
while(n>=2){
  c=a+b;
  a=b;
  b=c;
  n--;
}
vector<int>memo(temp+2,-1);
memo[0]=0;
memo[1]=1;
cout<<c<<endl;
cout<<fib(temp,memo);

vector<int>dp(temp+2);
dp[0]=0,dp[1]=1;
for(int i=2;i<=temp;i++){
  dp[i]=dp[i-1]+dp[i-2];
}
cout<<endl<<dp[temp];

return 0;
}
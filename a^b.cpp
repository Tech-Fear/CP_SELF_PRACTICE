#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
const int MOD=1e9+7;
int power(int a,int b){
  if(b==0) return 1;
  int temp=power(a,b/2);
  if(b%2==0) return (temp%MOD*temp%MOD)%MOD;
  return (((a%MOD*temp%MOD)%MOD)*temp%MOD)%MOD;
}

const int Mod=MOD-1;
int expo(int a,int b){
  if(b==0){
    return 1;
  }
  int temp=expo(a,b/2);
  if(b%2==0) return (temp%Mod*temp%Mod)%Mod;
  return (((temp%Mod *temp%Mod)%Mod)*a%Mod)%Mod;
}
int main()
{

std::ios::sync_with_stdio(false);
cin.tie(nullptr);
  cout<<power(66,4);

  //iterative approch 
  long long res=1;
  int n=5;
  int x=5;

  while(n>0){
    if(n&1==1) res=res*x;
    x*=x;
    n/=2;;
  }
  cout<<endl<<res;

  int a,b,c;
  a=10,b=2,c=2;
  int ans=expo(b,c);
  cout<< endl<<power(a,ans);
return 0;
}

// case 1. a very large then a%MOD and then calculate it 
// case 2. Mod is large 
// case 3. ETF=Euler totient function , if mod is prime then a^(b^c) => a^(b^c(mod MOD-1))%MOD;  

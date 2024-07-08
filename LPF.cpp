#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
vi primes;
void sieve(int &maxEle){
  vector<bool>visit(maxEle+1,true);
  visit[0]=visit[1]=false;
  for(int i=2;i<=maxEle;i++){
    if(visit[i]){
      for(int j=i*i;j<maxEle;j++){
        visit[j]=false;
      }
    }
  }
  for(int i=0;i<visit.size();i++){
    if(visit[i])
    primes.push_back(i);
  }
}

void lpf(vi &arr){
  for(int &p:primes){
    for(int i=0;i<arr.size();i++){
      if(arr[i]%p==0) arr[i]=p;
    }
  }
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int n;
cin>>n;
vi arr(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}
int maxEle=*max_element(arr.begin(),arr.end());
sieve(maxEle);
lpf(arr);
for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";
}
return 0;
}
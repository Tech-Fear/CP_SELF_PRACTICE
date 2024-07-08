#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
const int MOD=1e9+7;
using namespace std;
int binaryMulti(int a,int b){
  if(b==0) return 0;
  int k=binaryMulti(a, b/2);
  k=(k+k)%MOD;
  if (b % 2 == 1) {
        return (a+k)%MOD;
    } else {
      return k;
    }
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int binaryMulti(int a,int b){
  if(b==0) return 0;
  if (b % 2 == 1) {
        return a + binaryMulti(a, b - 1);
    } else {
      return binaryMulti(a << 1, b >> 1);
    }
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}
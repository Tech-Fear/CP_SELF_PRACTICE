#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;

int findLength(string &s1,string &s2){
  unordered_map<char,int>se1;
  unordered_map<char,int>se2;
  for(char i:s1){
    se1[i]++;
  }
  int count=0;
  for(char i:s2){
    if(se1[i]){
      se1[i]--;
      count++;
    }
  }
  return count;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin>>t;
while(t--){
  string a,b;
  cin>>a>>b;
  int s=findLength(a,b);
  cout<<a.length()+b.length()-s<<endl;
}
return 0;
}
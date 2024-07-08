#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vi sub(n);
    for(int i=0;i<n;i++){
      cin>>sub[i];
    }
    vi prs(n);
    prs[0]=sub[0];
    for(int i=1;i<n;i++){
      prs[i]=sub[i]+prs[i-1];
    }
    int l,r;
    cin>>l>>r;
    l--;r--;
    if(l==0){
      cout<<prs[r];
    }
    else{
      cout<<prs[r]-prs[l];
    }
    return 0;
}
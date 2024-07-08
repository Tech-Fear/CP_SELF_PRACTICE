#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vi uni;
  vi once;
  cout<<arr[0]<<endl;
  for(int i=1;i<n;i++){
    if(arr[i]!=arr[i-1])
    cout<<arr[i]<<endl; 
  }
  cout<<"\nOnly Once:\n";
  if(arr[0]!=arr[1]) cout<<arr[0]<<endl;
  for(int i=1;i<n-1;i++){
   if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]) {
      cout << arr[i] << endl;
    }
  }
  if(arr[n-1]!=arr[n-2]){
    cout<<arr[n-1];
  }
    return 0;
}
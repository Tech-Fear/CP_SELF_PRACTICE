#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  int count = 0;
  int left = 0, right = n - 1;
  while (left < right)
  {
    if (arr[left] + arr[right] <= target)
    {
      count += (right - left);
      left++;
    }
    else
    {
      right--;
    }
  }
  cout << count<<endl;
  // Binary search approch
  int ans=0;
  for (int i = 0; i < n; i++)
  {
    int low = i, high = n - 1;
    int check = target - arr[i];
    int ind = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] <= check)
      {
        ind = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    if(ind!=-1) ans+=(ind-i);
  }
  cout<<ans;
  return 0;
}
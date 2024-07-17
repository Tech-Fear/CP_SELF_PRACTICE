#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>>arr(n,vector<int>(n,0));
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a-1][b-1] = 1;
    arr[b-1][a-1] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}
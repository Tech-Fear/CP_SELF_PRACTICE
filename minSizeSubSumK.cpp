// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vll vector<long long int>
// using namespace std;
// int main()
// {
//   std::ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;
//   cin >> n;
//   vi arr(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   int k;
//   cin >> k;
//   vi prs(n + 1);
//   for (int i = 1; i < n; i++)
//   {
//     prs[i] = prs[i - 1] + arr[i];
//   }
//   int l = 1, r = n;
//   int ans = 0;
//   while (l <= r)
//   {
//     int mid = l + (r - l) / 2;
//     int z=0;
//     for (int i = mid; i <= n; ++i)
//     {
//       if (prs[i] - prs[i - mid] >= k)
//       {
//         z=1;
//         break;
//       }
//     }
//     if (z)
//     {
//       ans = mid;
//       r = mid - 1;
//     }
//     else
//     {
//       l = mid + 1;
//     }
//   }
//   cout << ans;
//   return 0;
// }

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0,right=0,sum=0;
        int n=nums.size();
        while(left<n || right<n ){
            if(sum<target && right<n){
                sum+=nums[right];
                right++;
            }else if(sum>=target && left<n){
                ans=min(ans,right-left);
                sum-=nums[left];
                left++;
            }else break;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
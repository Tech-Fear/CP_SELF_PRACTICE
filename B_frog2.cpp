#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int calc(vector<int>& arr, int n, int ind, int k) {
    if (ind == n - 1) return 0;
    if (dp[ind] != -1) return dp[ind]; 

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (ind + i < n) {
            ans = min(ans, calc(arr, n, ind + i, k) + abs(arr[ind] - arr[ind + i]));
        }
    }
    return dp[ind] = ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    dp.resize(n, -1); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << calc(arr, n, 0, k);
    return 0;
}



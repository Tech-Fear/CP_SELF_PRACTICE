// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vll vector<long long int>
// using namespace std;

// int vacation(vector<vi> &arr, int j, int i) {
//     if (i == arr.size()) return 0;
//     if (j == -1) {
//         return max({vacation(arr, 0, i + 1) + arr[i][0],
//                     vacation(arr, 1, i + 1) + arr[i][1],
//                     vacation(arr, 2, i + 1) + arr[i][2]});
//     } else if (j == 0) {
//         return max(vacation(arr, 1, i + 1) + arr[i][1], vacation(arr, 2, i + 1) + arr[i][2]);
//     } else if (j == 1) {
//         return max(vacation(arr, 2, i + 1) + arr[i][2], vacation(arr, 0, i + 1) + arr[i][0]);
//     } else {
//         return max(vacation(arr, 1, i + 1) + arr[i][1], vacation(arr, 0, i + 1) + arr[i][0]);
//     }
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<vi> arr(n, vi(3));
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
//     }

//     cout << vacation(arr, -1, 0);
//     return 0;
// }


#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;

int vacation(vector<vi> &arr) {
    int n = arr.size();
    vector<vi> dp(n, vi(3, 0));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vi> arr(n, vi(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    cout << vacation(arr);
    return 0;
}

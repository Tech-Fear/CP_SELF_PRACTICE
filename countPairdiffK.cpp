#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& nums, int k, int mid) {
    int count = 0;
    for (int left = 0, right = 0; right < nums.size(); right++) {
        while (nums[right] - nums[left] > mid) {
            left++;
        }
        count += (right - left);
    }
    return (count >= k);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    int k;
    cin >> k;
    
    sort(vec.begin(), vec.end());
    int left = 0;
    int right = vec[n-1] - vec[0];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValid(vec, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}



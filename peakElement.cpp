#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int peakElement = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if ((mid <=r && arr[mid] > arr[mid + 1]) && (mid>=l && arr[mid] > arr[mid - 1]))
        {      peakElement=arr[peakElement]>arr[mid]?peakElement:mid;
            break;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << peakElement;
    return 0;
}
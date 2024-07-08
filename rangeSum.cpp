#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vi arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vi calc(n, 0);
    
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        calc[a] += c;
        if (b + 1 < n) {
            calc[b + 1] -= c;
        }
    }
    
    for(int i = 1; i < n; i++){
        calc[i] += calc[i - 1];
    }
    
    for(int i = 0; i < n; i++){
        calc[i] += arr[i];
    }
    
    for(int i : calc){
        cout << i << " ";
    }
    return 0;
}

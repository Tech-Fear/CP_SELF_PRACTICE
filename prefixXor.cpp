#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
using namespace std;

void pref(int n, vi &prefixXor, vi &arr) {
    prefixXor[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixXor[i] = arr[i] ^ prefixXor[i - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vi prefixXor(n);
    pref(n, prefixXor, arr);
    
    int a, b;
    cin >> a >> b;
    if(a==0){
      cout<<prefixXor[b];
    }
    cout << (prefixXor[a-1] ^ prefixXor[b]) << endl;
    return 0;
}

// Repeated DNA sequence 
// Number is sparse or not
// xor of a number from l to r

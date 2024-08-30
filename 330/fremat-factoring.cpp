// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef pair<int, int> p32;
// typedef pair<ll, ll> p64;
// typedef pair<double, double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int>> vv32;
// typedef vector<vector<ll>> vv64;
// typedef vector<vector<p64>> vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// const ll MOD = 998244353;
// const double eps = 1e-12;
// #define forn(a, e) for (ll i = a; i < e; i++)
// #define forsn(i, s, e) for (ll i = s; i < e; i++)
// #define rforn(i, s) for (ll i = s; i >= 0; i--)
// #define rforsn(i, s, e) for (ll i = s; i >= e; i--)
// #define ln "\n"
// #define dbg(x) cout << #x << " = " << x << ln
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// const int INTMOD = 1e9 + 7;
// #define fast_cin()                  \
//   ios_base::sync_with_stdio(false); \
//   cin.tie(NULL);                    \
//   cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())
// bool isPerfectSquare(int x) {
//     int s = static_cast<int>(sqrt(x));
//     return s * s == x;
// }

// // Function to find the integer square root of n
// int integerSqrt(int n) {
//     return static_cast<int>(sqrt(n));
// }

// // Fermat's Factorization Method
// v32 fermatFact(int n) {
//     if (n <= 0) {
//         cout << "Invalid input" << endl;
//         return {};
//     }

//     int a = integerSqrt(n);
//     int b2 = a * a - n;

//     while (!isPerfectSquare(b2)) {
//         a++;
//         b2 = a * a - n;
//     }

//     int b = integerSqrt(b2);
//     int factor1 = a - b;
//     int factor2 = a + b;

//     return {factor1, factor2};
// }

// // Simple prime-checking function
// bool isPrime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0) return false;
//     }
//     return true;
// }

// // Function to solve and factorize a number using Fermat's method
// void solve(int tc=0) {
//   int n;
//   cin>>n;
//     if (n <= 1) {
//         cout << "Number must be greater than 1." << endl;
//         return;
//     }

//     v32 factors;
//     while (n > 1) {
//         v32 factorPair = fermatFact(n);
//         if (factorPair.empty()) {
//             cout << "Factorization failed for " << n << endl;
//             return;
//         }

//         for (int factor : factorPair) {
//             if (isPrime(factor)) {
//                 factors.push_back(factor);
//             } else {
//                 // Factor further
//                 solve(factor);
//             }
//         }

//         // Handle case when n is a prime number itself
//         if (isPrime(n)) {
//             factors.push_back(n);
//             break;
//         }
//     }

//     // Output factors
//     sort(factors.begin(), factors.end());
//     for (int factor : factors) {
//         cout << factor << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//   fast_cin();
//   solve();
//   return 0;
// }
#include<bits/stdc++.h>
using namespace std;
    bool isPrime(int n){
        for(int i=2; i<sqrt(n); i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    void factorise(int n){
        int x,y;
        int a = ceil(sqrt(n));
        if(a*a==n){
            cout<<a<<" "<<a;
            return;
        }
        int b;
        while(true){
           int b1 = a*a-n;
            b = int(sqrt(b1));
            if(b*b==b1)
                break;
            else{
                a+=1;
            }
        }
        bool c=isPrime(a+b);
        bool d = isPrime(a-b);
        if(c && d){
            cout<<a+b<<" "<<a-b;
        }
        else if(!c && d ){
            cout<<a-b<<" ";
            factorise(a+b);}
        else if(!d &&c){
            cout<<a+b<<" ";
            factorise(a-b);}
        else{
            factorise(a-b);
            factorise(a+b);
        }
        
    }
    

int main()
{
    int n; 
    cin>>n;
    factorise(n);
    return 0;
}
// #include<bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vll vector<long long int>
// using namespace std;
// int main()
// {
// std::ios::sync_with_stdio(false);
// cin.tie(nullptr);
// int a,b,m;
// cin>>a>>b>>m;
// int calcMod=(a-b+m)%m;
// int calcMod2=(a+b)%m;
// cout<<calcMod<<" "<<calcMod2;
// return 0;
// }

// Iterative C++ program to find modular
// inverse using extended Euclid algorithm

#include <bits/stdc++.h>
using namespace std;

// Returns modulo inverse of a with respect
// to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e.,
// gcd(A, M) = 1
int modInverse(int A, int M)
{
	int m0 = M;
	int y = 0, x = 1;

	if (M == 1)
		return 0;

	while (A > 1) {
		// q is quotient
		int q = A / M;
		int t = M;

		// m is remainder now, process same as
		// Euclid's algo
		M = A % M, A = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}

// Driver Code
int main()
{
	int A = 3, M = 11;

	// Function call
	cout << "Modular multiplicative inverse is "
		<< modInverse(A, M);
	return 0;
}
// this code is contributed by shivanisinghss2110

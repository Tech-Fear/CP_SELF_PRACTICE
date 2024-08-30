#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;

class Solution {
public:
    vector<int> p, rank;
    int numSets;

    // Initialize union-find data structure
    void init(int n) {
        p.resize(n);
        rank.resize(n, 0);
        numSets = n;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    // Find with path compression
    int findSet(int i) {
        if (p[i] != i) {
            p[i] = findSet(p[i]);  // Path compression
        }
        return p[i];
    }

    // Union by rank
    void unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
            numSets--;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        init(n);

        // Union stones that share the same row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unionSet(i, j);
                }
            }
        }

        // Return the number of stones we can remove
        return n - numSets;
    }
};

void solve() {
    int n;
    cin >> n;
    vv32 arr(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    Solution ss;
    cout << ss.removeStones(arr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

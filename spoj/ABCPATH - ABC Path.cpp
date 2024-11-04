#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;

const int dx[8] = {0,0,-1,1,-1,1,1,-1};
const int dy[8] = {1,-1,0,0,1,-1,1,-1};

bool isValid(int i, int j, vs &mat) {
    return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size();
}

int findABC(int i, int j, vs &mat, vector<vector<int>>& dp) {
    if (dp[i][j] != -1) return dp[i][j];

    int maxLength = 1;
    for (int x = 0; x < 8; x++) {
        int ni = i + dx[x];
        int nj = j + dy[x];
        if (isValid(ni, nj, mat) && mat[ni][nj] == mat[i][j] + 1) {
            maxLength = max(maxLength, 1 + findABC(ni, nj, mat, dp));
        }
    }
    return dp[i][j] = maxLength;
}

void solve() {
    int H, W;
    int caseNumber = 1;

    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;

        vs mat(H);
        for (int i = 0; i < H; i++) {
            cin >> mat[i];
        }

        vector<vector<int>> dp(H, vector<int>(W, -1));
        int longestPath = 0;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (mat[i][j] == 'A') {
                    longestPath = max(longestPath, findABC(i, j, mat, dp));
                }
            }
        }
        cout << "Case " << caseNumber++ << ": " << longestPath << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

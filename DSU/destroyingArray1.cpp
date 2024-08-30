#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class UnionFind {
private:
    vi parent, rank, setSize;
    vll sumSet;
    int numSets;

public:
    UnionFind(int N) {
        parent.assign(N, -1);
        rank.assign(N, 0);
        setSize.assign(N, 0);
        sumSet.assign(N, 0);
        numSets = 0;
    }

    void makeSet(int i, int x) {
        parent[i] = i;
        rank[i] = 0;
        setSize[i] = 1;
        sumSet[i] = x;
        numSets += 1;
    }

    int findSet(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findSet(parent[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }

    int numDisjointSets() {
        return numSets;
    }

    ll sumOfSet(int i) {
        return sumSet[findSet(i)];
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j))
            return;

        int x = findSet(i);
        int y = findSet(j);

        if (rank[x] > rank[y])
            swap(x, y);

        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;

        setSize[y] += setSize[x];
        sumSet[y] += sumSet[x];
        numSets--;
    }
};

void solve() {
    int n;
    cin >> n;

    vi arr(n + 1, 0);  // to store the values at each index
    vi sequence(n);    // to store the destruction sequence

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    UnionFind uf(n + 1);
    vi state(n + 1, 0); // Track which indices are currently active
    reverse(sequence.begin(), sequence.end());

    vll answers;
    answers.push_back(0); // The last answer is always zero

    ll currentAns = 0;

    for (int x : sequence) {
        state[x] = 1;
        uf.makeSet(x, arr[x]);

        if (x - 1 > 0 && state[x - 1]) {
            uf.unionSet(x - 1, x);
        }

        if (x + 1 <= n && state[x + 1]) {
            uf.unionSet(x, x + 1);
        }

        currentAns = max(currentAns, uf.sumOfSet(x));
        answers.push_back(currentAns);
    }

    answers.pop_back(); // Remove the last element which is not needed
    reverse(answers.begin(), answers.end());

    for (ll ans : answers) {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

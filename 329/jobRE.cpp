#include <bits/stdc++.h>

using namespace std;

struct task {
    char id;
    int deadline;
    int profits;
};
static bool comp(task &t1, task &t2) {
    return t1.profits > t2.profits; // Sort by profits (high to low)
}
struct CompareProfits {
    bool operator()(const task &t1, const task &t2) {
        return t1.profits < t2.profits; // Max heap based on profits
    }
};

void solve() {  
    vector<task> jobs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        task task1;
        cin >> task1.id >> task1.deadline >> task1.profits;
        jobs.push_back(task1);
    }
    sort(jobs.begin(), jobs.end(), comp);
    
    vector<bool> slot(n, false);
    int maxProfits = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
    //         if (!slot[j]) {
    //             slot[j] = true;
    //             maxProfits += jobs[i].profits;
    //             break;
    //         }
    //     }
    // }
    priority_queue<task, vector<task>, CompareProfits> pq;

    for (int i = 0; i < n; i++) {
        pq.push(jobs[i]);
    }

    // Schedule jobs
    while (!pq.empty()) {
        task currentJob = pq.top();
        pq.pop();
        for (int j = min(n, currentJob.deadline) - 1; j >= 0; j--) {
            if (!slot[j]) { 
                slot[j] = true;
                maxProfits += currentJob.profits;
                break;
            }
        }
    }
    cout << maxProfits << endl;
}

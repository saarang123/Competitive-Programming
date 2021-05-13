#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

/* Note: this function is already implemented for you */
bool query (const vector<int> &A, const vector<int> &B);
bool qry (const vector<int> &A, const vector<int> &B);

/* You can add global variables and functions here */
int itr;
vector<int> start;

int check(vector<int> &q) {
    if(q.size() == 1) 
        return qry(start, q) ? q[0] : -1;
    vector<int> newQ[2];
    for(int i = 0; i < q.size(); i++)
        newQ[i & 1].push_back(q[i]);
    bool b = qry(start, newQ[0]);
    if(b)
        return newQ[0].size() == 1 ? newQ[0][0] : check(newQ[0]);
    return check(newQ[1]);
}

bool solve(int n) {
    // Write your code here, and call query(A, B) from here to solve the problem.
    for(itr = 0; itr < 2; itr++) {
        start = {1};
        vector<bool> used(n + 1);
        used[1] = true;
        for(int i = 1; i < n; i++) {
            vector<int> q;
            for(int i = 1; i <= n; i++) if(!used[i])
                q.push_back(i);
            shuffle(q.begin(), q.end(), rng);
            int x = check(q);
            if(x < 0)
                return 0;
            start.push_back(x);
            used[x] = true;
        }
    }
    return 1;
}

int main() {
    int n;
    cin >> n;

    bool t = solve(n);
    cout << "A" << endl;
    cout << (t ? "YES" : "NO") << endl;
}

bool qry (const vector<int> &A, const vector<int> &B) {
    return itr ? query(B, A) : query(A, B);
}

bool query (const vector<int> &A, const vector<int> &B) {
    cout << "Q\n";
    cout << A.size() << endl;
    for (auto &x : A) {
        cout << x << ' ';
    }
    cout << endl;

    cout << B.size() << endl;
    for (auto &x : B) {
        cout << x << ' ';
    }
    cout << endl;

    int edge;
    cin >> edge;

    if (edge == -1) {
        exit(0);
    }

    return edge;
}
 

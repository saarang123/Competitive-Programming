#include <bits/stdc++.h>
using namespace std;

vector<int> query(vector<int> W);//Do not change this line

// Do NOT read anything from stdin or write something to stdout/stderr
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenPermutation() function.

// If it is impossible to determine the hidden permutation, this function must return {}
vector<int> findHiddenPermutation(int m){
    // your code goes here
    // for example vector<int> mst_edges = query({3, 4, 2, 3, 1});
    vector<bool> found(m);
    int bridges = 0;
    vector<int> cur(m), ans(m, -1);
    iota(cur.begin(), cur.end(), 1);
    vector<int> orig = query(cur);
    vector<int> q = orig;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++)
            cur[j]--;
        cur[i] = m;
        vector<int> newq;
        if(i == m - 1)
            newq = orig;
        else
            newq = query(cur);
        int id = 0;
        vector<int> o(m);
        for(int x : newq)
            o[x]--;
        for(int x : q)
            o[x]++;
        for(int j = 0; j < m; j++) {
            if(o[j] == 1) {
                ans[i] = j;
                found[i] = true;
                id++;
            }
        }
        q = newq;
        if(!id) {
            bridges++;
            if(bridges == 2)
                return {};
        }
    }
    for(int i = 0; i < m; i++) 
        if(ans[i] == -1) 
            for(int j = 0; j < m; j++) 
                if(!found[j]) {
                    ans[i] = j;
                    break;
                }

    return ans;
}
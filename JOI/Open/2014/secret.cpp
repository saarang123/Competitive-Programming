#include "secret.h"
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 1000;
 
int ans[MAX_N][MAX_N], N;
 
void PreCompute(int left, int right) {
    int mid = (left + right) >> 1;
    if(right - left <= 2)
        return;
    for(int i = mid - 2; i >= left; i--) {
        ans[i][mid - 1] = Secret(ans[i][i], ans[i + 1][mid - 1]);
    }
    for(int i = mid + 1; i < right; i++) {
        ans[mid][i] = Secret(ans[mid][i - 1], ans[i][i]);
    }
    PreCompute(left, mid);
    PreCompute(mid, right);
}
 
void Init(int n, int A[]) {
    N = n;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans[i][j] = (i == j) ? A[i] : -1; 
        }
    }
    PreCompute(0, N);
}
 
int Compute(int left, int right, int ql, int qr) {
    int mid = (left + right) >> 1;
    if(ql >= mid) {
        return Compute(mid, right, ql, qr);
    }
    else if(qr < mid) {
        return Compute(left, mid, ql, qr);
    }
    return Secret(ans[ql][mid - 1], ans[mid][qr]);
}
 
int Query(int L, int R) {
    if(L == R)
        return ans[L][L];
    if(L == R - 1)
        return Secret(ans[L][L], ans[R][R]);
    return Compute(0, N, L, R);
}

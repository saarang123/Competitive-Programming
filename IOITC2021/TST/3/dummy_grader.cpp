#include <bits/stdc++.h>
using namespace std;

namespace{
    int N;
    const int QMAX = 120;
    int a, b, asked;
}

pair<int, int> findHiddenCell(int N);

bool doesPathExist(const vector<string> & M){
    if(asked == QMAX){
        cerr << "Asked too many queries" << endl;
        exit(0);
    }
    if((int)M.size() != N){
        cerr << "Invalid query" << endl;
        exit(0);
    }
    for(int i = 0; i < N; i++){
        if((int)M[i].length() != N){
            cerr << "Invalid query" << endl;
            exit(0);
        }
        for(int j = 0; j < N; j++){
            if(M[i][j] != '0' && M[i][j] != '1'){
                cerr << "Non 0-1 character in M" << endl;
                cout << 0 << endl;
                exit(0);
            }
        }
    }
    asked++;
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    dp[0][0] = M[0][0] == '1';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(i + j && (M[i][j] == '1' || (i == a && j == b))){
            if(i && dp[i - 1][j]) dp[i][j] = true;
            if(j && dp[i][j - 1]) dp[i][j] = true;
        }
    }
    cout << "Query for: " << '\n';
    for(int i = 0; i < N; i++)
        cout << M[i] << '\n';
    cout << '\n';
    cout << "Returned: " << dp[N - 1][N - 1] << endl;
    return dp[N - 1][N - 1];
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> N;
        asked = 0;
        cin >> a >> b;
        pair<int, int> P = findHiddenCell(N);
        
        if(P != make_pair(a, b)){
            cerr << "Incorrect output!" << endl;
            cerr << "Expected: " << "(" <<a<<", " << b << ")" << endl;
            cerr << "Got: " << "(" <<P.first<<", " << P.second << ")" << endl;
            exit(0);
        }
        cerr << "Correct output!" << endl;
        cerr << "Queries asked = " << asked << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;
void chmax(int& a, int b){ if(a < b) a = b; }

int main(){
    int N;
    cin >> N;
    vector dp(4, vector(1 << 5, 0));
    dp[0][0] = 0x3fffffff;
    while(N--){
        auto dp2 = dp;
        for(int x = 0; x < 5; x++){
            int A;
            cin >> A;
            for(int j = 0; j < 3; j++) for(int k = 0; k < 1 << 5; k++){
                if(k & 1 << x) chmax(dp2[j][k], min(dp2[j][k ^ 1 << x], A));
            }
        }
        for(int j = 0; j < 3; j++) for(int k = 0; k < 1 << 5; k++){
            chmax(dp[j + 1][k], dp2[j][k]);
        }
    }
    cout << dp.back().back() << endl;
}

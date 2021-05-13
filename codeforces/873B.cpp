#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int maxlen(int arr[], int n)
{
    unordered_map<int, int> presum;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (arr[i] == 0 && max_len == 0)
            max_len = 1;
        if (sum == 0)
            max_len = i + 1;
        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            presum[sum] = i;
        }
    }
    return max_len;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    string s;
    cin >> n >> s;
    int a[n];
    for(i=0; i<n; i++)
    {
        if(s[i]=='1')
            a[i] = 1;
        else
            a[i] = -1;
    }
    cout << maxlen(a, n) << "\n";
    return 0;
}

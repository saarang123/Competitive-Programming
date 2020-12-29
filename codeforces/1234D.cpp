#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,j;
    string s;
    vector<set<int>> v(26);
    cin >> s;
    for(j=0; j<s.size(); j++)
    {
        v[s[j]-'a'].insert(j);
    }
    int q;
    cin >> q;
    for(int k=0; k<q; k++)
    {
        cin >> i;
        if(i==1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            v[s[pos]-'a'].erase(pos);
            s[pos] = c;
            v[s[pos]-'a'].insert(pos);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--,r--;
            int cnt = 0;
            for(j=0; j<26; j++)
            {
                auto it = v[j].lower_bound(l);
                if(*it<=r && it!=v[j].end())
                {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
	return 0;
}
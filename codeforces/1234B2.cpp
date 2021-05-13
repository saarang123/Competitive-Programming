#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j,n, k;
    cin >>n >> k;
    int id[n+1];
    for(i=1; i<=n; i++)
        cin >> id[i];
    set<int> s;
    queue<int> q;
    for(i=1; i<=n; i++)
    {
        if(!s.count(id[i]))
        {
            if(q.size()==k)
            {
                int cur = q.front();
                q.pop();
                s.erase(cur);
            }
            q.push(id[i]);
            s.insert(id[i]);
        }
    }
    vector<int> v;
    while(!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto it : v)
        cout << it << " ";
    cout << "\n";
	return 0;
}
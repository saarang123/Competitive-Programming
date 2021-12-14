#include <bits/stdc++.h>
using namespace std;
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> ret(512, 1000);
    ret[0] = -1;
 
    for(int e: a){
    	for(int j = 0; j < 512; ++j){
    		if (ret[j] < e){
    			ret[j ^ e] = min(ret[j ^ e], e);
    		}
    	}
    }
 
    vector<int> final;
    for(int i = 0; i < 512; ++i){
    	if (ret[i] < 1000){
    		final.push_back(i);
    	}
    }
    cout << final.size() << endl;
    for(int e: final){
    	cout << e << " ";
    } 
    cout << '\n';
    return 0;
}
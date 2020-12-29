#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    
	int b1,b2,s1,s2,g1,g2,p1,p2, pro1, pro2, pro3;
	fin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
	pro3 = p2-p1;
	g2+=pro3;
	pro2 = g2-g1;
	s2+=pro2;
	pro1 = s2-s1;
	fout << pro1 << "\n";
	fout << pro2 << "\n";
	fout << pro3 << "\n";
	return 0;
}
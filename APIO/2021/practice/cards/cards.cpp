#include "cards.h"
#include <bits/stdc++.h>
using namespace std;

int n, k;
map<vector<int>, int> ans;

void init_magician(int N, int K) {
	n = N, k = K;
}

void init_assistant(int N, int K) {
	n = N, k = K;
}

std::vector<int> choose_cards(std::vector<int> cards) {
	int x = cards.back();
	cards.pop_back();
	ans[cards] = x;
	return cards;
}

int find_discarded_card(std::vector<int> cards) {
	return ans[cards];
}

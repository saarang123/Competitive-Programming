#include "cards.h"

#include <cassert>
#include <cstdio>

#include <algorithm>
#include <vector>

int main() {
  int N, K, Q;
  assert(scanf("%d %d %d", &N, &K, &Q) == 3);
  
  init_assistant(N, K);
  init_magician(N, K);

  for (int i = 0; i < Q; ++i) {
    std::vector<int> cards(K);
    for (int j = 0; j < K; ++j) {
      assert(scanf("%d", &cards[j]) == 1);
    }

    std::vector<int> chosen_cards = choose_cards(cards);

    if (static_cast<int>(chosen_cards.size()) != K - 1) {
      printf("Wrong Answer: invalid number of chosen cards\n");
      continue;
    }
    std::vector<bool> cards_chosen(K, false);
    bool wrong_chosen_cards = false;
    for (int card : chosen_cards) {
      int card_idx = std::lower_bound(cards.begin(), cards.end(), card) -
                     cards.begin();
      if (card_idx >= K || cards[card_idx] != card) {
        printf("Wrong Answer: invalid chosen card number\n");
        wrong_chosen_cards = true;
        break;
      }
      if (cards_chosen[card_idx]) {
        printf("Wrong Answer: duplicated chosen cards\n");
        wrong_chosen_cards = true;
        break;
      }
      cards_chosen[card_idx] = true;
    }

    if (!wrong_chosen_cards) {
      int discarded_card = find_discarded_card(chosen_cards);
      int card_idx = std::lower_bound(cards.begin(), cards.end(),
                                      discarded_card) - cards.begin();
      if (card_idx >= K || cards[card_idx] != discarded_card ||
          cards_chosen[card_idx]) {
        printf("Wrong Answer: wrong discarded card\n");
        continue;
      }

      printf("Accepted: chosen_cards = [");
      for (int j = 0; j < K - 1; ++j) {
        printf("%d", chosen_cards[j]);
        if (j == K - 2) {
          printf("]; ");
        } else {
          printf(", ");
        }
      }
      printf("discarded_card = %d\n", discarded_card);
    }
  }
  return 0;
}

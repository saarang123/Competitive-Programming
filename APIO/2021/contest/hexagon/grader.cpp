#include "hexagon.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N, A, B;
  assert(3 == scanf("%d %d %d", &N, &A, &B));
  std::vector<int> D(N), L(N);
  for (int i = 0; i < N; ++i) {
    assert(2 == scanf("%d %d", &D[i], &L[i]));
  }

  int result = draw_territory(N, A, B, D, L);
  printf("%d\n", result);
  return 0;
}

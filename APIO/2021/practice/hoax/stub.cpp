#include "hoax.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N, S, Q;
  assert(3 == scanf("%d %d %d", &N, &S, &Q));
  std::vector<int> T(N);
  std::vector<std::vector<int>> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &T[i]));
    A[i].resize(T[i]);
    B[i].resize(T[i]);
    for (int j = 0; j < T[i]; ++j) {
      assert(2 == scanf("%d %d", &A[i][j], &B[i][j]));
    }
  }
  init(N, S, T, A, B);

  for (int i = 0; i < Q; ++i) {
    int P;
    assert(1 == scanf("%d", &P));
    printf("%d\n", count_users(P));
  }
  return 0;
}

#include "aplusb.h"

#include <cassert>
#include <cstdio>

int main() {
  int A, B;
  assert(2 == scanf("%d %d", &A, &B));

  int result = add_two_numbers(A, B);
  printf("%d\n", result);
  return 0;
}

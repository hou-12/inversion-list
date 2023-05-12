#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "inversion-list/inversion-list.h"
#include "inversion-list/inversion-list.inc"


int main(void) {
  InversionList set;
  assert(sizeof set == 2 * sizeof(unsigned int) + sizeof(size_t));  // NOLINT(build/include)
  assert((void *)&set.capacity == (void *)&set);  // NOLINT(build/include)
  assert((void *)&set.support == (void *)&set + sizeof(unsigned int));  // NOLINT(build/include)
  assert((void *)&set.size == (void *)&set + 2 * sizeof(unsigned int));  // NOLINT(build/include)
  assert((void *)set.couples == (void *)&set + 2 * sizeof(unsigned int) + sizeof(size_t));  // NOLINT(build/include)
  assert((void *)&set.couples[0] == (void *)&set + 2 * sizeof(unsigned int) + sizeof(size_t));  // NOLINT(build/include)
  assert((void *)&set.couples[1] == (void *)&set + 2 * sizeof(unsigned int) + sizeof(size_t) + sizeof(unsigned int));  // NOLINT(build/include)
  return EXIT_SUCCESS;
}

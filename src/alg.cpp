// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 0;
  while (num > 1) {
    if (num % 2 == 0) num /= 2;
    else num = 3 * num + 1;
    if (max < num) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num > 1) {
    if (num % 2 == 0) num /= 2;
    else num = 3 * num + 1;
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 0;
  uint64_t num = 0;
  for (uint64_t i = 2; i < 2000000; i++) {
    uint64_t counter = 1, n = i;
    while (n > 1) {
      if (n % 2 == 0) n /= 2;
      else n = 3 * n + 1;
      counter++;
    }
    if (*maxlen < counter && i <= rbound && i >= lbound) {
      num = i;
      *maxlen = counter;
    }
  }
  return num;
}

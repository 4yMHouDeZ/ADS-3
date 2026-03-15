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
  uint64_t num, n;
  for (uint64_t i = 2; i < 1000000; i++) {
    n = i;
    uint64_t counter = 1;
    while (n > 1) {
      if (n % 2 == 0) n = n / 2;
      else n = 3 * n + 1;
      counter++;
    }
    if (*maxlen < counter && counter <= rbound && counter >= lbound) {
      num = i;
      *maxlen = counter;
    }
  }
  return num;
}

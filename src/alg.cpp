// Copyright 2025 UNN-CS
#include "alg.h"
#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value < 2)
    return false;
  if (value == 2)
    return true;
  if (value % 2 == 0)
    return false;

  uint64_t max_div = static_cast<uint64_t>(sqrt(value));
  for (uint64_t i = 3; i <= max_div; i += 2) {
    if (value % i == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0)
    return 0;

  uint64_t found = 0;
  uint64_t current = 1;

  while (found < n) {
    current++;
    if (checkPrime(current)) {
      found++;
    }
  }
  return current;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
  while (!checkPrime(candidate)) {
    candidate++;
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t total_sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      total_sum += i;
    }
  }
  return total_sum;
}

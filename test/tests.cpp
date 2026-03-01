// Copyright 2025 UNN-CS

#include <cstdint>
#include <gtest/gtest.h>
#include "alg.h"

TEST(PrimeValidation, SmallValues) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
}

TEST(PrimeValidation, EvenNumbers) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(100));
  EXPECT_FALSE(checkPrime(10002));
}

TEST(PrimeValidation, CompositeOdd) {
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(121));
}

TEST(PrimeValidation, LargePrimes) {
  EXPECT_TRUE(checkPrime(7919));
  EXPECT_TRUE(checkPrime(104729));
}

TEST(NthPrimeSearch, EarlySequence) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
}

TEST(NthPrimeSearch, DeepSequence) {
  EXPECT_EQ(nPrime(50), 229);
  EXPECT_EQ(nPrime(100), 541);
}

TEST(NthPrimeSearch, InvalidInput) { EXPECT_EQ(nPrime(0), 0); }

TEST(NextPrimeFinder, TwinPrimes) {
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(11), 13);
  EXPECT_EQ(nextPrime(17), 19);
}

TEST(NextPrimeFinder, LargeGap) {
  EXPECT_EQ(nextPrime(113), 127);
  EXPECT_EQ(nextPrime(89), 97);
}

TEST(NextPrimeFinder, StartingFromZero) {
  EXPECT_EQ(nextPrime(0), 2);
  EXPECT_EQ(nextPrime(1), 2);
}

TEST(SummationLogic, SmallRange) {
  EXPECT_EQ(sumPrime(6), 10);
  EXPECT_EQ(sumPrime(7), 10);
}

TEST(SummationLogic, MediumRange) { EXPECT_EQ(sumPrime(100), 1060); }
TEST(Performance, HighBoundarySum) {
  uint64_t result = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(result, expected);
}

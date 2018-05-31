#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "16.cpp"
#include "ctime"

using namespace std;

TEST_CASE("shell"){
  int n = 7;
  int *a = new int[n];
  a[0] = -2;
  a[1] = 3;
  a[2] = -8;
  a[3] = -12;
  a[4] = 8;
  a[5] = 5;
  a[6] = -6;

  int *b = exclude_s(a, n);
  CHECK(b[0] == 3);
  CHECK(b[1] == 5);
  CHECK(b[2] == 8);
}

TEST_CASE("quick"){
  int n = 7;
  int *a = new int[n];
  a[0] = -2;
  a[1] = 3;
  a[2] = -8;
  a[3] = -12;
  a[4] = 8;
  a[5] = 5;
  a[6] = -6;

  int *b = exclude_q(a, n);
  CHECK(b[0] == 3);
  CHECK(b[1] == 5);
  CHECK(b[2] == 8);
}

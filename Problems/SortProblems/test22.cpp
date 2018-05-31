#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "22.cpp"
#include "14.cpp"
#include "ctime"

using namespace std;

TEST_CASE("22") {
  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  shell(a, n);
  int *b = problem22(a, n);

  for(int i = 0; i < 2*n - 1; i++){
    CHECK(b[i] <= b[i+1]);
  }
}

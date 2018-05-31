#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "17.cpp"
#include "ctime"

using namespace std;

TEST_CASE("a to b"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  int *b = transform(a, n);

  for(int i = 0; i < n; i++){
    CHECK(b[i] <= b[i+1]);
  }
}

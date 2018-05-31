#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "21.cpp"
#include "ctime"

using namespace std;

TEST_CASE("sort"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  abs_sort(a, n);

  for(int i = 0; i < n - 1; i++){
    CHECK(abs(a[i]) <= abs(a[i+1]));
  }
}

TEST_CASE("decrease sort"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  abs_decrease_sort(a, n);

  for(int i = 0; i < n - 1; i++){
    CHECK(abs(a[i]) >= abs(a[i+1]));
  }
}

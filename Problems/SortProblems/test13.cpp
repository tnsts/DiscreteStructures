#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "13.cpp"
#include "ctime"

using namespace std;

TEST_CASE("shell"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  shell_decrease(a, n);

  for(int i = 0; i < n - 1; i++){
    CHECK(a[i] >= a[i+1]);
  }
}

TEST_CASE("quick"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  quick_decrease(a, 0, n-1);

  for(int i = 0; i < n - 1; i++){
    CHECK(a[i] >= a[i+1]);
  }
}

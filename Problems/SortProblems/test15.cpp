#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "15.cpp"
#include "ctime"

using namespace std;

TEST_CASE("shell"){
  srand(time(0));

  int n = 10;
  int te = rand()%50-25;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = te + i;
  }

  s_transform(a, n);

  for(int i = 0; i < n - 1; i++){
    CHECK(a[i] >= a[i+1]);
  }
}

TEST_CASE("quick"){
  srand(time(0));

  int n = 10;
  int te = rand()%50-25;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = te + i;
  }

  q_transform(a, n);

  for(int i = 0; i < n - 1; i++){
    CHECK(a[i] >= a[i+1]);
  }
}

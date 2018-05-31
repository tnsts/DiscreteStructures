#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "14.cpp"
#include "ctime"

using namespace std;

TEST_CASE("shell"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  int *b = insert_s(a, n, rand()%50-25);

  for(int i = 0; i < n; i++){
    CHECK(b[i] <= b[i+1]);
  }
}

TEST_CASE("quick"){
  srand(time(0));

  int n = 10;
  int *a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = rand()%50-25;
  }

  int *b = insert_q(a, n, rand()%50-25);

  for(int i = 0; i < n; i++){
    CHECK(b[i] <= b[i+1]);
  }
}

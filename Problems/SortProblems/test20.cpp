#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "20.cpp"
#include "ctime"

using namespace std;

TEST_CASE("Problem_20") {
  vector <string> a;
  a.push_back("Smith");
  a.push_back("Vonnegut");
  a.push_back("Orwell");
  a.push_back("Bradbury");
  a.push_back("Solo");
  a.push_back("Skywalker");

  vector <string> b = length_sort(a);
  CHECK(b[0] == "Solo");
  CHECK(b[1] == "Smith");
  CHECK(b[2] == "Orwell");
  CHECK(b[3] == "Vonnegut");
  CHECK(b[4] == "Bradbury");
  CHECK(b[5] == "Skywalker");
}

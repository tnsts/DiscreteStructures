#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "18.cpp"
#include "ctime"

using namespace std;

TEST_CASE("Surname sorting") {
  vector <string> a;
  a.push_back("Smith");
  a.push_back("Vonnegut");
  a.push_back("Orwell");
  a.push_back("Bradbury");
  a.push_back("Solo");
  a.push_back("Skywalker");

  vector <string> b = surname_sort(a);
  CHECK(b[0] == "Bradbury");
  CHECK(b[1] == "Orwell");
  CHECK(b[2] == "Skywalker");
  CHECK(b[3] == "Smith");
  CHECK(b[4] == "Solo");
  CHECK(b[5] == "Vonnegut");
}

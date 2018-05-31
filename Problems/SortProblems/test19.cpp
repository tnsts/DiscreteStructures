#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "19.cpp"
#include "ctime"

using namespace std;

TEST_CASE("Problem_19") {
  Subscriber sub1;
  sub1.number = 9240067;
  sub1.surname = "Potter";
  Subscriber sub2;
  sub2.number = 9145609;
  sub2.surname = "Granger";
  Subscriber sub3;
  sub3.number = 9146895;
  sub3.surname = "Weasley";
  Subscriber sub4;
  sub4.number = 9040052;
  sub4.surname = "Longbottom";

  vector <Subscriber> a;
  a.push_back(sub1);
  a.push_back(sub2);
  a.push_back(sub3);
  a.push_back(sub4);

  vector <Subscriber> b = telephone_number_sort(a);
  CHECK(b[0].surname == "Longbottom");
  CHECK(b[1].surname == "Granger");
  CHECK(b[2].surname == "Weasley");
  CHECK(b[3].surname == "Potter");
}

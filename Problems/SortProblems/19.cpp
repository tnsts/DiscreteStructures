#include <iostream>
#include <string>
using namespace std;

struct Subscriber {
  int number;
  string surname;
};

vector<Subscriber> telephone_number_sort(vector<Subscriber> a) {
  int size = a.size();
  int d = size/2;
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && a[j].number > a[j + d].number; j--) {
        Subscriber temp = a[j];
        a[j] = a[j + d];
        a[j + d] = temp;
      }
    }
    d = d/2;
  }
  return a;
}

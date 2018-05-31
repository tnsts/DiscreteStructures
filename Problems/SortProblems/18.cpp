#include <iostream>
#include <string>
using namespace std;

vector<string> surname_sort(vector<string> a) {
  int size = a.size();
  vector<string> res = a;
  int d = size/2;
  while (d >= 1) {
    for (int i = 0; i < size - d; i++) {
      for (int j = i; j >= 0 && res[j].compare(res[j + d]) > 0; j--) {
        string temp = res[j];
        res[j] = res[j + d];
        res[j + d] = temp;
      }
    }
    d = d/2;
  }
  return res;
}

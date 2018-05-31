#include <iostream>
using namespace std;

int *transform(int *arr, int n){
  int *res = new int [n];
  for (int i = 1; i < n; i++) {
    int temp = res[i];
    int index = i - 1;
    while (index >= 0 && res[index] > temp) {
      res[index + 1] = res[index];
      res[index] = temp;
      index--;
    }
  }
  return res;
}

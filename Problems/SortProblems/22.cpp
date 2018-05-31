#include <iostream>
#include <cmath>
using namespace std;

int *problem22(int *arr, int n) {
  int *res = new int[n*2-1];
  int counter = 0;
  for(int i = 0; i < n; i++) {
    res[counter++] = arr[i];

    if (arr[i] + 1 < arr[i+1]) {
      res[counter++] = arr[i] + 1;
    } else {
      res[counter++] = arr[i];
    }
  }
  return res;
}

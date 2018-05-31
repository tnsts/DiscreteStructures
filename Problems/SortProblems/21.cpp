#include <iostream>
#include <cmath>
using namespace std;

void abs_sort(int *arr, int n) {
  int d = n/2;
  while (d >= 1) {
    for (int i = 0; i < n - d; i++) {
      for (int j = i; j >= 0 && abs(arr[j]) > abs(arr[j+d]); j--) {
        int temp = arr[j];
        arr[j] = arr[j+d];
        arr[j+d] = temp;
      }
    }
    d = d/2;
  }
}

void abs_decrease_sort(int *arr, int n) {
  int d = n/2;
  while (d >= 1) {
    for (int i = 0; i < n - d; i++) {
      for (int j = i; j >= 0 && abs(arr[j]) < abs(arr[j+d]); j--) {
        int temp = arr[j];
        arr[j] = arr[j+d];
        arr[j+d] = temp;
      }
    }
    d = d/2;
  }
}

#include <iostream>
using namespace std;

void shell_decrease(int *arr, int n) {
  int d = n/2;
  while (d >= 1) {
    for (int i = 0; i < n - d; i++) {
      for (int j = i; j >= 0 && arr[j] < arr[j+d]; j--) {
        int temp = arr[j];
        arr[j] = arr[j+d];
        arr[j+d] = temp;
      }
    }
    d = d/2;
  }
}

void quick_decrease(int *arr, int left, int right) {
  int i = left, j = right;
  int temp;
  int mid = arr[(left+right)/2];
  while (i <= j) {
    while (arr[i] > mid) i++;
    while (arr[j] < mid) j--;
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  };
  if (left < j) quick_decrease(arr, left, j);
  if (i < right) quick_decrease(arr, i, right);
}

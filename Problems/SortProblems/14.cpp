#include <iostream>
using namespace std;

void shell(int *arr, int n) {
  int d = n/2;
  while (d >= 1) {
    for (int i = 0; i < n - d; i++) {
      for (int j = i; j >= 0 && arr[j] > arr[j+d]; j--) {
        int temp = arr[j];
        arr[j] = arr[j+d];
        arr[j+d] = temp;
      }
    }
    d = d/2;
  }
}

void quick(int *arr, int left, int right) {
  int i = left, j = right;
  int temp;
  int mid = arr[(left+right)/2];
  while (i <= j) {
    while (arr[i] < mid) i++;
    while (arr[j] > mid) j--;
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  };
  if (left < j) quick(arr, left, j);
  if (i < right) quick(arr, i, right);
}

int *insert_s(int *arr, int n, int in_data){
  int *res = new int[n+1];
  for (int i = 0; i < n; i++) {
    res[i] = arr[i];
  }
  res[n] = in_data;
  shell(res, n+1);
  return res;
}

int *insert_q(int *arr, int n, int in_data){
  int *res = new int[n+1];
  for (int i = 0; i < n; i++) {
    res[i] = arr[i];
  }
  res[n] = in_data;
  quick(res, 0, n);
  return res;
}

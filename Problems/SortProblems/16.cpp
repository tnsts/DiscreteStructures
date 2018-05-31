#include <iostream>
#include "14.cpp"
using namespace std;

int *exclude_s(int *arr, int n){
  int *temp = new int[n];
  int counter = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      temp[counter] = arr[i];
      counter++;
    }
  }
  int *res = new int[counter];
  for(int i = 0; i < counter; i++){
    res[i] = temp[i];
  }
  delete [] temp;

  shell(res, counter);
  return res;
}

int *exclude_q(int *arr, int n){
  int *temp = new int[n];
  int counter = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      temp[counter] = arr[i];
      counter++;
    }
  }
  int *res = new int[counter];
  for(int i = 0; i < counter; i++){
    res[i] = temp[i];
  }
  delete [] temp;

  quick(res, 0, counter-1);
  return res;
}

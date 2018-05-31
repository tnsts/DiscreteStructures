#include <iostream>
#include "13.cpp"
using namespace std;

void s_transform(int *arr, int n){
  shell_decrease(arr, n);
}

void q_transform(int *arr, int n){
  quick_decrease(arr, 0, n-1);
}

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


int* addTwo(int* arr0, int len0, int* arr1, int len1) {
  int len = len0;
  int len_smaller = len1;
  int* arr_l = arr0;
  int* arr_s = arr1;
  if (len0 < len1) {
    len = len1;
    arr_l = arr1;
    arr_s = arr0; 
    len_smaller = len0; 
  }
  
  int carry = 0;
  int* sum = (int*) malloc(sizeof(int) * 100);
  memset(sum, -1, 100 * sizeof(int));
  int place = 0;
  for (int i = 0; i < len + place; i++) {
    if (i >= len) {
      sum[i] = carry;
      continue;
    }

    if (i >= len_smaller) {
      sum[i] = arr_l[i] + carry;
    } else {
      sum[i] = arr_l[i] + arr_s[i] + carry;
    }

    if (sum[i] < 10) {
      carry = 0;
      continue;
    } 
        
    carry = 1; 
    sum[i] = sum[i] - 10;

    if (i == len - 1) {
      place++;
    }
  }
  
  return sum; 
}


int main() {
  return 0;
}


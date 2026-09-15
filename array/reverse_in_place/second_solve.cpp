#include <cstdio>

void reverse(int x[], int len) {
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int y = x[left];
    x[left] = x[right];
    x[right] = y;
    left++;
    right--;
  }
}

int main() {
  int x[] = {1,2,3,4,5,6,7,8,9,10};
  int len = sizeof(x) / sizeof(x[0]);
  reverse(x,len);
  for(int i = 0; i < len; i++ ) { printf("%d - ", x[i]); }
}

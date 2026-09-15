#include <cstddef>
#include <cstdio>


// reverse array in place
// pattern used: two pointers - converging  

void reverse(int arr[], int len) {
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
    left++;
    right--;
  }
}

int main() {
  int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = sizeof(x) / sizeof(x[0]);
  reverse(x,len);
  for (size_t i = 0; i < len; ++i) { printf("%d - ", x[i]); }  
  return 0;
}

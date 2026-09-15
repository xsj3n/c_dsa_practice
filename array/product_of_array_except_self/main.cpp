#include <cstdio>
#include <cstdlib>
#include <cstring>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int sz = numsSize * sizeof(int);
  int* values  = (int*)malloc(sz);
  int* prefixs = (int*)malloc(sz);
  int* suffixs = (int*)malloc(sz);
  int ilen = numsSize - 1;

  prefixs[0] = nums[0];
  for(int i = 1; i < numsSize; i++)
     prefixs[i] = nums[i] * prefixs[i - 1];
  

  suffixs[ilen] = nums[ilen];
  for(int i = ilen - 1; i >= 0; i--)
    suffixs[i] = nums[i] * suffixs[i + 1];

  values[0] = suffixs[1]; 
  values[ilen] = prefixs[ilen - 1];
  for(int i = 1; i < numsSize - 1; i++)
    values[i] = prefixs[i - 1] * suffixs[i + 1];

  free(prefixs);
  free(suffixs);
  return values;
}

int main() {
  int x[] = {1,2,3,4};
  int len = sizeof(x)/sizeof(x[0]);
  int returnSize = 0;
  int* values = productExceptSelf(x, len, &returnSize);
  for(int i = 0; i < returnSize; i++) printf("%d ", values[i]);
  free(values);
}

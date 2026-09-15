
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bucket(int* target, int* num) {  
    if (*num < *target / 4)
      return 0;
    else if (*num < *target / 2)
      return 1;
    else if (*num < *target)
      return 2;
    else if (*num > *target)
      return 3;
    else if (*num > *target * 2)
      return 4;
    else
      return 5;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* answers = malloc(8);
  *returnSize = 2;
  int bucket_size = sizeof(int) * numsSize;
  int (*buckets)[bucket_size] = malloc(sizeof(*buckets) * 6);
  memset(buckets, -1, sizeof(*buckets) * 6); 
  memset(answers, 0, 8);
  for(int i = 0; i < numsSize; i++) {
    int bucket = get_bucket(&target, &nums[i]);
    printf("placing %d in bucket %d\n", nums[i], bucket); 
    for(int j = 0; j < numsSize; j++) {
      if (buckets[bucket][j] == -1) {
        buckets[bucket][j] = i;
        break;
      }
    } 
  }

  for(int i = 0; i < numsSize; i++) {
    int addend = target - nums[i];
    printf("%d needs %d, searching...\n", nums[i], target - nums[i]);
    int bucket = get_bucket(&target, &addend);
    
    printf("searching bucket %d for %d\n", bucket, addend);
    for(int j = 0; j < numsSize; j++) {
      if (buckets[bucket][j] == -1) break;
      if (i == buckets[bucket][j]) continue;
      if (nums[buckets[bucket][j]] == addend) {
        printf("found addend %d at index %d\n", addend, buckets[bucket][j]);
        answers[0] = i;
        answers[1] = buckets[bucket][j];
        goto fin;
      }   
    }
  }
  
fin:
  free(buckets);
  return answers;  
}

int main() {
  int x[] = {2,5,5,11};
  int len = sizeof(x) / sizeof(x[0]);
  int* returnSize;
  *returnSize = 0;
  int* values = twoSum(x, len, 10, returnSize);
  printf("%d, %d", values[0], values[1]);
  free(values);
  return 0;
}

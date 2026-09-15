#include <cstdio>

void moveZeroes(int* nums, int len) {
  if (len == 0 || len == 1)
    return;
  
  int* fst = nums;
  int* snd = nums + 1;

  while (true) {
  for(int i = 0; i < len; i++) { printf("%d ", nums[i]); if (i == len - 1) printf("\n"); } 
    if (snd > &nums[len - 1])
      return;

    if (*fst) {
      fst++;
      snd++;
      continue;
    }

    if (!*snd) {
      snd++;
      continue;
    }

    *fst = *snd;
    *snd = 0;
    fst++;
    snd++;
  }   
}

int main() {
  int x[] = {1,0,1};
  int y[] = {1,0,2,0,3,4};
  int z[] = {0,0,0,1,0,2,3,4};
  int len = sizeof(z) / sizeof(z[0]);
  moveZeroes(z, len);
  for(int i = 0; i < len; i++) printf("%d ", z[i]);
  return 0;
}


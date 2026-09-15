#include <cstdio>
int removeDuplicates(int* x, int len) {
  if (len == 1 || len == 0)
    return len; 

  int* fst = x; 
  int* snd = x + 1;
  while(true) {
    if (snd > &x[len - 1])
      return (int)(fst - x) + 1;
        
    if (*fst >= *snd) {
      snd++;
      continue;
    }

    fst++;
    *fst = *snd;
    snd++;
  } 
}


int main() {
  int x[] = {1,1,1,1,1,2,2,2,3,3,4,4,5,6,9,9,10,10,10,11111};
  //intx[]= {1,2,1,1,1,9,2,2,3,3,4,4,5,6,9,9,10};
  // ----------x-------y-------------------------
  //int x[] = {2,2};
  int len = sizeof(x) / sizeof(x[0]); 
  printf("%d found\n", removeDuplicates(x, len));
  for(int i = 0; i < len; i++) printf("%d ", x[i]);
}



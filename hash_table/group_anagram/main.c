#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
  int iv;
  unsigned int offset;
  unsigned int row;
};

int h(int x, int sz) {
  if (x < 0) x *= -1;
  double p = x * 0.6180339887;
  double f = p - floor(p);
  return (int)sz * f;
}

char*** groupAnagrams(char** strs, int len, int* rsz, int** rcz) {
  char*** values = malloc(len * sizeof(char*));
  *rcz = malloc(len * sizeof(int));
  struct Node nodes[len];
  int lengths[len]; 
  memset(&nodes, 0, len * sizeof(struct Node));
  memset(values, 0, len * sizeof(char*));
  memset(*rcz,   0, len * sizeof(int));
  *rsz = 0;

  int total_sz = 0;
  for(int i = 0; i < len; i++) {
    lengths[i] = sizeof(strs[i]);
    total_sz += lengths[i];
  }
  for(int i = 0; i < len; i++) {
    values[i] = malloc(len * sizeof(char*));
    char* p = malloc(total_sz);
    for(int j = 0; j < len; j++) values[i][j] = p;
    memset(p, 0, total_sz);
  }

  for(int i = 0; i < len; i++) {
    int iv = 0;
    for(char* s = strs[i]; *s != '\0'; s++) iv += *s;
    int k = h(iv, len) % len;

    if (!nodes[k].offset) {
empty:
      printf("New bucket [%d]: placed at bucket offset 0: %s\n", *rsz, strs[i]);
      strcpy(values[*rsz][0], strs[i]);
      nodes[k].iv = iv;
      nodes[k].offset += lengths[i];
      nodes[k].row = *rsz;
      (*rcz)[k]++;
      (*rsz)++;
      continue;
    }
    
    if (nodes[k].iv == iv) {
iv_match:
      printf("Adding '%s' to bucket %d\n", strs[i],k);
      char** p = &values[nodes[k].row][(*rcz)[k]];
      *p += nodes[k].offset;  
      strcpy(*p, strs[i]);
      nodes[k].offset += lengths[i];
      (*rcz)[k]++;
      continue;
    }

    printf("Key %d for '%s' occupied. Trying", k, strs[i]);
    for(k = (k + 1) % len; k < len ;k = (k + 1) % len) {
      printf(" %d ...", k);
      if (nodes[k].iv == iv) {
        printf("matched!\n");
        goto iv_match;
      }
      if (!nodes[k].offset)  {
        printf("empty! placing new bucket\n");
        goto empty;
      }
    }
    
    
  }
  



  return values;
}

int main() {
  int r = 0;
  char* x[] = {"eat","tea","tan","ate","nat","bat"};
  int len = sizeof(x) / sizeof(x[0]);
  int* csz = NULL; 
  
  char*** answer = groupAnagrams(x, len, &r, &csz);
  for(int i = 0; i < len; i++) {
    if (answer[i] == NULL) continue;
    printf("[");
    for(int j = 0; j < csz[i]; j++) {
      if (answer[i][j] == NULL) {
        free(answer[i][0]);
        break; 
      }
      printf("%s,", answer[i][j]); 
    }
    printf("]\n");
    free(answer[i]);
  }
  free(answer);
  return 0;
}

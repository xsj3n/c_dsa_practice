#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
  int iv;
  unsigned int offset;
  unsigned int row;
  char* start; 
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
    lengths[i] = strlen(strs[i]) + 1;
    total_sz += lengths[i];
  }
  for(int i = 0; i < len; i++) {
    values[i] = malloc(len * sizeof(char*));
    char* p = malloc(total_sz);
    memset(values[i], 0, len * sizeof(char*));
    memset(p, 0, total_sz);
  }

  for(int i = 0; i < len; i++) {
    int iv = 0;
    for(char* s = strs[i]; *s != '\0'; s++) iv += *s;
    int k = h(iv, len) % len;

    if (!nodes[k].offset) {
empty:
      printf("New bucket [%s][iv:%d] -> [key:%d]\n", strs[i], iv, k);
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
      printf("Appending [%s][iv: %d (%d) ] -> [key:%d]\n", strs[i],nodes[k].iv, iv, k);
      char** p = &values[nodes[k].row][(*rcz)[k]];
      *p += nodes[k].offset;  
      strcpy(*p, strs[i]);
      nodes[k].offset += lengths[i];
      (*rcz)[k]++;
      continue;
    }
    
    // for(k = (k + 1) % len; k < len ;k = (k + 1) % len) {
    //   if (nodes[k].iv == iv) {
    //     printf("[iv match]: ");
    //     goto iv_match;
    //   }
    //   if (!nodes[k].offset)  {
    //     printf("[probde key]: ");
    //     goto empty;
    //   }
    // }
    
    
  }
  



  return values;
}

int main() {
  int r = 0;
  char* x[] = {"eat","tea","tan","ate","nat","bat"};
  int len = sizeof(x) / sizeof(x[0]);
  int* csz = NULL;

  // int v = 0;
  // for(char* s = x[4]; *s != '\0'; s++) v+=*s;
  // printf("%d", h(v, len) % len);
  // exit(0); 

  printf("calling with %d strings\n", len);
  char*** answer = groupAnagrams(x, len, &r, &csz);
  for(int i = 0; i < len; i++) {
    if (*answer[i][0] == '\0') continue;
    printf("[");
    for(int j = 0; j < len; j++) {
      if (*answer[i][j] == '\0') break;
      printf("%s, ", answer[i][j]);
    }
    printf("]\n");
  }
  
  return 0;
}

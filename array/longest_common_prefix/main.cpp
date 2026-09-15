#include <cstdio>
#include <cstdlib>
#include <cstring>

char* longestCommonPrefix(char** strs, int strsSize) {
  char* answer = (char*)malloc(200);
  memset(answer, 0, 200);
  if (!strsSize)
    return answer;
  if (strsSize == 1) {
    int len = strlen(*strs);
    memcpy(answer, *strs, len);
    return answer;
  }

  bool end = false;
  for(int j = 0; j < strlen(*strs); j++) {
    for(int i = 0; i < strsSize - 1; i++){
      if (strs[i+1][j] == '\0') {
        end = true;
        break;
      }
      if (strs[i][j] != strs[i+1][j])
        break;

      
      if (i == strsSize - 2)
        answer[j] = strs[i][j];
    }
    if (end)
      return answer;
  }

  return answer;
}


int main() {
  const char* strs[] = {"flower","flow","flight"};
  int len = sizeof(strs) / sizeof(strs[0]);
  printf("%d strings\n", len);
  char* v = longestCommonPrefix((char**)strs,len);
  printf("%s", v);
  free(v);
  return 0;
}

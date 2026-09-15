#include <cstdio>
#include <cstring>
#include <memory_resource>


bool rotateString(char str[], char goal[]) {
  
  int goal_len = strlen(str);
  int input_len = strlen(goal);
  if (input_len != goal_len) return false;
  char double_str[100] = {"\0"};
  strcat(double_str, str);
  strcat(double_str, str);
  if (strstr(double_str, goal))
    return true;
  return false;
}

int main() {
  char input0[] = "barfoo";
  //               barfoobarfoo
  char goal[]   = "foobar";
  if (rotateString(input0, goal)) {
    printf("True");
  } else printf("False");
  return 0;
}

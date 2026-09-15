#include <cctype>
#include <cstdio>
#include <cstring>

bool isPalindrome(char* s) {
  char* left = s;
  char* right = s + strlen(s) - 1;
  
  while (left < right) {
    if (!isalnum(*left)) {
      left++;
      continue;
    }

    if (!isalnum(*right)) {
      right--;
      continue;
    }

    printf("%c | %c\n", *left, *right);
    if (tolower(*left) != tolower(*right))
      return false;

    
    left++; right--;
    
  }
  return true;
}


int main() {
  char s[] = "race a car";
  if (isPalindrome(s))
    printf("%s", "true");
  else
    printf("%s", "false");

  return 0;
}

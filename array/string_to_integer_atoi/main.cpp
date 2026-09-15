#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>

int myAtoi(char* s) {
  int answer = 0;
  int len = strlen(s);
  int si = 0;
  bool negative = false;
  for(int i = 0; i < len; i++, si++) { // find start of int
    if (s[i] == ' ') continue;
    if (s[i] == '-') {
      if (s[i+1] < 0x30 || s[i+1] > 0x39)
        return 0;
      negative = true;
      continue;
    }
    if (s[i] == '+') {
      if (s[i+1] < 0x30 || s[i+1] > 0x39)
        return 0;
      continue;
    }
    if (s[i] == 0) {
      if (s[i+1] - '0' > 9)
          break;
      continue;
    }
    
    if (isalpha(s[i]) || s[i] == '.') return 0;
    break;
  }

  for(int i = si; i < len; i++) { // read ints
    if (s[i] < 0x30 || s[i] > 0x39)
      break;
    int base = answer;
    int digit = s[i] - '0';
    for(int j = 0; j < 9; j++) { // multiply places
      if (base > INT32_MAX - answer) {
        if (negative)
          return INT32_MIN;
        return INT32_MAX;
      }
      answer += base;
    }
    if (digit && digit > INT32_MAX - answer) {
      if (negative)
        return INT32_MIN;
      return INT32_MAX;
    }
    answer += digit;
   }

  if (negative)
    answer *= -1;
  return (int)answer;
}

int main() {
  char s[] = "-2147483648";
  printf("%d", myAtoi(s));
  return 0;
}

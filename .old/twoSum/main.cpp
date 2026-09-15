#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>

int* twoSum(int* nums, int num_length,  int target) {
  int visited[] = {}; 
  for(int i = 0; i < num_length; i++) {
    for (int j = i + 1; j < num_length; j++) {
      int sum = nums[i] + nums[j];
      if (sum == target) {
        int* result = (int*) malloc(2 * sizeof(int));
        result[0] = i;
        result[1] = j;
        return result;
      }     
    } 
  }
  
  return NULL;
}


int main() {
  int n[] = {2, 7, 11, 15};
  int len = sizeof(n) / sizeof(n[0]); 
  int* result = twoSum(n, len, 9);
  std::cout << "Input: ";
  for(int i = 0; i < len; i++) {
    std::cout << n[i] << ", ";
  }
  std::cout << std::endl; 
  std::cout << "[" << result[0] << "," << result[1] << "]" << std::endl;
  return 0;
}

#include <cstdio>

// RULED OUT:
// - converging pointers
// - two pointers



int maxProfit(int* prices, int priceSize) {
  int buy = prices[0];
  int profit = 0; 
  if (!priceSize)
    return 0;
  

  for(int i = 0; i < priceSize; i++) {
    if (prices[i] < buy)
      buy = prices[i];
    else if (prices[i] - buy > profit)
      profit = prices[i] - buy;
  }
    
  return profit;

}

    

int main() {
  int x[] = {2,1,2,0,1};
  int len = sizeof(x) / sizeof(x[0]); 
  printf("Profit: %d", maxProfit(x,  len));
  return 0;
}




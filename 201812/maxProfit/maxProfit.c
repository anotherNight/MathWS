#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {

  if (pricesSize == 0 || pricesSize == 1) {
    return 0;
  }

  int tem = prices[0];
  int sum = 0;
  int isBottom = prices[1] > prices[0];

  for (int i = 1; i < pricesSize; i++) {
    if (isBottom == 1) {
      if (i == pricesSize-1 || prices[i] > prices[i+1]) {
        sum = sum + prices[i]-tem;
        isBottom = 0;
        printf("is max at index %d\n", i);
      }
    }else {
      if (i != pricesSize-1 && prices[i] < prices[i+1]) {
        tem = prices[i];
        isBottom = 1;
        printf("is bottom at index %d\n", i);
      }
    }
  }
  return sum;
}

int main(){

  // printf("111\n", );
  // int a[7] = {3,5,1,4,11,3,19};
  int a[6] = {7,1,5,3,6,4};
  int total = maxProfit(a,7);
  printf("max profit:%d\n", total);
  return 0;
}

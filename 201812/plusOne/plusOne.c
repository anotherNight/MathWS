/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carryOver = 1;
  for (int i = digitsSize-1; i >=0; i--) {
    int value = digits[i];
    value  = value + carryOver;
    if (value > 9) {
      carryOver = 1;
      value = value % 10;
    }else {
      carryOver = 0;
    }
    digits[i] = value;
  }

  if (carryOver == 1) {
      *returnSize = digitsSize +1;
      int newArray[digitsSize+1];
      newArray[0] = 1;
      for (int i = 0; i < digitsSize; i++) {
        newArray[i+1] = digits[i];
      }
  }else {
      *returnSize = digitsSize;
      return digits;
  }
  return returnSize;
}

int main(){

  printf("test c main\n");
  int a[7] = {3,5,1,1,2,3,2};
  int size = 0;


  return 0;
}

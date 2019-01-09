#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    for(int i=1;i<numsSize;i++)
    {
        nums[0]=nums[0]^nums[i];
        printf("%d\n", nums[0]);
    }
    return nums[0];
}

int singleNumber(int* nums, int numsSize) {
  if (numsSize == 1) {
    return nums[0];
  }

  int index = 0;
  int m = 0;


  for (int i = 0; i < numsSize; i++) {
    if (i<=index) {
      continue;
    }
    printf("i:%d,index:%d\n", i,index);
    if (nums[index] == nums[i]) {
      int n = nums[index+1];
      nums[index+1] = nums[i];
      nums[i] = n;
      index = index+2;
      i = index;
    }

    if(i == numsSize -1) {
      m = nums[index];
      break;
    }
  }

  return m;
}

int main(){
  printf("test c main\n");
  // int a[7] = {1,1,3,3,5,5,6};
  int a[7] = {3,5,1,1,2,3,2};


  printf("singleNumber:%d\n", singleNumber(a,7));

  return 0;
}

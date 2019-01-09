#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool containsDuplicate(int* nums, int numsSize) {
  if (numsSize == 1) {
    return false;
  }

for (int index = 0; index < numsSize; index++) {
  for (int i = index+1; i < numsSize; i++) {
    printf("i:%d,index:%d\n", i,index);
    if (nums[index] == nums[i]) {
      return true;
    }
  }
}
  return false;
}

int main(){
  printf("test c main\n");
  int a[7] = {3,5,1,6,2,9,4};

bool result = containsDuplicate(a,7);
if (result) {
  printf("containsDuplicate yes\n");
}else {
  printf("containsDuplicate no\n");
}

  return 0;
}

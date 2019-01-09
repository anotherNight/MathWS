#include <stdio.h>

int indexZero(int* nums, int numsSize,int fromIndex){
  int index = -1;
  for (int i = fromIndex; i < numsSize; i++) {
    if (nums[i] == 0) {
      index = i;
      break;
    }
  }
  return index;
}

int indexNoZero(int* nums, int numsSize,int fromIndex){
  int index = -1;
  for (int i = fromIndex; i < numsSize; i++) {
    if (nums[i] != 0) {
      index = i;
      break;
    }
  }
  return index;
}

void moveZeroes(int* nums, int numsSize) {
  if (numsSize == 1) {
    return;
  }

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) {
      int index = i;
      int nextValueIndex = indexNoZero(nums,numsSize,index);
      int nextZeroIndex = indexZero(nums,numsSize,nextValueIndex);

      if (nextValueIndex == -1) {
        break;
      }
      if (nextZeroIndex == -1) {
        nextZeroIndex = numsSize;
      }

      int moveSize = nextValueIndex - index;
      for (int m = i; m < nextZeroIndex; m++) {
        if (m+moveSize>=nextZeroIndex) {
          nums[m] = 0;
        }else {
          nums[m] = nums[m+moveSize];
        }
      }
      i = nextZeroIndex - moveSize-1;
    }
  }
}


// void moveZeroes(int* nums, int numsSize) {
//     int i,len=0;
//     for(i=0;i<numsSize;i++){
//         if(nums[i]!=0){
//             nums[len]=nums[i];
//             len++;
//         }
//     }
//     for(i=len;i<numsSize;i++)
//         nums[i]=0;
// }

int main(){
  int a[6] = {1,0,3,0,5,6};
  moveZeroes(a,6);
  for (size_t i = 0; i < 6; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}

#include <stdio.h>

void jd_remove(int *dat, int len, int idx){
  len--;
  if(idx <0 || idx >= len){
    return;
  }
  for (int i = idx; i< len;i++){
    dat[i] = dat[i+1];
  }
}

void output (int *dat,int len){
  for (int i = 0; i< len; i++){
    printf("%d\n", dat[i]);
  }
  printf("\n");
}

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1){
        return numsSize;
    }
    int number = nums[numsSize-1];
    int length = numsSize;
    for (int i = numsSize-2; i >=0; i--){
        if(number == nums[i]){
            for (int n = i; n < numsSize-1;n++){
                nums[n] = nums[n+1];
            }
            length--;
        }else{
            number = nums[i];
        }
    }
    return length;
}

int main(){
  int a[10] = {0,1,2,2,4,4,6,7,8,9},len = 10;
  // jd_remove(a,len,5);
  int num = removeDuplicates(a,10);
  printf("%d\n", num);
  output(a,len-2);
  return 0;
}

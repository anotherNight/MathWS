#include <stdio.h>

void rotate(int* nums, int numsSize, int k) { 
  while(k>=numsSize) {
    k=k-numsSize;
  }
  if(k!=0) {
    int a[k];
    int i;
    i=numsSize-k;
    while(i<=numsSize-1) {
      a[i+k-numsSize]=nums[i];
      i=i+1;
    }
    i=numsSize-k-1;
    while(i>=0) {
      nums[i+k]=nums[i];
      i=i-1;
    }
    i=0;
    while(i<k) {
      nums[i]=a[i];
       i=i+1;
     }
   }
 }



  // for (int i = 0; i < k; i++) {
  //   m = nums[numsSize-1];
  //   for (size_t n = numsSize-1; n > 0; n--){
  //     nums[n] = nums[n-1];
  //   }
  //   nums[0] = m;
  // }


int main(){
printf("test c main\n");

int a[6] = {1,2,3,4,5,6};
rotate(a,6,2);

for (size_t i = 0; i < 5; i++) {
  /* code */
  printf("%d\n", a[i]);
}
return 0;
}

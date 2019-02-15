#include <stdio.h>
#include <stdlib.h>

int *twoSum(int* nums, int numsSize,int target){

	int *array = (int*)malloc(2*sizeof(int));

	for (int i = 0; i < numsSize-1; i++) {
		for (int j = 1; j < numsSize; j++) {
			if (nums[i]+nums[j] == target) {
				array[0] = i;
				array[1] = j;
			}
		}
	}
	return array;
}

int *twoSumHash(int* nums, int numsSize,int target){

	int *array = (int*)malloc(2*sizeof(int));

	printf("%d--%d\n",first,seconds );
	return array;
}

int main(){
	int s[] = {1,2,3,4,5,6,7,8};
	twoSum(s,8,8);
	return 0;
}

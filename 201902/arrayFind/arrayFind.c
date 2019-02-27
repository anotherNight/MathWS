#include <stdio.h>

typedef int bool;

#define true 1
#define false 0

bool Find (int *matrix, int rows, int columns,int number) {
  bool found = false;
  if (matrix != NULL && rows >0 && columns >0) {
    int row = 0;
    int column = columns-1;
    while (row < rows && column>0) {
      if (matrix[row*columns+column] == number) {
        found = true;
        printf("row:%d,column:%d\n", row,column);
        break;
      }else if(matrix[row*columns+column]>number){
        column--;
      }else {
        row++;
      }
    }
  }

  return found;
}

int main(){
  int a[] = {
    1,2,8,9,
    2,4,9,12,
    4,7,10,13,
    6,8,11,15};
  bool b = Find(a,4,4,7);
  printf("%d\n", b);
	return 0;
}

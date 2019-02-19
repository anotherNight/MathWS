#include <stdio.h>
#include <limits.h>

int myAtoi(char* str) {

  if (*str == '\0') {
    return 0;
  }

  long long llnum = 0;

  int sign = 1;

  while (*str != '\0' && (*str == ' ') ) {
    printf("%c\n", *str);
    str++;
  }

  if (*str == '-') {
    sign = -1;
    str++;
  }else if(*str == '+'){
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    int i = *str - '0';
    llnum = llnum*10+i;
    if (llnum*sign > INT_MAX) {
      llnum = INT_MAX;
      break;
    }else if(llnum*sign < INT_MIN){
      llnum = INT_MIN;
      break;
    }
    str++;
  }

  return (int)(sign*llnum);
}

int main(){
  char* a = "asb   987";
  int result = myAtoi(a);
  printf("%d\n", result);
	return 0;
}

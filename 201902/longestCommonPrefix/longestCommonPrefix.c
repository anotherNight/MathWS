#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  char* str=strs[0];
  int i,j;
  if(strsSize==0) return "";

  for(i=1;i<strsSize;i++){
      j=0;
      while(str[j] && strs[i][j] && str[j]==strs[i][j])j++;
      str[j]='\0';
  }
  return str;
}

int main(){
  char* a[] = {"aaa321","aa33"};
  char* result = longestCommonPrefix(a,2);
  printf("%s\n", result);
	return 0;
}

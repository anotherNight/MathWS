#include <stdio.h>

void reverseString(char* s, int sSize) {
  if (sSize < 2){
    return;
  }
  char sample = ' ';
  for (int i = 0; i < sSize; i++) {
    int j = sSize-1-i;
    if (j<=i) {
      break;
    }
    sample = s[i];
    s[i] = s[j];
    s[j] = sample;
  }
}

int main(){
  char c[] = {'h','e','l','l','o'};
	reverseString(c,5);
  for (int i = 0; i < 5; i++) {
    printf("--%c--\n", c[i]);
  }
	return 0;
}

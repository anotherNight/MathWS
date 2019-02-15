#include <stdio.h>
#include <string.h>

// int firstUniqChar(char* s) {
//   int len = strlen(s);
//   if (len == 1) {
//     return 0;
//   }
//   if (len == 0) {
//     return -1;
//   }
//
//   int k = 0;
//
//   for (int i = 0; i < len; i++) {
//     k = 0;
//     for (int j = 0; j < len; j++) {
//       if (s[i] == s[j] && i!=j) {
//         k = 1;
//         break;
//       }
//     }
//     if (k == 0) {
//       return i;
//     }
//   }
//   return -1;
// }

int firstUniqChar(char* s) {
    int d[26]={0};

    int i=0;
    int t;
    for(i=0;s[i]!='\0';i++)
    {
        t=s[i]-'a';
        d[t]++;
    }

    for (int k = 0; k < 26; k++) {
      printf("%d--\n", d[k]);
    }
    for(i=0;s[i]!='\0';i++)
    {
        t=s[i]-'a';
        if(d[t]==1)
            return i;
    }
    return -1;
}

int main(){
  char a[] = "teetcode";
  int b = firstUniqChar(a);
  printf("%d\n", b);
	return 0;
}

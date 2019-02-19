#include <stdio.h>
#include <limits.h>

int strStr(char* haystack, char* needle) {
  if (*haystack == '\0' && *needle != '\0') {
    return -1;
  }
  if (*needle == '\0') {
    return 0;
  }

  int index = 0;

  while (haystack[index] != '\0') {
    if (haystack[index] == *needle) {
      //first index
      char* temp = needle;
      int tempIndex = index;
      while (haystack[tempIndex] == *temp) {
        tempIndex++;
        temp++;
        if (*temp == '\0') {
          return index;
        }
      }
      index++;
    }else {
      index++;
    }
  }

  return -1;
}


// int strStr(char* haystack, char* needle) {
//     int len1 = strlen(haystack);
//     int len2 = strlen(needle);
//     int i,j,cnt = 0;
//
//     if (len2 == 0) return 0;
//
//     for (i = 0; i < len1 - len2 + 1; i++) {
//         cnt = 0;
//         for (j = 0; j < len2; j++) {
//             if (haystack[i+j] == needle[j]) {
//                 cnt ++;
//             }
//             if (cnt == len2) return i;
//         }
//     }
//
//     return -1;
// }

int main(){
  char* a = "asb   98797";
  char* b = "98";
  char* c = "97";
  char* d = "9";
  char* e = "9877";
  char* f = "";
  int result = strStr(a,b);
  printf("%d\n", result);
  printf("%d\n", strStr(a,c));
  printf("%d\n", strStr(a,d));
  printf("%d\n", strStr(a,e));
  printf("%d\n", strStr(a,f));
	return 0;
}

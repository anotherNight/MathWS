#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int * s_buffer;
    int * t_buffer;
    int s_len;
    int t_len;

    /* 分配空间 */
    s_buffer = (int *)malloc(sizeof(int) * 256);
    t_buffer = (int *)malloc(sizeof(int) * 256);
    //初始化空间内容
    //memset() 的作用是在一段内存块中填充某个给定的值。
    memset(s_buffer, 0, sizeof(int) * 256);
    memset(t_buffer, 0, sizeof(int) * 256);

    /* 两个字符串大小不一致，返回false */
    s_len = strlen(s);
    t_len = strlen(t);
    if(s_len != t_len)
        return false;

    /* 计算字符串1中各个字符的数目 */
    for(int i = 0; i < s_len; i++)
    {
        s_buffer[s[i]]++;
    }
    /* 计算字符串2中各个字符的数目 */
    for(int i = 0; i < t_len; i++)
    {
        t_buffer[t[i]]++;
    }
    /* 判断两个字符串中字符是否一致 */
    for(int i = 0; i < 256; i++)
    {
        if((s_buffer[i] != t_buffer[i]))
            return false;
    }
    return true;
}


// int firstUniqChar(char* s) {
//     int d[26]={0};
//
//     int i=0;
//     int t;
//     for(i=0;s[i]!='\0';i++)
//     {
//         t=s[i]-'a';
//         d[t]++;
//     }
//     for(i=0;s[i]!='\0';i++)
//     {
//         t=s[i]-'a';
//         if(d[t]==1)
//             return i;
//     }
//     return -1;
// }

int main(){
  char a[] = "";
  char b[] = "";
  bool result = isAnagram(a,b);
  printf("%d\n", result);
	return 0;
}

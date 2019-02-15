#include <stdio.h>
#include <math.h>

int reverse(int x) {
    long long y=0;
    int max = pow(2,31)-1;
    int min = pow(-2,31);
    while(x)
    {
        int temp=y;
        y= y*10+x%10;
        if( y > max || y<min)
        {
            return 0;
        }
        x/=10;
    }
    return y;
}

int main(){
  int a = -1534236469;
  int b = reverse(a);
  printf("%d\n", b);
	return 0;
}

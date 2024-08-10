#include<stdio.h>

int fact(int n)
{
    int result = 1;
    while(n)
    {
       result =  result * n;
       n--;
    }
}
int main()
{
    int k = 5;
    printf("factorial(%d) = %d\n", k, fact(k));
    return 0;
}

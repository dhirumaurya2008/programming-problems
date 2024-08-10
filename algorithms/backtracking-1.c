#include<stdio.h>

void printBinary(int digits, char* prefix, int prefixlen)
{
    if(digits ==0)
        printf("%s\n", prefix);
    else{
        printBinary(digits-1, strcat(prefix,"0"), prefixlen+1);
        prefix[prefixlen]=0;
        printBinary(digits-1, strcat(prefix,"1"), prefixlen+1);
        prefix[prefixlen]=0;
    }
}

int main()
{
    char prefix[4]={0};
int prefixlen=0;
    printBinary(3, prefix, prefixlen);
    return 0;
}

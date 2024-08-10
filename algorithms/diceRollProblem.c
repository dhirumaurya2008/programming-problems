/*
Algorithm:print output of dices when the rolled over parrelly.
*/

#include<stdio.h>

void printDiceRoll(int dice, int *arr, int arr_size)
{
    if(dice == 0)
    {
        for(int i=0; i<arr_size; i++)
        {
            printf("%d \t", arr[i]);
        }
        printf("\n");
    }
    else
    {
       for(int i =1;i<=6; i++)
       {
           arr[arr_size++] = i;
           printDiceRoll(dice-1, arr, arr_size);
           arr_size = arr_size -1;
       }
    }
}
int main()
{
    int arr[3];
    int arr_size=0;
    printDiceRoll(3, arr, arr_size);

    return 0;
}

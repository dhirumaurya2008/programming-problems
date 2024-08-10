#include<iostream>
#include<queue>

using namespace std;


int firstNegativeElement (int arr[], int n, int k)
{
 unsigned short index = 0;
 queue<int> fifo;
 while (index < k)
 {
     if (arr[index] < 0)
     {
         fifo.push(arr[index]);
     }
     index++;
 }

 for (; index < n; index++)
 {
     if (!fifo.empty())
        cout << fifo.front() << " ";
     else
        cout << 0 << " ";
     if (arr[index-k] < 0)
        fifo.pop();
     if (arr[index] < 0)
        fifo.push(arr[index]);
 }

 if (!fifo.empty())
        cout << fifo.front() << " ";
     else
        cout << 0 << " ";

 while (!fifo.empty())
    fifo.pop();
}

int main()
{

    int a[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(a)/sizeof(a[0]);
    firstNegativeElement (a, n, 3);
    return 0;
}

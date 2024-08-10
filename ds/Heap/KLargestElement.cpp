#include<iostream>
#include<queue>

using namespace std;


void FirstKLargestelements(int arr[], unsigned int arr_size, unsigned int k)
{
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<arr_size; i++)
    {
       que.push(arr[i]);
       if(que.size() > k)
        que.pop();
    }

    while (!que.empty())
    {
        cout << que.top() << " " << endl;
        que.pop();
    }
}

int main()
{

    int arr[] = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Size of Min Heap
    int k = 3;

    FirstKLargestelements(arr,size,k);

    return 0;
}

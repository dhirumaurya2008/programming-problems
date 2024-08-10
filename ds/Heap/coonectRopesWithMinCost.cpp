#include<iostream>
#include<queue>
using namespace std;

int minCost(int arr[], int arr_size)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=0; i<arr_size; i++) {
        pq.push(arr[i]);
    }
    unsigned int cost = 0;
    while(pq.size() >= 2) {
        int first = pq.top();

        pq.pop();
        int second = pq.top();

        pq.pop();

        cost += (first + second);
        cout << "First " << first<< " Second " << second << " Cost " << cost<<  endl;
        pq.push(first+second);
    }

    cout << " Cost " << pq.top() << " Cost " << cost<<  endl;

    return cost;
}
// Driver program to test above function
int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
